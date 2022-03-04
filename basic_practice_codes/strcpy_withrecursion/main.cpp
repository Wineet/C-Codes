/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

void mystrcpy1(const char *str, char *buff)
{
    static int i=0;
    if(str[i] == '\0')
    {
        return;
    }
    buff[i]=str[i];
   //  cout<<"buff[i] "<<buff[i]<<"str[i] "<<str[i]<<" i "<<i<<endl;
    i++;
    mystrcpy1(str, buff);        // can't pass mystrcpy(str+i,buff+i);  
    //Because i value is continues increasing, It will skip one char and jump to next 
    // every time
}


void mystrcpy(const char *str, char *buff)
{
    if(*str == '\0')
    {
        return;
    }
    *buff=*str;
   //  cout<<"buff[i] "<<buff[i]<<"str[i] "<<str[i]<<" i "<<i<<endl;
    mystrcpy(str+1, buff+1);
}

int main()
{
    const char *str="vinit";
    char buff[10]={0};
    mystrcpy(str,buff);
    cout<<"Hello World "<<buff<<endl;

    return 0;
}
