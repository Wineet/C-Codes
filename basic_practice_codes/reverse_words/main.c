/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>
int main()
{
    char ptr[]="Hello World vinit kumar";
    int lenght=strlen(ptr);
    
    /*reverse Word and print*/
    char *ptr_trav=(char *)ptr+lenght-1;    
    while(ptr_trav != ptr)
    {
        if(*ptr_trav == ' ')
        {
            printf("%s ",(ptr_trav+1));
            *ptr_trav='\0';
        }
        ptr_trav--;
        
    }
    printf("%s ",ptr);
    return 0;
}
