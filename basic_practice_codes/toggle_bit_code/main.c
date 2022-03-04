/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

/* Toggle Bit Code */

int main()
{
    int x=0xF1;
    for(int i=0;i<5;i++)
    {
        x ^= (1<<0);
        printf(" %x",x);
    }
    return 0;
}
