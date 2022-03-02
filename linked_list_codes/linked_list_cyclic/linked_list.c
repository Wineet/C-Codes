/*
* Author: Vinit
* Description: Dyanmic List, practice code
* Code Demonstrate Insert, create destroy, remove, find_node etc. function call for Linked list
* 
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "linked_list.h"

void main()
{
    nodePtr head1= creat_list("Node 1");
    printf("list_empty %d\n",is_list_empty(head1));
    printList(head1);
    node_data nodeData={0};
    strcpy(nodeData.node_name,"Node 2");
    printf("nodeCount %d\n",get_node_count(head1));
    insert_node(&head1,2,nodeData);

    strcpy(nodeData.node_name,"Node 3");
    printf("nodeCount %d\n",get_node_count(head1));
    insert_node(&head1,3,nodeData);

    strcpy(nodeData.node_name,"Node 4");
    printf("nodeCount %d\n",get_node_count(head1));
    insert_node(&head1,4,nodeData);

    strcpy(nodeData.node_name,"Node 5");
    printf("nodeCount %d\n",get_node_count(head1));
    insert_node(&head1,1,nodeData);

    printList(head1);
    printf("\n------------\n");
    remove_node(&head1,1);
    printList(head1);
    printf("nodeCount %d\n",get_node_count(head1));
    destroy_list(&head1);
     printList(head1);
    printf("nodeCount %d\n",get_node_count(head1));
}