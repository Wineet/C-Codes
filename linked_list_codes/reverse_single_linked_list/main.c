/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
/* Basic linked list code for all experiments */
typedef struct _node{
    int data;
    struct _node *next;
}node;

/* Get to the Last Node */
node *get_to_last_node(node *head)
{
    while(head->next != NULL && head != NULL )
    {
        head=head->next;
    }
    return head;
}

/* Print Link list */
void print_linked_list(node *head)
{
    printf("print list ");
    while( head != NULL )
    {
        printf(" %d",head->data);
        head=head->next;
    }
     printf("\n");
}

/* Add Node to the End 
   return address of added node
 */

node *add_node(node *head,int data)
{
    if(head == NULL)
    {
        node *head =(node *) malloc(sizeof(node)*1);
        if(head == NULL)
        {
            printf("Unable to allocate Dynamic Memory \n");
            return NULL;
        }
        memset(head,0,sizeof(node));
        head->data=data;
        head->next=NULL;
        return head;
    }
    else
    {

        head=get_to_last_node(head);
        node *last_node =(node *) malloc(sizeof(node)*1);
        if(last_node == NULL)
        {
            printf("Unable to allocate Dynamic Memory \n");
            return NULL;
        }
        memset(last_node,0,sizeof(sizeof(last_node)));
        last_node->data=data;
        last_node->next=NULL;
        head->next=last_node;
        return last_node; 
    }
}

/*reverse linked list and return Head pointer */
node *reverse_linked_list(node *head)
{
    node *prev=NULL;
    node *current=head;
    node * next= NULL;
    while(current != NULL)
    {
        next=current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
int main()
{
    node *head=NULL;
    head=add_node(head,1);
    add_node(head,2);
    add_node(head,3);
    add_node(head,4);
    add_node(head,5);
    print_linked_list(head);
    head=reverse_linked_list(head);
    print_linked_list(head);
    return 0;
}
