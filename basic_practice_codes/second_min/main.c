/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
    int arr[]={1,2,3,4,5};
    int min=0XFF,sec_min=0XFF;
    for(int i=0;i<5;i++)
    {
        if(min>arr[i])
        {
            min=arr[i];
        }
        if(min < arr[i] && sec_min>arr[i] )
        {
            sec_min = arr[i];
        }
    }
    
    printf("Hello World %d %d\n",min, sec_min);

    return 0;
}
