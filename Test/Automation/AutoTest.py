from __future__ import annotations

import re
import subprocess
import sys
from pathlib import Path


ROOT = Path(__file__).resolve().parents[2]
HEX_DIR = ROOT / "Test" / "Hex"
INSTRUCTIONS_HEX = ROOT / "Core" / "Memory" / "Instructions.hex"
CONVERTER = ROOT / "Test" / "Automation" / "hex_to_four_word.py"
LOG_FILE = ROOT / "Test" / "Automation" / "hex_results.log"
SIM_TIMEOUT_SECONDS = 1

STOP_CYCLE_RE = re.compile(r"Stopped at cycle (\d+) with tohost = (0x[0-9a-fA-F]{8})")
INFINITE_LOOP_RE = re.compile(r"Infinite loop after (\d+) cycles")


def to_wsl_path(path: Path) -> str:
    resolved = path.resolve()
    drive = resolved.drive.rstrip(":").lower()
    parts = resolved.parts[1:]
    return "/mnt/" + drive + "/" + "/".join(parts)


def run_command(command: list[str], cwd: Path | None = None) -> subprocess.CompletedProcess[str]:
    return subprocess.run(
        command,
        cwd=str(cwd) if cwd else None,
        text=True,
        capture_output=True,
        check=True,
    )


def extract_last_nonempty_line(text: str) -> str:
    for line in reversed(text.splitlines()):
        stripped = line.strip()
        if stripped:
            return stripped
    return ""


def count_retired_instructions(text: str) -> int:
    return sum(1 for line in text.splitlines() if line.startswith("Retired "))


def parse_result(last_line: str) -> tuple[str, int | None]:
    stop_match = STOP_CYCLE_RE.fullmatch(last_line)
    if stop_match:
        tohost = stop_match.group(2).lower()
        if tohost == "0x00000101":
            return "PASS", int(stop_match.group(1))
        if tohost == "0x00000102":
            return "FAIL", int(stop_match.group(1))
        return tohost, int(stop_match.group(1))

    infinite_loop_match = INFINITE_LOOP_RE.fullmatch(last_line)
    if infinite_loop_match:
        return "infinite loop", int(infinite_loop_match.group(1))

    if not last_line:
        return "NO OUTPUT", None

    return f"UNPARSED ({last_line})", None


def format_ipc(retired: int, cycles: int | None) -> str:
    if not cycles:
        return "n/a"
    return f"{retired / cycles:.4f}"


def classify_failed_simulation(stdout: str, stderr: str) -> tuple[str, int | None]:
    combined = "\n".join(part for part in (stdout, stderr) if part)
    last_line = extract_last_nonempty_line(combined)

    status, cycles = parse_result(last_line)
    if status == "infinite loop":
        return status, cycles

    lowered = combined.lower()
    if "did not converge" in lowered:
        return "non-convergent sim", None
    if "aborting..." in lowered:
        return "aborted", None

    if not last_line:
        return "NO OUTPUT", None

    return f"UNPARSED ({last_line})", None


def run_single_test(hex_file: Path) -> str:
    INSTRUCTIONS_HEX.write_text(hex_file.read_text())

    run_command([sys.executable, str(CONVERTER), str(INSTRUCTIONS_HEX)], cwd=ROOT)

    wsl_command = f"cd '{to_wsl_path(ROOT)}' && ./Verilator/VTop"
    try:
        sim = subprocess.run(
            ["wsl", "bash", "-lc", wsl_command],
            cwd=str(ROOT),
            text=True,
            capture_output=True,
            check=False,
            timeout=SIM_TIMEOUT_SECONDS,
        )
        stdout = sim.stdout
        stderr = sim.stderr
    except subprocess.TimeoutExpired as exc:
        stdout = exc.stdout or ""
        stderr = exc.stderr or ""
        retired = count_retired_instructions(stdout)
        ipc = format_ipc(retired, None)
        return f"{hex_file.name}: TIMEOUT, IPC={ipc}"

    retired = count_retired_instructions(stdout)
    last_line = extract_last_nonempty_line(stdout)
    status, cycles = parse_result(last_line)
    ipc = format_ipc(retired, cycles)

    if sim.returncode != 0:
        failed_status, failed_cycles = classify_failed_simulation(stdout, stderr)
        return f"{hex_file.name}: {failed_status}, IPC={format_ipc(retired, failed_cycles)}"

    return f"{hex_file.name}: {status}, IPC={ipc}"


def main() -> int:
    hex_files = sorted(HEX_DIR.glob("*.hex"))
    if not hex_files:
        print(f"No hex files found in {HEX_DIR}", file=sys.stderr)
        return 1

    results: list[str] = []
    for hex_file in hex_files:
        try:
            result = run_single_test(hex_file)
        except subprocess.CalledProcessError as exc:
            details = extract_last_nonempty_line(exc.stderr) or extract_last_nonempty_line(exc.stdout)
            result = f"{hex_file.name}: ERROR ({details or 'command failed'})"
        results.append(result)
        print(result)

    LOG_FILE.write_text("\n".join(results) + "\n")
    print(f"Wrote summary log to {LOG_FILE}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
