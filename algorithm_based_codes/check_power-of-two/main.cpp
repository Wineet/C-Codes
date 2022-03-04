/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

// check weather number is mulitple of 2 or not
// if we do -1 from any 2's power number
// then all right side LSB bits become -1, we are using that property

bool check_num_is_powerof_two(int arg)
{
    if(((arg) & (arg -1) )== 0)
    {
        return true;
    }
        return false;
}
int main()
{
    printf("Hello World %d",check_num_is_powerof_two(5));

    return 0;
}
