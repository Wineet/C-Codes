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
/*Get nth Node From Last*/
//Function to find the data of nth node from the end of a linked list.
int getNthFromLast(struct Node *head, int n)
{
    struct Node *front_node=head;
    struct Node *current_node=head;
    n=n-1;
    while(n--)
    {
        if(front_node->next == NULL)
        {
            return -1;
        }
        front_node=front_node->next;
    }
    
    while(front_node->next)
    {
        front_node=front_node->next;
        current_node=current_node->next;
    }
    return current_node->data;
}
int main()
{
    return 0;
}
