#!/bin/bash

# Check if the script has execute permission
if [ ! -x "$0" ]; then
    echo "Error: Script does not have execute permission."
    echo "Run: chmod +x $0"
    exit 1
fi

echo "===================================="
echo "   Welcome to Script: $(basename "$0")"
echo "===================================="

echo "Date          : $(date)"
echo "User          : $USER"
echo "Working Dir   : $(pwd)"
