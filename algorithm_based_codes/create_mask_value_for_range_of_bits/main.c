/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
/* Create Mask Value for a range to set or reset bits */

int power(int base, int power)
{
    int temp=base;
    for(int i=1;i<power;i++)
    {
        base *=temp;
    }
    return base;
}
int create_mask_value(int m,int n)
{
    int diff=n-m+1; //masking range bits too
    return (power(2,diff) -1)<<m;
}
int create_mask_value2(int m,int n)
{
    int mask_value=0; 
    for(int i=m;i<=n;i++)
    {
        mask_value|=(1<<i);
    }
    return mask_value;
}

int main()
{
    printf("Mask Value %d\n",create_mask_value(2,5));
    printf("Mask Value %d\n",create_mask_value2(2,5));
    int var=0XABCD;
    var &=create_mask_value(2,5);
    printf("var = %d\n",var);
    return 0;
}

