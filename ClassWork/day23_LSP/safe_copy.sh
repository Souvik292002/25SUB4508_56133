#!/bin/bash

# ---------- Argument Validation ----------

# Check if exactly two arguments are provided
if [ $# -ne 2 ]; then
    echo "Usage: $0 <source_file> <destination_path>"
    exit 1
fi

source_file="$1"
destination="$2"

# ---------- Source File Checks ----------

# Check if source file exists
if [ ! -f "$source_file" ]; then
    echo "Error: Source file does not exist."
    exit 2
fi

# Check read permission on source file
if [ ! -r "$source_file" ]; then
    echo "Error: Source file is not readable."
    exit 3
fi

# ---------- Destination Checks ----------

# If destination is a directory, check write permission
if [ -d "$destination" ]; then
    if [ ! -w "$destination" ]; then
        echo "Error: No write permission on destination directory."
        exit 4
    fi
fi

# ---------- Copy Operation ----------

cp "$source_file" "$destination"
status=$?

# ---------- Exit Status Handling ----------

if [ $status -eq 0 ]; then
    echo "File copied successfully."
    exit 0
else
    echo "Error: File copy failed."
    exit 5
fi
