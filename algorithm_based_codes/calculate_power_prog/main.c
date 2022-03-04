/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
/* Write Recursive Power Function */

int power(int n,int power_)
{
    if(power_==0)
    {
        return 1;
    }
    if(power_==1)
    {
        return n;
    }
    return n*power(n,power_-1);
}
int main()
{
    printf("pow = %d",power(2,0));

    return 0;
}
