/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

/* Reverse Byte*/

char reverse_byte(char byte)
{
    byte=(byte &0xF0)>>4 | (byte &0x0F)<<4;
    byte=(byte &0xCC)>>2 | (byte &0x33)<<2;
    byte=(byte &0xAA)>>1 | (byte &0x55)<<1;
    return byte;
}

int main()
{
    printf("Hello World %X",(unsigned int)reverse_byte(0xAA));

    return 0;
}
