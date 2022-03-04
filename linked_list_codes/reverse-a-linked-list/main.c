/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

	struct Node{
    int data;
    struct Node *next;
};
/* Reverse a Linked List */
struct Node* reverseList(struct Node *head)
    {
        struct Node *current=head;
        struct Node *prev=NULL;
        struct Node *next=NULL;
        while(current != NULL)
        {
            struct Node *buff=current->next;
            current->next=prev;
            prev=current;
            current=buff;
        }
        return prev;
    }
    

int main()
{
    printf("Hello World");

    return 0;
}
