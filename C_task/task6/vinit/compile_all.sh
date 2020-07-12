#!/bin/bash
if [ /home/pi/vinit/git_repo/C-Codes/C_task/task6/vinit/find_my_ip ]
then
     gcc -o find_my_ip find_my_ip.c 
 		if [ 0 -ne 0 ]
		then
   	     echo compilation Failed
	  	     exit 1	
          fi
     gcc -c -pie find_my_ip.c 
 		if [ 0 -ne 0 ]
		then
   	     echo compilation Failed
	  	     exit 1	
          fi
     gcc -shared -o find_my_ip.so find_my_ip.o 
 		if [ 0 -ne 0 ]
		then
   	     echo compilation Failed
	  	     exit 1	
          fi
fi
echo compilation sucessful
 exit 0
