from __future__ import annotations

import argparse
import re
import subprocess
import sys
from pathlib import Path
from typing import Sequence


ROOT = Path(__file__).resolve().parents[2]
SIM_SCRIPT = ROOT / "Test" / "Automation" / "simulate_instructions_hex.py"
RTL_SCRIPT = ROOT / "Test" / "Automation" / "simulate_rtl_trace.py"
SIM_LOG = ROOT / "Test" / "Automation" / "sim_register_trace.log"
SIM_PC_LOG = ROOT / "Test" / "Automation" / "sim_register_trace_pc.log"
RTL_LOG = ROOT / "Test" / "Automation" / "rtl_register_trace.log"
REGISTER_RE = re.compile(r"x(\d{2})=([0-9a-fA-F]{8})")


def run_python(script: Path, args: list[str]) -> None:
    command = [sys.executable, str(script), *args]
    subprocess.run(command, cwd=str(ROOT), check=True)


def parse_register_log(path: Path) -> list[list[int]]:
    lines = path.read_text(encoding="utf-8").splitlines()
    states: list[list[int]] = []

    index = 0
    while index < len(lines):
        if lines[index].strip() != "Register File":
            index += 1
            continue

        block_lines = lines[index + 1 : index + 9]
        if len(block_lines) != 8:
            raise ValueError(f"{path}: incomplete register block near line {index + 1}")

        registers = [0] * 32
        seen = set()
        for line in block_lines:
            for register_name, value in REGISTER_RE.findall(line):
                register_index = int(register_name)
                registers[register_index] = int(value, 16)
                seen.add(register_index)

        if len(seen) != 32:
            raise ValueError(f"{path}: failed to parse all 32 registers near line {index + 1}")

        states.append(registers)
        index += 9

    if not states:
        raise ValueError(f"{path}: no register states found")

    return states


def parse_pc_log(path: Path) -> dict[int, int]:
    mapping: dict[int, int] = {}
    for raw_line in path.read_text(encoding="utf-8").splitlines():
        text = raw_line.strip()
        if not text:
            continue
        parts = text.split()
        if len(parts) != 2:
            raise ValueError(f"{path}: malformed PC log entry '{text}'")
        mapping[int(parts[0])] = int(parts[1], 16)
    return mapping


def summarize_delta(previous: Sequence[int], current: Sequence[int]) -> str:
    deltas: list[str] = []
    for reg_index, (old_value, new_value) in enumerate(zip(previous, current)):
        if old_value != new_value:
            deltas.append(f"x{reg_index:02d}={new_value:08x}")
    return ", ".join(deltas[:8]) if deltas else "no delta"


def describe_difference(sim_state: Sequence[int], rtl_state: Sequence[int]) -> str:
    diffs: list[str] = []
    for reg_index, (sim_value, rtl_value) in enumerate(zip(sim_state, rtl_state)):
        if sim_value != rtl_value:
            diffs.append(f"x{reg_index:02d}=sim:{sim_value:08x} rtl:{rtl_value:08x}")
    return ", ".join(diffs[:8]) if diffs else "no visible difference"


def compare_state_sequences(
    sim_states: list[list[int]],
    rtl_states: list[list[int]],
    lookahead: int,
    sim_pc_map: dict[int, int],
) -> tuple[bool, str]:
    sim_index = 0
    rtl_index = 0

    while sim_index < len(sim_states) and rtl_index < len(rtl_states):
        sim_state = sim_states[sim_index]
        rtl_state = rtl_states[rtl_index]

        if sim_state == rtl_state:
            sim_index += 1
            rtl_index += 1
            continue

        sim_match = None
        for offset in range(1, lookahead + 1):
            if sim_index + offset < len(sim_states) and sim_states[sim_index + offset] == rtl_state:
                sim_match = sim_index + offset
                break

        rtl_match = None
        for offset in range(1, lookahead + 1):
            if rtl_index + offset < len(rtl_states) and rtl_states[rtl_index + offset] == sim_state:
                rtl_match = rtl_index + offset
                break

        if sim_match is not None and (rtl_match is None or sim_match - sim_index <= rtl_match - rtl_index):
            sim_index = sim_match
            continue

        if rtl_match is not None:
            rtl_index = rtl_match
            continue

        previous_sim = sim_states[sim_index - 1] if sim_index > 0 else [0] * 32
        previous_rtl = rtl_states[rtl_index - 1] if rtl_index > 0 else [0] * 32
        sim_pc = sim_pc_map.get(sim_index, sim_pc_map.get(sim_index - 1, 0))
        message = (
            f"Divergence at sim state #{sim_index} and rtl state #{rtl_index}\n"
            f"Simulator PC: 0x{sim_pc:08x}\n"
            f"Sim delta: {summarize_delta(previous_sim, sim_state)}\n"
            f"RTL delta: {summarize_delta(previous_rtl, rtl_state)}\n"
            f"Difference: {describe_difference(sim_state, rtl_state)}"
        )
        return False, message

    if sim_index != len(sim_states) or rtl_index != len(rtl_states):
        return (
            False,
            f"Trace lengths did not reconcile: sim_remaining={len(sim_states) - sim_index}, rtl_remaining={len(rtl_states) - rtl_index}",
        )

    return True, f"Matched {len(sim_states)} simulator states against {len(rtl_states)} RTL states"


def main() -> int:
    parser = argparse.ArgumentParser(
        description="Run simulator and RTL trace scripts, then compare their register-state logs."
    )
    parser.add_argument(
        "--hex-path",
        type=Path,
        default=ROOT / "Core" / "Memory" / "Instructions.hex",
        help="Program hex for the standalone simulator.",
    )
    parser.add_argument(
        "--sim-log-path",
        type=Path,
        default=SIM_LOG,
        help="Where to write/read the software simulator trace log.",
    )
    parser.add_argument(
        "--sim-pc-log-path",
        type=Path,
        default=SIM_PC_LOG,
        help="Where to write/read the software simulator PC sidecar log.",
    )
    parser.add_argument(
        "--rtl-log-path",
        type=Path,
        default=RTL_LOG,
        help="Where to write/read the RTL trace log.",
    )
    parser.add_argument(
        "--rtl-exe",
        default="./Verilator/VTop",
        help="WSL command for the stepped RTL executable.",
    )
    parser.add_argument(
        "--max-steps",
        type=int,
        default=50000,
        help="Maximum instruction steps for the software simulator.",
    )
    parser.add_argument(
        "--max-cycles",
        type=int,
        default=50000,
        help="Maximum RTL cycles for the hardware trace.",
    )
    parser.add_argument(
        "--lookahead",
        type=int,
        default=3,
        help="Allowed state-skew window when reconciling dual-retire timing differences.",
    )
    parser.add_argument(
        "--startup-timeout",
        type=float,
        default=5.0,
        help="RTL harness startup timeout in seconds.",
    )
    parser.add_argument(
        "--command-timeout",
        type=float,
        default=2.0,
        help="RTL harness per-command timeout in seconds.",
    )
    args = parser.parse_args()

    hex_path = args.hex_path.resolve()
    sim_log_path = args.sim_log_path.resolve()
    sim_pc_log_path = args.sim_pc_log_path.resolve()
    rtl_log_path = args.rtl_log_path.resolve()

    run_python(
        SIM_SCRIPT,
        [
            "--hex-path",
            str(hex_path),
            "--log-path",
            str(sim_log_path),
            "--pc-log-path",
            str(sim_pc_log_path),
            "--max-steps",
            str(args.max_steps),
        ],
    )

    run_python(
        RTL_SCRIPT,
        [
            "--exe",
            args.rtl_exe,
            "--log-path",
            str(rtl_log_path),
            "--max-cycles",
            str(args.max_cycles),
            "--startup-timeout",
            str(args.startup_timeout),
            "--command-timeout",
            str(args.command_timeout),
        ],
    )

    sim_states = parse_register_log(sim_log_path)
    sim_pc_map = parse_pc_log(sim_pc_log_path)
    rtl_states = parse_register_log(rtl_log_path)

    matched, message = compare_state_sequences(
        sim_states, rtl_states, args.lookahead, sim_pc_map
    )
    if matched:
        print(f"MATCH\n{message}")
        return 0

    print(f"DIVERGENCE\n{message}")
    return 1


if __name__ == "__main__":
    raise SystemExit(main())
