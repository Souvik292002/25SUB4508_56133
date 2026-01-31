#!/bin/bash

echo "Users using /bin/bash shell:"
echo "--------------------------------"

# Extract username and shell, then filter users with /bin/bash
cut -d: -f1,7 /etc/passwd | grep "/bin/bash"
