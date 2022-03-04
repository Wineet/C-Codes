/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;


int add(int x,int y)
{
    if(y==0)
    {
        return x;
    }
    return add(x^y, (x&y)<<1);
}


int sub(int x,int y)
{
    if(y==0)
    {
        return x;
    }
    return sub(x^y, ((~x)&y)<<1);
}

int multiply(int x,int y)
{
    int multiple=0;
    for(int i=0;i<y;i++)
    {
        multiple=add(multiple,x);
    }
    return multiple;
}

int divide(int x,int y)
{
    int division_count=0;
    if(x==0)
    {
        return -1;
    }
    while(x>=y)
    {
        x=sub(x,y);
        division_count++;
    }
    return division_count;
}


int main()
{
    
    cout<<"Hello World "<<add(4,5)<<" "<<sub(4,3)<<" "<<multiply(6,8)<<" "<<divide(6,2);

    return 0;
}
