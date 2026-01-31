#!/bin/bash

# Read first number
read -p "Enter first number: " num1

# Read operator
read -p "Enter operator (+ - * /): " op

# Read second number
read -p "Enter second number: " num2

# Calculator using case statement
case "$op" in
    +)
        result=$(( num1 + num2 ))
        ;;
    -)
        result=$(( num1 - num2 ))
        ;;
    \*)
        result=$(( num1 * num2 ))
        ;;
    /)
        if [ "$num2" -eq 0 ]; then
            echo "Error: Division by zero is not allowed."
            exit 1
        fi
        result=$(( num1 / num2 ))
        ;;
    *)
        echo "Invalid operator. Use +, -, *, or /"
        exit 1
        ;;
esac

# Display result
echo "Result: $num1 $op $num2 = $result"
