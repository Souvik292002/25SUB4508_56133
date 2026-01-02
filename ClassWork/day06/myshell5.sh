#!/bin/bash

echo "enter a value: "

read val

if [ $val -eq 10 ]; then
	echo "value is eq to 10"
elif [ $val -eq 20 ]; then
	echo "value is eq to 20"
else
	echo "doesn't match the required values"
fi

