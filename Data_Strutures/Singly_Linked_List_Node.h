/**
 ********************************************************************************
 * @file    singly_linked_list_node.h
 * @author  Kai Gehry
 * @date    2025-03-25
 * @brief   Defines a singly linked list node.
 ********************************************************************************
 */

#include <stdio.h>

/*!
 * @brief Struct representing a singly linked list node.
 */
typedef struct singly_linked_list_node
{
    // Value held by the node
    int value;
    // pointer to the next node in the singly linked list
    struct singly_linked_list_node *next;
} singly_linked_list_node;
