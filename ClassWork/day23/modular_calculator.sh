#!/bin/bash

# --------- Function Definitions ---------

# Function to add two numbers
add() {
    echo $(( $1 + $2 ))
}

# Function to subtract two numbers
subtract() {
    echo $(( $1 - $2 ))
}

# Function to multiply two numbers
multiply() {
    echo $(( $1 * $2 ))
}

# Function to divide two numbers
divide() {
    if [ "$2" -eq 0 ]; then
        echo "Error: Division by zero"
        return 1
    fi
    echo $(( $1 / $2 ))
}

# --------- Main Program ---------

# Read inputs from user
read -p "Enter first number: " num1
read -p "Enter second number: " num2

# Display menu
echo "Choose operation:"
echo "1. Add"
echo "2. Subtract"
echo "3. Multiply"
echo "4. Divide"

read -p "Enter choice (1-4): " choice

# Call functions based on user choice
case "$choice" in
    1)
        result=$(add "$num1" "$num2")
        ;;
    2)
        result=$(subtract "$num1" "$num2")
        ;;
    3)
        result=$(multiply "$num1" "$num2")
        ;;
    4)
        result=$(divide "$num1" "$num2") || exit 1
        ;;
    *)
        echo "Invalid choice"
        exit 1
        ;;
esac

# Display result
echo "Result: $result"
