// To Check the whether little endian or big endian

#include<stdio.h>

void main()
{
unsigned  int x=0x01;
char *p;
p=(char *)&x;
    if(*p==1)
    {
    printf("little endian ");
    }
    else{
    printf("Big Endian");
    }

 }
