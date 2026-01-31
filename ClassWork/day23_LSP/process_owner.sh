#!/bin/bash

# -------- Argument Validation --------

# Check if exactly one argument (process name) is provided
if [ $# -ne 1 ]; then
    echo "Usage: $0 <process_name>"
    exit 1
fi

process_name="$1"

echo "Process Name : $process_name"
echo "PID     USER"
echo "----------------"

# Find PID and owner of the process
ps -eo pid,user,comm | grep -w "$process_name" | grep -v grep
