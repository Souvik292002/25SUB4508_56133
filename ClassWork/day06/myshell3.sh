#!/bin/bash

echo "First Args/File Name: $0"
echo "No of Args passed : $#"

echo "First args to shell : $1"
echo "second arg to shell : $2"

echo "Quoted values : $@"
echo "Quoted values : $*"


for args in $@
do
	echo "Arg $args"
done

# $? - indicate the exit status of the previous command

echo $?

echo "Your PATH is $PATH"

gVar=10

my_function(){
	local local_var=20
	echo "local variable value : $local_var"
	echo "Global variable value: $gVar"
}


my_function

echo "Gvar : $gVar"
echo "local var: $local_var"

echo $?

