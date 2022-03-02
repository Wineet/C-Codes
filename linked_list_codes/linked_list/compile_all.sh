#!/bin/bash

echo "** Compile Linked List **"

gcc *.c -o linked_list.out

if [ $? -ne 0 ]
then
    echo " Compilation Failed "
fi
