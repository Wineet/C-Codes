/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>

int swap_bits(int num,int bit1,int bit2)
{
    int temp= (num >> bit1) & 0x01;
    int temp2=(num >> bit2) & 0x01;
    
    num &= ~(1<<bit1);
    num &= ~(1<<bit2);
    num |= (temp << bit2);
    num |= (temp2 << bit1);
    return num;
}

int main()
{
    printf("x=%x \n",swap_bits(0XAA,5,4));
    return 0;
}
