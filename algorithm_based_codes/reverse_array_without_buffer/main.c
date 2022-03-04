/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

/* Write a function to reverse array*/

void swap(int *ptr1,int *ptr2)
{
    int temp=*ptr1;
    *ptr1=*ptr2;
    *ptr2=temp;
}
int main()
{
    int arr[]={1,2,3,4,5,23,34,43,0};
    int size=sizeof(arr)/sizeof(int);
    for(int i=0,j=size-1;i<j;i++,j--)
    {
        swap(&arr[i],&arr[j]);
    }
    
    for(int i=0;i<size;i++)
    {
        printf(" %d",arr[i]);
    }
    return 0;
}
