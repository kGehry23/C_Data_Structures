/**
 ********************************************************************************
 * @file    Singly_Linked_List_Node.
 * @author  Kai Gehry
 * @date    2025-03-25
 * @brief
 ********************************************************************************
 */

#include <stdio.h>

/*
    Struct which represents a node in a singly linked list.
*/
typedef struct singly_linked_list_node
{
    // Value held by the node
    int value;
    // pointer to the next node in the singly linked list
    struct singly_linked_list_node *next;
} singly_linked_list_node;
