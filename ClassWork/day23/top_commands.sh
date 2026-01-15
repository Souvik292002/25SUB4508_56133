#!/bin/bash

HISTORY_FILE="$HOME/.bash_history"

# Check if history file exists
if [ ! -f "$HISTORY_FILE" ]; then
    echo "Error: .bash_history file not found."
    exit 1
fi

echo "Top 5 most-used commands:"
echo "--------------------------"

# Analyze command usage
cut -d' ' -f1 "$HISTORY_FILE" \
| sort \
| uniq -c \
| sort -nr \
| head -5
