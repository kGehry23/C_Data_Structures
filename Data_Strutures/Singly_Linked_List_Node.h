/**
 ********************************************************************************
 * @file    Singly_Linked_List_Test.c
 * @author  Kai Gehry
 * @date    2025-03-25
 * @brief
 ********************************************************************************
 */

#include <stdio.h>

/*
    Struct which represents a node in a singly linked list.
*/
typedef struct
{
    // Value held by the node
    int value;
    // pointer to the next node in the singly linked list
    Singly_Linked_List_Node *next;
} Singly_Linked_List_Node;
