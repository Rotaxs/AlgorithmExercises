#!/usr/bin/env python3
"""Show file and line counts for source and documentation in this repository."""

import argparse
import subprocess
from collections import defaultdict
from dataclasses import dataclass
from pathlib import Path
from unicodedata import east_asian_width


ROOT = Path(__file__).resolve().parents[1]
FILE_TYPES = {
    "C/C++": {".c", ".cc", ".cpp", ".cxx", ".c++", ".h", ".hh", ".hpp", ".hxx", ".h++"},
    "Python": {".py"},
    "Markdown": {".md"},
    "其他文本": {".sh", ".txt", ".json", ".yaml", ".yml", ".toml", ".ini"},
}
EXTENSION_TYPE = {
    extension: name for name, extensions in FILE_TYPES.items() for extension in extensions
}


@dataclass
class Counts:
    files: int = 0
    lines: int = 0
    nonblank: int = 0

    def add(self, lines, nonblank):
        self.files += 1
        self.lines += lines
        self.nonblank += nonblank


def tracked_and_untracked_paths():
    result = subprocess.run(
        ["git", "-C", str(ROOT), "ls-files", "--cached", "--others", "--exclude-standard", "-z"],
        check=True,
        stdout=subprocess.PIPE,
    )
    return sorted({
        Path(raw.decode("utf-8", errors="surrogateescape"))
        for raw in result.stdout.split(b"\0") if raw
    })


def show_table(rows):
    def display_width(value):
        return sum(2 if east_asian_width(char) in "FW" else 1 for char in value)

    data = [["名称", "文件数", "总行数", "非空行", "空行"]]
    for name, counts in rows:
        data.append([
            name, f"{counts.files:,}", f"{counts.lines:,}",
            f"{counts.nonblank:,}", f"{counts.lines - counts.nonblank:,}",
        ])

    stops = []
    position = 0
    for index in range(4):
        width = max(display_width(row[index]) for row in data) + 1
        position = ((position + width + 7) // 8) * 8
        stops.append(position)

    for row in data:
        parts = []
        position = 0
        for index, value in enumerate(row):
            parts.append(value)
            position += display_width(value)
            if index < 4:
                tabs = stops[index] // 8 - position // 8
                parts.append("\t" * tabs)
                position = stops[index]
        print("".join(parts))


def main():
    parser = argparse.ArgumentParser(description="按类型和目录统计项目文本文件行数")
    parser.add_argument("directory", nargs="?", default=".", help="要统计的子目录，默认整个仓库")
    args = parser.parse_args()
    target = (ROOT / args.directory).resolve()
    if not target.is_dir() or not target.is_relative_to(ROOT):
        parser.error("目录必须位于项目内，且已经存在")
    prefix = target.relative_to(ROOT)

    total = Counts()
    by_type = defaultdict(Counts)
    by_directory = defaultdict(Counts)
    by_directory_type = defaultdict(Counts)
    for relative in tracked_and_untracked_paths():
        if not relative.is_relative_to(prefix):
            continue
        category = EXTENSION_TYPE.get(relative.suffix.lower())
        path = ROOT / relative
        if category is None or not path.is_file() or path.is_symlink():
            continue
        content_lines = path.read_text(encoding="utf-8", errors="replace").splitlines()
        lines = len(content_lines)
        nonblank = sum(bool(line.strip()) for line in content_lines)
        remainder = relative.relative_to(prefix)
        directory = remainder.parts[0] if len(remainder.parts) > 1 else "(当前目录)"
        for counts in (total, by_type[category], by_directory[directory],
                       by_directory_type[directory, category]):
            counts.add(lines, nonblank)

    print(f"统计范围：{prefix}/" if prefix != Path(".") else "统计范围：整个项目")
    print("文件范围：Git 已跟踪文件和未忽略的新文件；空行包括只含空白字符的行")
    print("\n总计：")
    show_table([("全部", total)])
    print("\n按类型：")
    show_table([(name, by_type[name]) for name in FILE_TYPES if by_type[name].files])
    print("\n按目录（含子目录）：")
    rows = []
    for directory in sorted(by_directory):
        rows.append((directory, by_directory[directory]))
        present = [category for category in FILE_TYPES if by_directory_type[directory, category].files]
        if len(present) > 1:
            for category in present:
                rows.append((f"  {directory} / {category}", by_directory_type[directory, category]))
    show_table(rows)


if __name__ == "__main__":
    main()
