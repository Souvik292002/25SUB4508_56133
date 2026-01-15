#!/bin/bash

# Declare a local variable
local_var="I am a local variable"

# Declare an environment variable
export env_var="I am an environment variable"

# Display both variables in parent script
echo "Inside Parent Script:"
echo "Local Variable      : $local_var"
echo "Environment Variable: $env_var"

echo "--------------------------------"

# Run the child script
./child.sh
