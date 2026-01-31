#!/bin/bash

# Generate a random number between 1 and 50
secret=$(( RANDOM % 50 + 1 ))

echo "🎯 Number Guessing Game"
echo "Guess a number between 1 and 50"

# Initialize guess variable
guess=0

# Loop until the correct number is guessed
while [ "$guess" -ne "$secret" ]; do
    read -p "Enter your guess: " guess

    # Check if input is numeric
    if ! [[ "$guess" =~ ^[0-9]+$ ]]; then
        echo "❌ Please enter a valid number."
        continue
    fi

    # Compare guess with secret number
    if [ "$guess" -lt "$secret" ]; then
        echo "📉 Too low! Try again."
    elif [ "$guess" -gt "$secret" ]; then
        echo "📈 Too high! Try again."
    else
        echo "🎉 Correct! You guessed the number."
    fi
done
