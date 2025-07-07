/**
 ********************************************************************************
 * @file    linked_list_queue.c
 * @author  Kai Gehry
 * @date    2025-03-26
 *
 * @brief   Defines the operations on a linked list queue.
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/
#include "linked_list_queue.h"

/************************************
 * FUNCTION DEFINITIONS
 ************************************/

/*!
 * @brief Initializes the queue.
 * @param queue Pointer to a linked list queue.
 * @return None
 */
void initialize_queue(linked_list_queue *queue)
{
    initialize_sl_list(&(queue->list));
}

/*!
 * @brief Adds an item to the queue.
 * @param queue Pointer to a linked list queue.
 * @param value Value to add to the queue.
 * @return None
 */
void enqueue(linked_list_queue *queue, void *value)
{
    add_sl_node_to_tail(&(queue->list), value);
}

/*!
 * @brief Removes an item from the queue and returns its value.
 * @param queue Pointer to a linked list queue.
 * @return Removes and returns the item at the head of the queue
 */
void *dequeue(linked_list_queue *queue)
{
    return remove_sl_node(&(queue->list), ((queue->list).head)->value);
}

/*!
 * @brief Returns the element at the front of the queue.
 * @param queue Pointer to a linked list queue.
 * @return A value representing the value stored by the node at the head of queue.
 */
void *first(linked_list_queue *queue)
{
    return return_sl_head(&(queue->list));
}

/*!
 * @brief Returns the size (number of elements) in the queue.
 * @param queue Pointer to a linked list queue.
 * @return An integer value representing the number of elements in the queue.
 */
int size(linked_list_queue *queue)
{
    return sl_list_length(&(queue->list));
}

/*!
 * @brief Returns if the queue is empty or not.
 * @param queue Pointer to a linked list queue.
 * @return A boolean value representing if the queue is empty (1) or not empty (0).
 */
bool is_empty(linked_list_queue *queue)
{
    return sl_list_length(&(queue->list)) == 0;
}

/*!
 * @brief Frees the dynamically allocated memory held by the queue
 * @param queue Pointer to a linked list queue.
 * @return None
 */
void free_linked_list_queue(linked_list_queue *queue)
{
    free_singly_linked_list(&(queue->list));
}

// /*!
//  * @brief Displays the contents of the queue.
//  * @param queue Pointer to a linked list queue.
//  * @return None
//  */
// void display_queue(linked_list_queue *queue)
// {
//     display_sl_list(&(queue->list));
// }
