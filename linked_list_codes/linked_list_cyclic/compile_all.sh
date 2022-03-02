#!/bin/bash

echo "** Compile Linked List **"

gcc *.c -o linked_list_cyclic.out

if [ $? -ne 0 ]
then
    echo " Compilation Failed "
else
    ./linked_list_cyclic.out
    echo " Done "
fi
