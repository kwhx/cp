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

BINARY="/tmp/cp_solution"

echo "Compiling: $1"

g++ -std=c++20 -Wall -Wextra -O2 "$SOURCE" -o "$BINARY"

echo "Running"
echo

"$BINARY"
