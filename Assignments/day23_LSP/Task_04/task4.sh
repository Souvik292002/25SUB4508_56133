#!/bin/bash

# Function to count lines in a file
count_lines() {
    local file=$1
    if [ -f "$file" ]; then
        lines=$(wc -l < "$file")
        echo "File: $file has $lines lines"
    else
        echo "File: $file does not exist"
    fi
}

# List of files
files=(file1.txt file2.txt file3.txt)

# Loop through files
for f in "${files[@]}"; do
    count_lines "$f"
done
