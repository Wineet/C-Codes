/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
	typedef struct _Node{
    int data;
    struct _Node *next;
}Node;
/*Find Middle of the List*/
 int getMiddle(Node *head)
    {
        Node *slow_ptr=head;
        Node *fast_ptr=head;
        while(fast_ptr != NULL && fast_ptr->next != NULL)
        {
            fast_ptr=fast_ptr->next;
            if(fast_ptr->next ==NULL)
            {
                slow_ptr=slow_ptr->next;
                return slow_ptr->data;
            }
            fast_ptr=fast_ptr->next;
            slow_ptr=slow_ptr->next;
        }
        return slow_ptr->data;
        // Your code here
    }
	
int main()
{

    return 0;
}
