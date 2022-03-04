/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int gcd(int x,int y)
{
    if(y==0)
    {
        return x;
    }
    return gcd(y,x%y);    
    
}

int find_gcd_of_arr(int *arr,int size)
{
    int ans=arr[0];
    for(int i=0;i<size;i++)
    {
        ans=gcd(ans,arr[i]);
    }
    return ans;
}


int lcm(int x,int y)
{
    return (x*y)/gcd(x,y);
}

int find_lcm_of_arr(int *arr,int size)
{
    int ans=arr[0];
    for(int i=0;i<size;i++)
    {
        ans=lcm(ans,arr[i]);
    }
    return ans;
}

int main()
{
    int arr[]={1};
    int arr2[]={100};
    int size= sizeof(arr)/sizeof(int);
    int size2= sizeof(arr2)/sizeof(int);
    int ans = 0;
    cout<<"Array GCD "<<find_gcd_of_arr(arr2,size)<<endl;
    cout<<"Array LCM "<<find_lcm_of_arr(arr,size)<<endl;

    return 0;
}
