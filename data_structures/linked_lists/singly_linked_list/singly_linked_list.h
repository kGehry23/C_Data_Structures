/**
 ********************************************************************************
 * @file    singly_linked_list.h
 * @author  Kai Gehry
 * @date    2025-03-25
 *
 * @brief   Defines the structure of a singly linked list and the functions
 *          defined on it.
 ********************************************************************************
 */

#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

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

/************************************
 * FUNCTION PROTOTYPES
 ************************************/

/*!
 * @brief Struct representing a singly linked list node.
 */
typedef struct singly_linked_list_node
{
    // Value held by the node
    void *value;
    // Pointer to the next node in the singly linked list
    struct singly_linked_list_node *next;
} singly_linked_list_node;

/*!
 * @brief   Struct representing a singly linked list.
 */
typedef struct singly_linked_list
{
    singly_linked_list_node *head;
    singly_linked_list_node *tail;
    int list_size;
} singly_linked_list;

/*!
 * @brief Initializes a singly linked list type by setting its list_size variable to 0.
 * @param list  Pointer to the singly linked list being initalized.
 * @return  None
 */
void initialize_sl_list(singly_linked_list *list);

/*!
 * @brief Returns the element at the tail of the singly linked list.
 * @param list Pointer to a singly linked list struct.
 * @return The value held at the tail of the linked list.
 */
void *return_sl_tail(singly_linked_list *list);

/*!
 * @brief Returns the element at the head of the singly linked list.
 * @param list Pointer to a singly linked list struct.
 * @return The value held at the head of the linked list.
 */
void *return_sl_head(singly_linked_list *list);

/*!
 * @brief Returns the length of the singly linked list.
 * @param list Pointer to a singly linked list struct.
 * @return An integer representing the size of the linked list.
 */
int sl_list_length(singly_linked_list *list);

/*!
 * @brief Adds a node to the front of the singly linked list.
 * @param list Pointer to a singly linked list struct.
 * @param insert_value Value to insert at the head of the list.
 * @return None
 */
void add_sl_node_to_head(singly_linked_list *list, void *insert_value);

/*!
 * @brief Adds a node to the the end of the singly linked list.
 * @param list Pointer to a singly linked list struct.
 * @param insert_value Value to insert at the tail of the list.
 * @return None
 */
void add_sl_node_to_tail(singly_linked_list *list, void *insert_value);

/*!
 * @brief Adds a node to a position after a specified node.
 * @param list Pointer to a singly linked list struct.
 * @param insert_value Value to insert into the list.
 * @param insert_after_value The value of the element to insert an element after.
 * @return None
 */
void insert_sl_node(singly_linked_list *list, int insert_value, void *insert_after_value);

/*!
 * @brief Removes and returns the value of an element.
 * @param list Pointer to a singly linked list struct.
 * @param removal_value Value to remove from the list.
 * @return The value of the element to be removed.
 */
void *remove_sl_node(singly_linked_list *list, void *removal_value);

/*!
 * @brief Frees the memory held by a singly linked list struct
 * @param list Pointer to a singly linked list struct
 * @return None
 */
void free_singly_linked_list(singly_linked_list *list);

#endif // SINGLY_LINKED_LIST_H