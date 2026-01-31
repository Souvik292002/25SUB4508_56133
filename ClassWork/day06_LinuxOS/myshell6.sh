#!/bin/bash


echo "enter a value: "
read v1

if [ $v1 -gt 0 ]; then
	if [ $v1 -lt 10 ]; then
		echo "value enter is beteween 1-9"
	fi
fi

