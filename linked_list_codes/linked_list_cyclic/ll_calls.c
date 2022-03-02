
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include "ll_calls.h"
/**
 *  function Name: creat_list
 *  Arg: char *
 *  function Description:
 *  Creates a Head of List and return Head pointer
*/
nodePtr creat_list(char *head_data)
{
    nodePtr head_ptr=NULL;
    head_ptr=(nodePtr)malloc(sizeof(node));
    if(head_ptr==NULL)
    {
        return NULL;
    }
    memset(head_ptr,0,sizeof(node));
    if(head_data != NULL);
    {
        memcpy(head_ptr->data.node_name,head_data,MAX_NODE_NAME-1);
    }
    head_ptr->nextPtr=NULL;
    head_ptr->prevPtr=NULL;
    return head_ptr;
}

bool is_list_empty(nodePtr head)
{
    if (head == NULL)
    {
        return false;
    }
    else if(head->nextPtr != NULL)
    {
        return false;
    }
    return true;
}

void printList(nodePtr head)
{
    int node_no=0;
    if(head == NULL)
    {
        return;
    }
    while(head != NULL)
    {
        printf("Node No= %d, Data = %s \n",node_no++,head->data.node_name);
        head=head->nextPtr;
    }
}

void insert_node(nodePtr *head_ptr,int pos,node_data node)
{

    if(get_node_count(*head_ptr)+1 < pos || pos == 0)
    {
        perror("Invalid Position or List is short\n");
        return;
    }
    nodePtr newNode = creat_node(node);
    if(newNode == NULL)
    {
        perror("create Node Failed \n");
        return;
    }
    if(pos==1)
    {
        newNode->nextPtr=*head_ptr;
        *head_ptr = newNode;
            /*Head replacement*/        
    }
    else
    {
        nodePtr prev = get_node(*head_ptr,pos-1);
        newNode->nextPtr = prev->nextPtr;
        prev->nextPtr=newNode;
    }
}

nodePtr creat_node(node_data data)
{
        nodePtr newNode=(nodePtr)malloc(sizeof(node));
        if( newNode ==NULL)
        {
            return NULL;
        }
        memset(newNode,0,sizeof(node));
        memcpy(&newNode->data,&data,sizeof(node_data));
        newNode->nextPtr =NULL;
        return newNode;
}
nodePtr get_node(nodePtr head,int pos)
{
    int count=1;
    while( (head != NULL )&& (count++ != pos )&&  (head=head->nextPtr) );
    return head;
}

int get_node_count(nodePtr head)
{
    /* Need to write below code in good Manner*/
    int count=1;
    if(head==NULL)
    {
        return 0;
    }
    while( (head != NULL )&& (head=head->nextPtr) )
    {
        count++;
    }
    return count;
}


void remove_node(nodePtr *head_ptr,int pos)
{
    
    if(get_node_count(*head_ptr)<pos)
    {
        perror("invalid pos");
        return;
    }
    if(pos == 1)
    {
        nodePtr temphead=*head_ptr;
        *head_ptr=temphead->nextPtr;
        temphead->nextPtr=NULL;
        free(temphead);
        /*Head Replacement*/
    }
    else
    {
        nodePtr prevNode= get_node(*head_ptr,pos-1);
        nodePtr delNode= prevNode->nextPtr;
        prevNode->nextPtr=prevNode->nextPtr->nextPtr;
        free(delNode);
    }
    
}

void destroy_list(nodePtr *head)
{
    int count = get_node_count(*head);
    for(int i=0;i<count;i++)
    {
        printf(".");
        remove_node(head,1);
    }
    *head=NULL;
}