#!/bin/bash

# Store basic salary
basic=30000

# Calculate allowances using arithmetic expansion
hra=$(( basic * 20 / 100 ))
da=$(( basic * 15 / 100 ))

# Calculate gross salary
gross=$(( basic + hra + da ))

# Display formatted output
echo "================ Salary Slip ================"
echo "Basic Salary : ₹$basic"
echo "HRA (20%)    : ₹$hra"
echo "DA  (15%)    : ₹$da"
echo "---------------------------------------------"
echo "Gross Salary : ₹$gross"
