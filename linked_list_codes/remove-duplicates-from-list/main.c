/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
/*Remove Duplicates From list Function call*/
void removeDuplicates(struct Node* head)
{
    while(head && head->next)
    {
            if(head->data == head->next->data)
            {
                struct Node *temp =head->next;
                head->next=head->next->next;
                free(temp);
            }
            else{
                head=head->next;
            }
    }
    
}

int main()
{

    return 0;
}
