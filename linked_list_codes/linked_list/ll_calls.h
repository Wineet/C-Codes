
#ifndef _LL_CALLS_H_
#define _LL_CALLS_H_
#define MAX_NODE_NAME 10

#include<stdbool.h>
typedef struct _node *nodePtr;

typedef struct _node_data{
    char node_name[MAX_NODE_NAME];
}node_data;

typedef struct _node
{
    node_data data;
    struct _node *nextPtr;
}node;

nodePtr creat_list(char *head_data);
bool is_list_empty(nodePtr head);
void printList(nodePtr head);
void insert_node(nodePtr *head_ptr,int pos,node_data node);
void remove_node(nodePtr *head_ptr,int pos);
nodePtr creat_node(node_data data);
nodePtr get_node(nodePtr head,int pos);
int get_node_count(nodePtr head);
int get_node_count(nodePtr head);
void destroy_list(nodePtr *head);

#endif