from __future__ import annotations

import argparse
import sys
from pathlib import Path


DEFAULT_INPUT = (
    Path(__file__).resolve().parents[2] / "Core" / "Memory" / "Instructions.hex"
)


def load_words(path: Path) -> list[str]:
    words: list[str] = []
    for line_number, raw_line in enumerate(path.read_text().splitlines(), start=1):
        text = raw_line.strip()
        if not text:
            continue
        if len(text) not in (8, 32):
            raise ValueError(
                f"{path}:{line_number}: expected 8 or 32 hex digits, found {len(text)}"
            )
        try:
            int(text, 16)
        except ValueError as exc:
            raise ValueError(f"{path}:{line_number}: invalid hex value '{text}'") from exc
        words.append(text.upper())
    return words


def convert_scalar_words(words: list[str]) -> list[str]:
    if not words:
        return []

    widths = {len(word) for word in words}
    if widths == {32}:
        return words
    if widths != {8}:
        raise ValueError("input must contain only 8-digit words or only 32-digit lines")

    grouped: list[str] = []
    for index in range(0, len(words), 4):
        chunk = words[index : index + 4]
        padded_chunk = list(reversed(chunk)) + ["00000000"] * (4 - len(chunk))
        grouped.append("".join(padded_chunk))
    return grouped


def main() -> int:
    parser = argparse.ArgumentParser(
        description="Convert 32-bit hex instructions into 128-bit four-word lines."
    )
    parser.add_argument(
        "path",
        nargs="?",
        type=Path,
        default=DEFAULT_INPUT,
        help="Path to the hex file to rewrite in place.",
    )
    args = parser.parse_args()

    path = args.path.resolve()
    if not path.exists():
        print(f"Input file not found: {path}", file=sys.stderr)
        return 1

    try:
        words = load_words(path)
        converted = convert_scalar_words(words)
    except ValueError as exc:
        print(exc, file=sys.stderr)
        return 1

    output = "\n".join(converted)
    if converted:
        output += "\n"
    path.write_text(output)

    print(f"Rewrote {path} with {len(converted)} four-word line(s).")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
