#!/bin/bash

# Declare variables
name="Souvik"
age=21

# If-else condition
if [ $age -ge 18 ]; then
    echo "Hello $name, you are eligible to vote."
else
    echo "Hello $name, you are not eligible to vote yet."
fi
