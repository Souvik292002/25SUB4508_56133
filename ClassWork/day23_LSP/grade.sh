#!/bin/bash

# Ask user to enter marks
read -p "Enter marks (0-100): " marks

# Validate numeric input (only digits)
if ! [[ "$marks" =~ ^[0-9]+$ ]]; then
    echo "Error: Marks must be a numeric value."
    exit 1
fi

# Validate range
if [ "$marks" -lt 0 ] || [ "$marks" -gt 100 ]; then
    echo "Error: Marks must be between 0 and 100."
    exit 1
fi

# Grade classification using if-elif-else
if [ "$marks" -ge 90 ]; then
    grade="A+"
elif [ "$marks" -ge 80 ]; then
    grade="A"
elif [ "$marks" -ge 70 ]; then
    grade="B"
elif [ "$marks" -ge 60 ]; then
    grade="C"
elif [ "$marks" -ge 50 ]; then
    grade="D"
else
    grade="F"
fi

# Display result
echo "Marks Obtained : $marks"
echo "Grade          : $grade"
