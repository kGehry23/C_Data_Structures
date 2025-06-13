/**
 ********************************************************************************
 * @file    doubly_linked_list.h
 * @author  Kai Gehry
 * @date    2025-04-05
 *
 * @brief   Defines the stucture of a doubly linked list and the functions
 *          defined on it.
 ********************************************************************************
 */

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

/************************************
 * INCLUDES
 ************************************/
#include <stdio.h>
#include <stdlib.h>

/************************************
 * COMPILER DIRECTIVES
 ************************************/
// Added for void* to required type conversions
#pragma GCC diagnostic ignored "-Wint-conversion"

/*!
 * @brief Struct representing a doubly linked list node.
 */
typedef struct doubly_linked_list_node
{
    // Value held by the node
    void *value;
    // Pointer to the previous node in the doubly linked list
    struct doubly_linked_list_node *previous;
    // Pointer to the next node in the doubly linked list
    struct doubly_linked_list_node *next;
} doubly_linked_list_node;

/*!
 * @brief   Struct representing a doubly linked list.
 */
typedef struct
{
    // Pointer to the element at the head of the doubly linked list
    doubly_linked_list_node *head;
    // Pointer to the element at the tail of the doubly linked list
    doubly_linked_list_node *tail;
    // Size of the doubly linked list
    int list_size;
} doubly_linked_list;

/*!
 * @brief   Initializes a doubly linked list type by setting its list_size variable to 0.
 * @param list  Pointer to the doubly linked list being initalized.
 * @return  None
 */
void initialize_dl_list(doubly_linked_list *list);

/*!
 * @brief Returns the element at the tail of the doubly linked list.
 * @param list Pointer to a doubly linked list struct.
 * @return The value held at the tail of the doubly linked list.
 */
void *return_dl_tail(doubly_linked_list *list);

/*!
 * @brief Returns the element at the head of the doubly linked list.
 * @param list Pointer to a doubly linked list.
 * @return The value held at the head of the doubly linked list.
 */
void *return_dl_head(doubly_linked_list *list);

/*!
 * @brief Returns the length of the doubly linked list.
 * @param list Pointer to a doubly linked list struct.
 * @return An integer representing the size of the linked list.
 */
int dl_list_length(doubly_linked_list *list);

/*!
 * @brief Adds a node to the front of the doubly linked list.
 * @param list Pointer to a doubly linked list struct.
 * @param insert_value Value to insert at the head of the list.
 * @return None
 */
void add_dl_node_to_head(doubly_linked_list *list, void *insert_value);

/*!
 * @brief Adds a node to the the end of the doubly linked list.
 * @param list Pointer to a doubly linked list struct.
 * @param insert_value Value to insert at the tail of the list.
 * @return None
 */
void add_dl_node_to_tail(doubly_linked_list *list, void *insert_value);

/*!
 * @brief Adds a node to a position after a specified node.
 * @param list Pointer to a doubly linked list struct.
 * @param insert_value Value to insert into the list.
 * @param insert_after_value The value of the element to insert an element after.
 * @return None
 */
void insert_dl_node(doubly_linked_list *list, int insert_value, void *insert_after_value);

/*!
 * @brief Removes and returns the value of an element.
 * @param list Pointer to a doubly linked list struct.
 * @param removal_value Value to remove from the list.
 * @return The value of the element to be removed.
 */
void *remove_dl_node(doubly_linked_list *list, void *removal_value);

#endif
