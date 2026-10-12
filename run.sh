#!/usr/bin/env bash
set -e
ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

if [ $# -ne 1 ]; then
    echo "Usage: ./run.sh <directory/file.cpp>"
    exit 1
fi

SOURCE="$ROOT/$1"

if [ ! -f "$SOURCE" ]; then
    echo "Error: source file not found: $1"
    exit 1
fi

if [[ "$SOURCE" != *.cpp ]]; then
    echo "Error: source file must be a .cpp file"
    exit 1
fi

BINARY="$(mktemp /tmp/cp_solution.XXXXXX)"
trap 'rm -f "$BINARY"' EXIT
echo "Compiling: $1"
g++ -std=c++20 -O2 -g -DLOCAL -Wall -Wextra -Wshadow -Wconversion -Wfloat-equal -D_GLIBCXX_DEBUG -fsanitize=address,undefined -fno-sanitize-recover=all "$SOURCE" -o "$BINARY"
echo "Running:"
echo
"$BINARY"

echo
echo "Debug run completed successfully."
echo "next run:"
echo "g++ -std=c++20 -O2 \"$1\" -o main_fast"