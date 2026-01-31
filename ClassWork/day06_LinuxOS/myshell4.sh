#!/bin/bash

#contact

fName="Bhima"
sName="Shankar"

echo "$fName$sName"

fullName=$fName$sName

echo $fullName

num1=10
num2=20

sum=$((num1+num2))
echo $sum


fruits=("apple" "banana" "grapes")

echo ${fruits[@]}

for fruit in "${fruits[@]}"
do
	echo $fruit
done

#Assicative array

declare -A colors
colors[apple]="red"
colors[banana]="yellow"
colors[grapes]="green"

echo ${colors[apple]}
echo ${colors[grapes]}


#operators
# -eq => equalto
# -ne => not equal to
# -lt => less than
# -gt => greater than
# -ge => greater than or equal to
# -le => less than or equal to


#string cmp ops

# = =>equal to
# != => not equal to
# < => less than for ascii char cmp
# > => greater than


#Arithematic ops

# +, -, *, /, %

#logical ops

# &&, ||, !


#files based ops

# -e => check if the file exists
# -d => check if dir exists
# -f => check if a file is regular
# -s => check if the file is empty
