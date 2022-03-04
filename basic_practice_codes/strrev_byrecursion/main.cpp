/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

void my_strrev(const char *src,char *dest)
{
    static int i=0;
    if(*src == '\0')
    {
        return;
    }
    my_strrev(src+1,dest);
    dest[i]=*src;
    i++;
    
}

int main()
{
    const char *src="Vinit";
    char buff[10]={0};
    my_strrev(src,buff);
    cout<<"buff "<<buff<<endl;
    return 0;
}
