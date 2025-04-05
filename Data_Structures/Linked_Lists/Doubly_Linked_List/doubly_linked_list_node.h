/**
 ********************************************************************************
 * @file    doubly_linked_list_node.h
 * @author  Kai Gehry
 * @date    2025-04-05
 *
 * @brief   Defines a doubly linked list node.
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/
#include <stdio.h>

/*!
 * @brief Struct representing a doubly linked list node.
 */
typedef struct doubly_linked_list_node
{
    // Value held by the node
    int value;
    // Pointer to the previous node in the doubly linked list
    struct doubly_linked_list_node *previous;
    // Pointer to the next node in the doubly linked list
    struct doubly_linked_list_node *next;
} doubly_linked_list_node;
