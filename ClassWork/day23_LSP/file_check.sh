#!/bin/bash

# Check if filename argument is provided
if [ $# -ne 1 ]; then
    echo "Usage: $0 <filename>"
    exit 1
fi

file=$1

echo "========= File Validation Report ========="
echo "File Name: $file"
echo "------------------------------------------"

# Check if file exists and is a regular file
if [ -f "$file" ]; then
    echo "✔ File exists (regular file)"
else
    echo "✘ File does not exist or is not a regular file"
    exit 1
fi

# Check read permission
if [ -r "$file" ]; then
    echo "✔ Readable      : Yes"
else
    echo "✘ Readable      : No"
fi

# Check write permission
if [ -w "$file" ]; then
    echo "✔ Writable      : Yes"
else
    echo "✘ Writable      : No"
fi

# Check execute permission
if [ -x "$file" ]; then
    echo "✔ Executable    : Yes"
else
    echo "✘ Executable    : No"
fi
