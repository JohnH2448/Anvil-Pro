from __future__ import annotations

import argparse
import queue
import re
import subprocess
import threading
from pathlib import Path
from typing import Sequence


ROOT = Path(__file__).resolve().parents[2]
DEFAULT_LOG_PATH = ROOT / "Test" / "Automation" / "rtl_register_trace.log"
REGISTER_RE = re.compile(r"x(\d{2})=([0-9a-fA-F]{8})")
STEP_RE = re.compile(r"__STEP_DONE__\s+(\d+)\s+([0-9a-fA-F]{8})")
TOHOST_VALUES = {0x101, 0x102}


def to_wsl_path(path: Path) -> str:
    resolved = path.resolve()
    drive = resolved.drive.rstrip(":").lower()
    parts = resolved.parts[1:]
    return "/mnt/" + drive + "/" + "/".join(parts)


def format_register_block(registers: Sequence[int]) -> str:
    lines = ["Register File"]
    for base in range(0, 32, 4):
        row = "  ".join(
            f"x{index:02d}={int(registers[index]) & 0xFFFFFFFF:08x}"
            for index in range(base, base + 4)
        )
        lines.append(row)
    return "\n".join(lines) + "\n"


def parse_last_register_block(lines: Sequence[str]) -> list[int]:
    last_header_index = None
    for index, line in enumerate(lines):
        if line.strip() == "Register File":
            last_header_index = index

    if last_header_index is None:
        raise RuntimeError("no register file block found in RTL output")

    block_lines = list(lines[last_header_index + 1 : last_header_index + 9])
    if len(block_lines) != 8:
        raise RuntimeError("incomplete register file block in RTL output")

    registers = [0] * 32
    seen = set()
    for line in block_lines:
        for register_name, value in REGISTER_RE.findall(line):
            register_index = int(register_name)
            registers[register_index] = int(value, 16)
            seen.add(register_index)

    if len(seen) != 32:
        raise RuntimeError("failed to parse all 32 registers from RTL output")

    return registers


class HardwareStepper:
    def __init__(self, executable: str, startup_timeout: float, command_timeout: float):
        wsl_command = f"cd '{to_wsl_path(ROOT)}' && {executable}"
        self.command_timeout = command_timeout
        self.process = subprocess.Popen(
            ["wsl", "bash", "-lc", wsl_command],
            stdin=subprocess.PIPE,
            stdout=subprocess.PIPE,
            stderr=subprocess.STDOUT,
            text=True,
            bufsize=1,
        )
        self._line_queue: queue.Queue[str | None] = queue.Queue()
        self._recent_lines: list[str] = []
        self._reader = threading.Thread(target=self._reader_loop, daemon=True)
        self._reader.start()
        self._collect_until("__READY__", startup_timeout)

    def _reader_loop(self) -> None:
        if self.process.stdout is None:
            self._line_queue.put(None)
            return
        for line in self.process.stdout:
            stripped = line.rstrip("\r\n")
            self._line_queue.put(stripped)
        self._line_queue.put(None)

    def close(self) -> None:
        if self.process.poll() is None and self.process.stdin:
            try:
                self.process.stdin.write("quit\n")
                self.process.stdin.flush()
            except OSError:
                pass
        if self.process.poll() is None:
            self.process.terminate()

    def _send(self, command: str) -> None:
        if self.process.stdin is None:
            raise RuntimeError("hardware process stdin is unavailable")
        self.process.stdin.write(command + "\n")
        self.process.stdin.flush()

    def _collect_until(self, prefix: str, timeout: float) -> list[str]:
        lines: list[str] = []
        while True:
            try:
                item = self._line_queue.get(timeout=timeout)
            except queue.Empty as exc:
                recent = "\n".join(self._recent_lines[-8:])
                raise RuntimeError(
                    f"Timed out waiting for {prefix}. "
                    "This usually means ./Verilator/VTop was not rebuilt with TraceStepHarness.cpp "
                    f"or WSL failed to launch it.\nRecent output:\n{recent}"
                ) from exc

            if item is None:
                recent = "\n".join(self._recent_lines[-8:])
                raise RuntimeError(
                    "hardware process exited unexpectedly.\n"
                    f"Recent output:\n{recent}"
                )

            stripped = item
            lines.append(stripped)
            self._recent_lines.append(stripped)
            if len(self._recent_lines) > 32:
                self._recent_lines = self._recent_lines[-32:]
            if stripped.startswith(prefix):
                return lines

    def reset(self) -> None:
        self._send("reset")
        self._collect_until("__RESET_DONE__", self.command_timeout)

    def step(self) -> tuple[int, int, list[int]]:
        self._send("step")
        lines = self._collect_until("__STEP_DONE__", self.command_timeout)
        marker = lines[-1]
        step_match = STEP_RE.fullmatch(marker)
        if step_match is None:
            raise RuntimeError(f"bad step marker: {marker}")

        cycle = int(step_match.group(1))
        tohost = int(step_match.group(2), 16)
        registers = parse_last_register_block(lines)
        return cycle, tohost, registers


def main() -> int:
    parser = argparse.ArgumentParser(
        description="Step the RTL simulator and log register-file state changes."
    )
    parser.add_argument(
        "--exe",
        default="./Verilator/VTop",
        help="WSL command for the stepped Verilator executable.",
    )
    parser.add_argument(
        "--log-path",
        type=Path,
        default=DEFAULT_LOG_PATH,
        help="Output log file for register-file state changes.",
    )
    parser.add_argument(
        "--max-cycles",
        type=int,
        default=50000,
        help="Maximum cycles before aborting.",
    )
    parser.add_argument(
        "--startup-timeout",
        type=float,
        default=5.0,
        help="Seconds to wait for the RTL harness startup marker.",
    )
    parser.add_argument(
        "--command-timeout",
        type=float,
        default=2.0,
        help="Seconds to wait for each reset/step marker.",
    )
    args = parser.parse_args()

    log_path = args.log_path.resolve()
    blocks = [format_register_block([0] * 32)]
    last_logged = [0] * 32

    hardware = HardwareStepper(
        args.exe,
        startup_timeout=args.startup_timeout,
        command_timeout=args.command_timeout,
    )
    try:
        hardware.reset()

        for _ in range(args.max_cycles):
            cycle, tohost, registers = hardware.step()

            if registers != last_logged:
                blocks.append(format_register_block(registers))
                last_logged = registers

            if tohost in TOHOST_VALUES:
                log_path.write_text("\n".join(blocks), encoding="utf-8")
                print(f"Stopped with tohost=0x{tohost:08x} at cycle {cycle}")
                print(f"Wrote trace log to {log_path}")
                return 0

        log_path.write_text("\n".join(blocks), encoding="utf-8")
        raise SystemExit(
            f"tohost was not reached within {args.max_cycles} cycle(s); partial log written to {log_path}"
        )
    finally:
        hardware.close()


if __name__ == "__main__":
    raise SystemExit(main())
