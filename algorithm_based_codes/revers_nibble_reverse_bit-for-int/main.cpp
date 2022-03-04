/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
/* code to reverse interger Value shifiting Nibble Value i/P 0X1234 0x4321 */
    int x=0x1A74;
    int result=0;
    while(x!=0)
    {
        int temp = x&0x0F;
        result=result<<4;
        result |= temp;
        x=x>>4;
    }
    printf("reverse nibble %x\n",result);

/* reverse integer by bit value ex: if binary is 0101010110 0110101010*/

    int y=0x1234;
    int y_result=0;
    while(y!=0)
    {
        int temp = y&0x01;
        y_result=y_result<<1;
        y_result |= temp;
        y=y>>1;
    }
    printf("reverse bit %x\n",y_result);
    return 0;
}
