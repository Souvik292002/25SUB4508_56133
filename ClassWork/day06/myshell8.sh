#!/bin/bash


my_function(){
	echo "function gets called"
}

my_function


add() {
	local v1=$1
	local v2=$2
	sum=$((v1+v2))
	echo "Sum of 2 numbers = $sum"
}

add 10 20


prod() {
	local v1=$1
	local v2=$2
	local p=$((v1*v2))
	echo $p
}

result=$(prod 4 3)

echo "Prod of 2 numbers is: $result"


