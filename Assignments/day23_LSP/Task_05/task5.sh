#!/bin/bash

# Check for correct arguments
if [ $# -ne 2 ]; then
    echo "Usage: $0 <filename> <word>"
    exit 1
fi

file=$1
word=$2

# Pipes and filters
grep "$word" "$file" | sort

