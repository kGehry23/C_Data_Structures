/**
 ********************************************************************************
 * @file    linked_list_queue.h
 * @author  Kai Gehry
 * @date    2025-03-26
 *
 * @brief   Defines the operations on a linked list queue.
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/
#include <stdio.h>
#include <stdbool.h>
#include "../Linked_Lists/singly_linked_list.h"

/*!
 * @brief Struct which represents a queue.
 */
typedef struct
{
    singly_linked_list list;
} linked_list_queue;

/*!
 * @brief Initializes the queue.
 * @param queue Pointer to a linked list queue.
 * @return None
 */
void initialize_queue(linked_list_queue *queue)
{
    initialize_list(&(queue->list));
}

/*!
 * @brief Adds an item to the queue.
 * @param queue Pointer to a linked list queue.
 * @param value Value to add to the queue.
 * @return None
 */
void enqueue(linked_list_queue *queue, int value)
{
    add_node_to_tail(&(queue->list), value);
}

/*!
 * @brief Removes an item from the queue and returns its value.
 * @param queue Pointer to a linked list queue.
 * @return Removes and returns the item at the head of the queue
 */
int dequeue(linked_list_queue *queue)
{
    return remove_node(&(queue->list), ((queue->list).head)->value);
}

/*!
 * @brief Returns the element at the front of the queue.
 * @param queue Pointer to a linked list queue.
 * @return A value representing the value stored by the node at the head of queue.
 */
int first(linked_list_queue *queue)
{
    return return_head_element(&(queue->list));
}

/*!
 * @brief Returns the size (number of elements) in the queue.
 * @param queue Pointer to a linked list queue.
 * @return An integer value representing the number of elements in the queue.
 */
int size(linked_list_queue *queue)
{
    return list_length(&(queue->list));
}

/*!
 * @brief Returns if the queue is empty or not.
 * @param queue Pointer to a linked list queue.
 * @return A boolean value representing if the queue is empty (1) or not empty (0)
 */
bool is_empty(linked_list_queue *queue)
{
    return list_length(&(queue->list)) == 0;
}

/*!
 * @brief Displays the contents of the queue.
 * @param queue Pointer to a linked list queue.
 * @return None
 */
void display_queue(linked_list_queue *queue)
{
    display_linked_list(&(queue->list));
}
