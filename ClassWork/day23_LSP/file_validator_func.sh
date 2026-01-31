#!/bin/bash

# -------- Function Definition --------
check_file() {
    file="$1"      # Function argument (filename)

    # Check if file exists
    if [ ! -f "$file" ]; then
        echo "Error: File does not exist."
        return 1
    fi

    echo "File: $file"

    # Check file size
    size=$(stat -c %s "$file")
    echo "Size: $size bytes"

    # Check permissions
    [ -r "$file" ] && echo "Readable   : Yes" || echo "Readable   : No"
    [ -w "$file" ] && echo "Writable   : Yes" || echo "Writable   : No"
    [ -x "$file" ] && echo "Executable : Yes" || echo "Executable : No"

    return 0
}

# -------- Main Program --------

# Check argument count
if [ $# -ne 1 ]; then
    echo "Usage: $0 <filename>"
    exit 1
fi

# Call function with filename
check_file "$1"

# Capture function return status
status=$?

# Final result
if [ $status -eq 0 ]; then
    echo "File validation successful."
else
    echo "File validation failed."
fi
