/**
 ********************************************************************************
 * @file    linked_list_queue.h
 * @author  Kai Gehry
 * @date    2025-06-24
 *
 * @brief   Defines the structure and operations defined on a linked list queue
 ********************************************************************************
 */

#ifndef LINKED_LIST_QUEUE_H
#define LINKED_LIST_QUEUE_H

/************************************
 * INCLUDES
 ************************************/
#include <stdio.h>
#include <stdbool.h>
#include "../../linked_lists/singly_linked_list/singly_linked_list.h"

/************************************
 * TYPEDEFS
 ************************************/

/*!
 * @brief Struct which represents a queue.
 */
typedef struct
{
    singly_linked_list list;
} linked_list_queue;

/************************************
 * FUNCTION PROTOTYPES
 ************************************/

/*!
 * @brief Initializes the queue.
 * @param queue Pointer to a linked list queue.
 * @return None
 */
void initialize_queue(linked_list_queue *queue);

/*!
 * @brief Adds an item to the queue.
 * @param queue Pointer to a linked list queue.
 * @param value Value to add to the queue.
 * @return None
 */
void enqueue(linked_list_queue *queue, void *value);

/*!
 * @brief Removes an item from the queue and returns its value.
 * @param queue Pointer to a linked list queue.
 * @return Removes and returns the item at the head of the queue
 */
void *dequeue(linked_list_queue *queue);

/*!
 * @brief Returns the element at the front of the queue.
 * @param queue Pointer to a linked list queue.
 * @return A value representing the value stored by the node at the head of queue.
 */
void *first(linked_list_queue *queue);

/*!
 * @brief Returns the size (number of elements) in the queue.
 * @param queue Pointer to a linked list queue.
 * @return An integer value representing the number of elements in the queue.
 */
int size(linked_list_queue *queue);

/*!
 * @brief Returns if the queue is empty or not.
 * @param queue Pointer to a linked list queue.
 * @return A boolean value representing if the queue is empty (1) or not empty (0).
 */
bool is_empty(linked_list_queue *queue);

/*!
 * @brief Displays the contents of the queue.
 * @param queue Pointer to a linked list queue.
 * @return None
 */
void display_queue(linked_list_queue *queue);

/*!
 * @brief Frees the dynamically allocated memory held by the queue
 * @param queue Pointer to a linked list queue.
 * @return None
 */
void free_linked_list_queue(linked_list_queue *queue);

#endif // LINKED_LIST_QUEUE_H