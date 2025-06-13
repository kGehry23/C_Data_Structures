/**
 ********************************************************************************
 * @file    array_queue.h
 * @author  Kai Gehry
 * @date    2025-06-07
 *
 * @brief   Defines the structure and operations on an array based queue.
 ********************************************************************************
 */

#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H

/************************************
 * INCLUDES
 ************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/************************************
 * COMPILER DIRECTIVES
 ************************************/
// Added for void* to required type conversions
#pragma GCC diagnostic ignored "-Wint-conversion"

/************************************
 * TYPEDEFS
 ************************************/

/*!
 * @brief Struct which represents an array based queue.
 */
typedef struct
{
    // Defines the number of elements allowable in the queue
    int size;
    // Index of the element at the front of the queue
    int front_index;
    // Index of the next position to add an element to
    int end_index;
    // Number of elements currently in the queue
    int num_elements;
    // Pointer to void* type which will point to the underlying array
    void **array;

} array_queue;

/************************************
 * FUNCTION PROTOTYPES
 ************************************/

/*!
 * @brief Adds an element to the end of the queue
 * @param queue Pointer to a queue
 * @param element Element to add to the queue
 * @return None
 */
void enqueue(array_queue *queue, void *element);

/*!
 * @brief Removes an item from the queue and returns its value.
 * @param queue Pointer to a linked list queue.
 * @return Removes and returns the item at the head of the queue
 */
void *dequeue(array_queue *queue);

/*!
 * @brief Returns the element at the front of the queue.
 * @param queue Pointer to a queue.
 * @return A value representing the value stored by the node at the head of queue.
 */
void *first(array_queue *queue);

/*!
 * @brief Returns the size (number of elements) in the queue.
 * @param queue Pointer to a queue.
 * @return An integer value representing the number of elements in the queue.
 */
int size(array_queue *queue);

/*!
 * @brief Returns if the queue is empty or not.
 * @param queue Pointer to a queue.
 * @return A boolean value representing if the queue is empty (1) or not empty (0).
 */
bool is_empty(array_queue *queue);

/*!
 * @brief Initializes the queue.
 * @param queue Pointer to a queue
 * @param num_elements Number of allowable elements in the queue
 * @return None
 */
void initialize_array_queue(array_queue *queue, int queue_size);

/*!
 * @brief Prints the relevant contents of the array based queue to the terminal.
 *        Can be uncommented if the element type remains constant.
 * @param list Pointer to a queue.
 * @return None
 */
void display_queue(array_queue *queue);

#endif // ARRAY_QUEUE_H
