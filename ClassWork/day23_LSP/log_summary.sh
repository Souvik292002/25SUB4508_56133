#!/bin/bash

# -------- Argument Validation --------

# Check if exactly one argument (log file) is provided
if [ $# -ne 1 ]; then
    echo "Usage: $0 <log_file>"
    exit 1
fi

logfile="$1"

# -------- File Validation --------

# Check if file exists
if [ ! -f "$logfile" ]; then
    echo "Error: Log file does not exist."
    exit 2
fi

# Check if file is readable
if [ ! -r "$logfile" ]; then
    echo "Error: Log file is not readable."
    exit 3
fi

# -------- Log Level Counting --------

info_count=$(grep -c "INFO" "$logfile")
warning_count=$(grep -c "WARNING" "$logfile")
error_count=$(grep -c "ERROR" "$logfile")

# -------- Display Summary --------

echo "========= Log Summary ========="
echo "Log File : $logfile"
echo "INFO     : $info_count"
echo "WARNING  : $warning_count"
echo "ERROR    : $error_count"
echo "==============================="
