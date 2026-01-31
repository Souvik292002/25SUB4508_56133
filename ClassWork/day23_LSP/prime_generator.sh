#!/bin/bash

# Ask user for the upper limit
read -p "Enter the value of N: " N

# Validate numeric input
if ! [[ "$N" =~ ^[0-9]+$ ]]; then
    echo "Error: Please enter a valid positive number."
    exit 1
fi

echo "Prime numbers between 1 and $N are:"

# Outer loop: iterates through numbers from 2 to N
for (( num=2; num<=N; num++ )); do
    is_prime=1   # Assume number is prime

    # Inner loop: checks divisibility
    for (( i=2; i<=num/2; i++ )); do
        if [ $((num % i)) -eq 0 ]; then
            is_prime=0
            break
        fi
    done

    # If number is prime, print it
    if [ $is_prime -eq 1 ]; then
        echo -n "$num "
    fi
done

echo
