#!/bin/bash

# -------- Function Definition --------
check_user_login() {
    username="$1"

    # Check if the user is currently logged in
    if who | awk '{print $1}' | grep -wq "$username"; then
        return 0   # success
    else
        return 1   # failure
    fi
}

# -------- Main Program --------

# Ask for username
read -p "Enter username to check: " user

# Call the function with username
check_user_login "$user"

# Capture return value
status=$?

# Display message based on return value
if [ $status -eq 0 ]; then
    echo "✅ User '$user' is currently logged in."
else
    echo "❌ User '$user' is NOT logged in."
fi
