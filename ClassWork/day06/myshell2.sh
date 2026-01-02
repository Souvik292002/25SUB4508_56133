#!/bin/bash

echo "Program to check if person is eligible to vote"


echo "Enter the age: "

read age

if [ $age -ge 18 ]
then
	echo "Eligible to Vote"
else
	echo "You are Minor"
fi

