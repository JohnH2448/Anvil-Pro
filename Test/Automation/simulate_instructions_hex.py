from __future__ import annotations

import argparse
from pathlib import Path
from typing import Sequence


ROOT = Path(__file__).resolve().parents[2]
DEFAULT_HEX_PATH = ROOT / "Core" / "Memory" / "Instructions.hex"
DEFAULT_LOG_PATH = ROOT / "Test" / "Automation" / "sim_register_trace.log"
DEFAULT_PC_LOG_PATH = ROOT / "Test" / "Automation" / "sim_register_trace_pc.log"
DEFAULT_MAX_STEPS = 50000
TOHOST_VALUES = {0x101, 0x102}


def sign_extend(value: int, bits: int) -> int:
    sign_bit = 1 << (bits - 1)
    mask = (1 << bits) - 1
    value &= mask
    return value - (1 << bits) if (value & sign_bit) else value


def u32(value: int) -> int:
    return value & 0xFFFFFFFF


def s32(value: int) -> int:
    value &= 0xFFFFFFFF
    return value if value < 0x80000000 else value - 0x100000000


def load_hex_words(path: Path) -> list[int]:
    words: list[int] = []
    for raw_line in path.read_text().splitlines():
        text = raw_line.strip()
        if not text:
            continue
        if len(text) == 8:
            words.append(int(text, 16))
            continue
        if len(text) == 32:
            packed_words = [text[index : index + 8] for index in range(0, 32, 8)]
            for word in reversed(packed_words):
                words.append(int(word, 16))
            continue
        raise ValueError(f"{path}: unsupported hex line width {len(text)}")
    return words


class NativeSimulator:
    def __init__(self, hex_path: Path, dmem_bytes: int = 4096):
        self.hex_path = Path(hex_path)
        self.dmem_bytes = dmem_bytes
        self.imem: list[int] = []
        self.regs: list[int] = []
        self.pc = 0
        self.step_count = 0
        self.dmem = bytearray()
        self.reset()

    def reset(self) -> None:
        self.imem = load_hex_words(self.hex_path)
        self.regs = [0] * 32
        self.pc = 0
        self.step_count = 0
        self.dmem = bytearray(self.dmem_bytes)

    def get_registers(self) -> Sequence[int]:
        return list(self.regs)

    def step(self) -> None:
        instruction = self._fetch()
        self._execute(instruction)
        self.regs[0] = 0
        self.step_count += 1

    def _fetch(self) -> int:
        index = self.pc // 4
        if self.pc % 4 != 0 or index < 0 or index >= len(self.imem):
            raise RuntimeError(f"Instruction fetch out of range at pc=0x{self.pc:08x}")
        return self.imem[index]

    def _write_reg(self, rd: int, value: int) -> None:
        if rd != 0:
            self.regs[rd] = u32(value)

    def _dmem_index(self, addr: int) -> int:
        return addr % self.dmem_bytes

    def _load_byte(self, addr: int) -> int:
        return self.dmem[self._dmem_index(addr)]

    def _store_byte(self, addr: int, value: int) -> None:
        self.dmem[self._dmem_index(addr)] = value & 0xFF

    def _load_le(self, addr: int, size: int, signed: bool) -> int:
        value = 0
        for offset in range(size):
            value |= self._load_byte(addr + offset) << (8 * offset)
        return u32(sign_extend(value, size * 8)) if signed else u32(value)

    def _store_le(self, addr: int, size: int, value: int) -> None:
        for offset in range(size):
            self._store_byte(addr + offset, value >> (8 * offset))

    def _execute(self, instruction: int) -> None:
        opcode = instruction & 0x7F
        rd = (instruction >> 7) & 0x1F
        funct3 = (instruction >> 12) & 0x7
        rs1 = (instruction >> 15) & 0x1F
        rs2 = (instruction >> 20) & 0x1F
        funct7 = (instruction >> 25) & 0x7F

        rs1_u = self.regs[rs1]
        rs2_u = self.regs[rs2]
        rs1_s = s32(rs1_u)
        rs2_s = s32(rs2_u)
        next_pc = u32(self.pc + 4)

        imm_i = sign_extend(instruction >> 20, 12)
        imm_s = sign_extend(
            ((instruction >> 25) << 5) | ((instruction >> 7) & 0x1F), 12
        )
        imm_b = sign_extend(
            ((instruction >> 31) << 12)
            | (((instruction >> 7) & 0x1) << 11)
            | (((instruction >> 25) & 0x3F) << 5)
            | (((instruction >> 8) & 0xF) << 1),
            13,
        )
        imm_u = instruction & 0xFFFFF000
        imm_j = sign_extend(
            ((instruction >> 31) << 20)
            | (((instruction >> 12) & 0xFF) << 12)
            | (((instruction >> 20) & 0x1) << 11)
            | (((instruction >> 21) & 0x3FF) << 1),
            21,
        )

        if opcode == 0x33:
            if funct3 == 0x0:
                if funct7 == 0x00:
                    self._write_reg(rd, rs1_u + rs2_u)
                elif funct7 == 0x20:
                    self._write_reg(rd, rs1_u - rs2_u)
                else:
                    raise RuntimeError(f"Unsupported R-type funct7 0x{funct7:02x}")
            elif funct3 == 0x1:
                self._write_reg(rd, rs1_u << (rs2_u & 0x1F))
            elif funct3 == 0x2:
                self._write_reg(rd, 1 if rs1_s < rs2_s else 0)
            elif funct3 == 0x3:
                self._write_reg(rd, 1 if rs1_u < rs2_u else 0)
            elif funct3 == 0x4:
                self._write_reg(rd, rs1_u ^ rs2_u)
            elif funct3 == 0x5:
                if funct7 == 0x00:
                    self._write_reg(rd, rs1_u >> (rs2_u & 0x1F))
                elif funct7 == 0x20:
                    self._write_reg(rd, s32(rs1_u) >> (rs2_u & 0x1F))
                else:
                    raise RuntimeError(f"Unsupported shift funct7 0x{funct7:02x}")
            elif funct3 == 0x6:
                self._write_reg(rd, rs1_u | rs2_u)
            elif funct3 == 0x7:
                self._write_reg(rd, rs1_u & rs2_u)
            else:
                raise RuntimeError(f"Unsupported R-type funct3 0x{funct3:x}")

        elif opcode == 0x13:
            shamt = (instruction >> 20) & 0x1F
            if funct3 == 0x0:
                self._write_reg(rd, rs1_u + imm_i)
            elif funct3 == 0x1:
                self._write_reg(rd, rs1_u << shamt)
            elif funct3 == 0x2:
                self._write_reg(rd, 1 if rs1_s < imm_i else 0)
            elif funct3 == 0x3:
                self._write_reg(rd, 1 if rs1_u < u32(imm_i) else 0)
            elif funct3 == 0x4:
                self._write_reg(rd, rs1_u ^ u32(imm_i))
            elif funct3 == 0x5:
                if funct7 == 0x00:
                    self._write_reg(rd, rs1_u >> shamt)
                elif funct7 == 0x20:
                    self._write_reg(rd, s32(rs1_u) >> shamt)
                else:
                    raise RuntimeError(f"Unsupported I-shift funct7 0x{funct7:02x}")
            elif funct3 == 0x6:
                self._write_reg(rd, rs1_u | u32(imm_i))
            elif funct3 == 0x7:
                self._write_reg(rd, rs1_u & u32(imm_i))
            else:
                raise RuntimeError(f"Unsupported I-type funct3 0x{funct3:x}")

        elif opcode == 0x03:
            address = u32(rs1_u + imm_i)
            if funct3 == 0x0:
                self._write_reg(rd, self._load_le(address, 1, True))
            elif funct3 == 0x1:
                self._write_reg(rd, self._load_le(address, 2, True))
            elif funct3 == 0x2:
                self._write_reg(rd, self._load_le(address, 4, True))
            elif funct3 == 0x4:
                self._write_reg(rd, self._load_le(address, 1, False))
            elif funct3 == 0x5:
                self._write_reg(rd, self._load_le(address, 2, False))
            else:
                raise RuntimeError(f"Unsupported load funct3 0x{funct3:x}")

        elif opcode == 0x23:
            address = u32(rs1_u + imm_s)
            if funct3 == 0x0:
                self._store_le(address, 1, rs2_u)
            elif funct3 == 0x1:
                self._store_le(address, 2, rs2_u)
            elif funct3 == 0x2:
                self._store_le(address, 4, rs2_u)
            else:
                raise RuntimeError(f"Unsupported store funct3 0x{funct3:x}")

        elif opcode == 0x63:
            taken = False
            if funct3 == 0x0:
                taken = rs1_u == rs2_u
            elif funct3 == 0x1:
                taken = rs1_u != rs2_u
            elif funct3 == 0x4:
                taken = rs1_s < rs2_s
            elif funct3 == 0x5:
                taken = rs1_s >= rs2_s
            elif funct3 == 0x6:
                taken = rs1_u < rs2_u
            elif funct3 == 0x7:
                taken = rs1_u >= rs2_u
            else:
                raise RuntimeError(f"Unsupported branch funct3 0x{funct3:x}")
            if taken:
                next_pc = u32(self.pc + imm_b)

        elif opcode == 0x37:
            self._write_reg(rd, imm_u)

        elif opcode == 0x17:
            self._write_reg(rd, self.pc + imm_u)

        elif opcode == 0x6F:
            self._write_reg(rd, next_pc)
            next_pc = u32(self.pc + imm_j)

        elif opcode == 0x67:
            if funct3 != 0x0:
                raise RuntimeError(f"Unsupported jalr funct3 0x{funct3:x}")
            self._write_reg(rd, next_pc)
            next_pc = u32((rs1_u + imm_i) & ~1)

        elif opcode == 0x0F:
            pass

        elif opcode == 0x73:
            raise RuntimeError(
                f"Unsupported SYSTEM instruction 0x{instruction:08x} at pc=0x{self.pc:08x}"
            )

        else:
            raise RuntimeError(
                f"Unsupported opcode 0x{opcode:02x} at pc=0x{self.pc:08x}"
            )

        self.pc = next_pc


def format_register_block(registers: Sequence[int]) -> str:
    lines = ["Register File"]
    for base in range(0, 32, 4):
        row = "  ".join(
            f"x{index:02d}={int(registers[index]) & 0xFFFFFFFF:08x}"
            for index in range(base, base + 4)
        )
        lines.append(row)
    return "\n".join(lines) + "\n"


def main() -> int:
    parser = argparse.ArgumentParser(
        description="Simulate Instructions.hex and log each visible register-file state change."
    )
    parser.add_argument(
        "--hex-path",
        type=Path,
        default=DEFAULT_HEX_PATH,
        help="Input scalar/four-word hex file. Defaults to Core/Memory/Instructions.hex.",
    )
    parser.add_argument(
        "--log-path",
        type=Path,
        default=DEFAULT_LOG_PATH,
        help="Output log file for register-file state changes.",
    )
    parser.add_argument(
        "--pc-log-path",
        type=Path,
        default=DEFAULT_PC_LOG_PATH,
        help="Output sidecar log file mapping each register state to the simulator PC.",
    )
    parser.add_argument(
        "--max-steps",
        type=int,
        default=DEFAULT_MAX_STEPS,
        help="Maximum instruction steps before aborting.",
    )
    args = parser.parse_args()

    hex_path = args.hex_path.resolve()
    log_path = args.log_path.resolve()
    pc_log_path = args.pc_log_path.resolve()

    simulator = NativeSimulator(hex_path)
    simulator.reset()

    last_logged = list(simulator.get_registers())
    blocks = [format_register_block(last_logged)]
    pc_entries = [f"0 0x{simulator.pc:08x}"]

    for _ in range(args.max_steps):
        simulator.step()
        current = list(simulator.get_registers())

        if current != last_logged:
            blocks.append(format_register_block(current))
            pc_entries.append(f"{len(blocks) - 1} 0x{simulator.pc:08x}")
            last_logged = current

        if (current[10] & 0xFFFFFFFF) in TOHOST_VALUES:
            log_path.write_text("\n".join(blocks), encoding="utf-8")
            pc_log_path.write_text("\n".join(pc_entries) + "\n", encoding="utf-8")
            print(
                f"Stopped with tohost=0x{current[10] & 0xFFFFFFFF:08x} after {simulator.step_count} step(s)"
            )
            print(f"Wrote trace log to {log_path}")
            print(f"Wrote PC log to {pc_log_path}")
            return 0

    log_path.write_text("\n".join(blocks), encoding="utf-8")
    pc_log_path.write_text("\n".join(pc_entries) + "\n", encoding="utf-8")
    raise SystemExit(
        f"tohost was not reached within {args.max_steps} step(s); partial logs written to {log_path} and {pc_log_path}"
    )


if __name__ == "__main__":
    raise SystemExit(main())
