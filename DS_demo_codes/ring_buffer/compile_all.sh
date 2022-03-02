#!/bin/bash
if [ -e m ]
then
    rm m
fi
gcc -o m *.c
if [ $? -ne 0 ]
then
	echo Compilation Failed
	exit 1
fi
echo Compilation Successful
