/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

/*count number of 1's in the number*/
int number_of_one(int x)
{
    int count=0;
    while(x!=0)
    {
        x & 0x01 ? count++:0;
        x=x>>1;
    }
    return count;
}


int main()
{
    int x=123;
    
    cout<<"1's = "<<number_of_one(x);
    return 0;
}
