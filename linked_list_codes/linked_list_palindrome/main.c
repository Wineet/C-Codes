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
#include <stdbool.h>

/* Basic linked list code for all experiments */
struct _node{
    int data;
    struct _node *next;
};
typedef struct _node node;
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

/* delete Linked List*/
void delete_list(node *head)
{
    if(head == NULL)
    {
        return;
    }
    delete_list(head->next);
    free(head);
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
/*add nodes at front and changes head*/
node *add_node_at_front(node *head,int data)
{
     node *new_head =NULL;
    if(1)
    {
        new_head =(node *) malloc(sizeof(node)*1);
        if(new_head == NULL)
        {
            printf("Unable to allocate Dynamic Memory \n");
            return NULL;
        }
        memset(new_head,0,sizeof(node));
        new_head->data=data;
        new_head->next=head;
    }
    return new_head;
    
}

/*reverse linked list and return Head pointer */
 bool check_palindrome_list(node * head)
 {
    node *rev_head = NULL;
    node *slow_ptr = head;
    node *fast_ptr = head;
    rev_head=add_node_at_front(rev_head,slow_ptr->data);
    while(fast_ptr->next != NULL && fast_ptr->next->next != NULL)
    {
        slow_ptr=slow_ptr->next;
        fast_ptr=fast_ptr->next->next;
        rev_head=add_node_at_front(rev_head,slow_ptr->data);
    }
    if(fast_ptr->next != NULL)
    {
         slow_ptr=slow_ptr->next;
    }
    while(slow_ptr)
    {
        if(slow_ptr->data != rev_head->data)
        {
          delete_list(rev_head);
            return false;
        }
        slow_ptr=slow_ptr->next;
        rev_head=rev_head->next;
    }
     return true;
 }
int main()
{
    node *head=NULL;
    head=add_node(head,1);
    add_node(head,2);
    add_node(head,1);
    add_node(head,2);
    add_node(head,1);
    printf("Palindrome %d",check_palindrome_list(head));

    return 0;
}
