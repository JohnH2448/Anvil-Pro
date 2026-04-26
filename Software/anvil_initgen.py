from __future__ import annotations

import argparse
import subprocess
from pathlib import Path


SECTIONS = (".rodata", ".srodata", ".data", ".sdata")


def run_text(command: list[str]) -> str:
    return subprocess.run(command, check=True, text=True, capture_output=True).stdout


def section_headers(objdump: str, elf: Path) -> dict[str, tuple[int, int]]:
    headers: dict[str, tuple[int, int]] = {}
    text = run_text([objdump, "-h", str(elf)])

    for line in text.splitlines():
        parts = line.split()
        if len(parts) < 7:
            continue
        name = parts[1]
        if name not in SECTIONS:
            continue
        size = int(parts[2], 16)
        vma = int(parts[3], 16)
        if size:
            headers[name] = (vma, size)

    return headers


def dump_section(objcopy: str, elf: Path, section: str, out_dir: Path) -> bytes:
    output = out_dir / f"{section.strip('.')}.bin"
    if output.exists():
        output.unlink()
    subprocess.run(
        [objcopy, "-O", "binary", f"--only-section={section}", str(elf), str(output)],
        check=True,
    )
    return output.read_bytes() if output.exists() else b""


def emit_li(lines: list[str], register: str, value: int) -> None:
    lines.append(f"    li {register}, 0x{value & 0xffffffff:08x}")


def emit_stores(lines: list[str], address: int, data: bytes) -> None:
    offset = 0
    length = len(data)

    while offset < length:
        current_address = address + offset
        remaining = length - offset

        if current_address % 4 == 0 and remaining >= 4:
            word = int.from_bytes(data[offset : offset + 4], "little")
            if word != 0:
                emit_li(lines, "t0", current_address)
                emit_li(lines, "t1", word)
                lines.append("    sw t1, 0(t0)")
            offset += 4
        else:
            byte = data[offset]
            if byte != 0:
                emit_li(lines, "t0", current_address)
                lines.append(f"    li t1, 0x{byte:02x}")
                lines.append("    sb t1, 0(t0)")
            offset += 1


def main() -> int:
    parser = argparse.ArgumentParser(description="Generate Anvil startup stores for initialized data sections.")
    parser.add_argument("elf", type=Path)
    parser.add_argument("output", type=Path)
    parser.add_argument("--objdump", default="riscv32-unknown-elf-objdump")
    parser.add_argument("--objcopy", default="riscv32-unknown-elf-objcopy")
    args = parser.parse_args()

    elf = args.elf.resolve()
    output = args.output.resolve()
    output.parent.mkdir(parents=True, exist_ok=True)

    headers = section_headers(args.objdump, elf)

    lines: list[str] = [
        '    .section .text.init_data, "ax", @progbits',
        "    .globl __anvil_init_data",
        "    .type __anvil_init_data, @function",
        "__anvil_init_data:",
    ]

    for section in SECTIONS:
        if section not in headers:
            continue
        address, size = headers[section]
        data = dump_section(args.objcopy, elf, section, output.parent)
        if len(data) != size:
            raise RuntimeError(f"{section}: header size {size} but dumped {len(data)} bytes")
        emit_stores(lines, address, data)

    lines.extend(
        [
            "    ret",
            "    .size __anvil_init_data, . - __anvil_init_data",
            "",
        ]
    )

    output.write_text("\n".join(lines))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
