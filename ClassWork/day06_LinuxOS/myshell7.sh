#!/bin/bash


for i in {1..10}; do
	echo $i
done


count=1

echo "Below is from the while loop"

while [ $count -le 10 ]; do
	echo "Count = $count"
	((count++))
done

echo "Below output is with untill loop"

count=1
until [ $count -gt 5 ]; do
	echo "Count = $count"
	((count++))
done


#use of break and continue


for i in {1..10}; do
	echo "Value: $i"
	if [ $i -eq 6 ]; then
		break
	fi
done




for i in {1..10}; do
	if [ $i -eq 6 ]; then
		continue
	fi
	echo "Value: $i"
done


#nesting of loops

for i in {2..4}; do
	for j in {1..10}; do
		prod=$((i*j))
		echo "$i x $j = $prod"
	done
	echo "============================="
done

