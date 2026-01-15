#!/bin/bash

# Check if directory argument is provided
if [ $# -ne 1 ]; then
    echo "Usage: $0 <directory_path>"
    exit 1
fi

dir=$1

# Check if the directory exists
if [ ! -d "$dir" ]; then
    echo "Error: Directory does not exist."
    exit 1
fi

# Initialize counters
txt_count=0
log_count=0
other_count=0

# Loop through files in the directory
for file in "$dir"/*; do
    # Skip if no files are present
    [ -e "$file" ] || continue

    # Check if it's a regular file
    if [ -f "$file" ]; then
        case "$file" in
            *.txt)
                txt_count=$((txt_count + 1))
                ;;
            *.log)
                log_count=$((log_count + 1))
                ;;
            *)
                other_count=$((other_count + 1))
                ;;
        esac
    fi
done

# Display result
echo "======= File Count Report ======="
echo ".txt files : $txt_count"
echo ".log files : $log_count"
echo "Other files: $other_count"
