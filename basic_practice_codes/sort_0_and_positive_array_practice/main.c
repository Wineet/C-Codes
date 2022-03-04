/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int a[]={0,0,1,2,0,0,0,1,0,4,0,3,2};
    // Output: 1 2 1 4 3 2 0 0 0 0 0 0 0 
    
    int size=sizeof(a)/sizeof(int);
    int zero_count=0;
    for(int i=0;i<size;i++)
    {
        if(a[i]==0)
        {
            int j=i+1;
            for(int j=i+1;j<size;j++)
            {
                if(a[j]!=0)
                {
                  
                    /*swapping zero and non zero element*/
                    int temp=a[j];
                    a[j]=a[i];
                    a[i]=temp;
                    break;
                }
            }
           
        }
    }
    
    for(int i=0;i<size;i++)
    {
        printf("%d ",a[i]);   
    }
    return 0;
}
