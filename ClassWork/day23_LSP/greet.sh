#!/bin/bash

# Check if exactly 2 arguments are provided
if [ $# -ne 2 ]; then
    echo "Usage: $0 <name> <age>"
    exit 1
fi

name=$1
age=$2

echo "Hello $name 👋"
echo "You are $age years old."
