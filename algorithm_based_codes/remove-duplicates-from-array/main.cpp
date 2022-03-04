/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;


int main()
{
    int arr[]={2,3,4,5,6,4,5,1,7};
    int size= sizeof(arr)/sizeof(int);
//    sort(arr,size);

    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
     int buff[10]={0};
     int prev=arr[0];
     int count=1;
     buff[0]=arr[0];
    for(int i=1;i<size;i++)
    {
        if(prev==arr[i])
        {
            prev=arr[i];
            continue;
        }
        buff[count++]=arr[i];
        prev=arr[i];
    }
    for(int i=0;i<count;i++)
    {
        cout<<" "<<buff[i];
    }
    return 0;
}
