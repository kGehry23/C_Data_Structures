/**
 ********************************************************************************
 * @file    circular_queue.h
 * @author  Kai Gehry
 * @date    2025-06-02
 *
 * @brief   Defines the structure and operations defined on a circular queue.
 ********************************************************************************
 */

#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

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
 * @brief Struct which represents a circular queue.
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

} circular_queue;

/************************************
 * FUNCTION PROTOTYPES
 ************************************/

/*!
 * @brief Adds an element to the end of the circular queue
 * @param circ_queue Pointer to a circular queue
 * @param element Element to add to the circular queue
 * @return None
 */
void enqueue(circular_queue *circ_queue, void *element);

/*!
 * @brief Removes an item from the circular queue and returns its value.
 * @param circ_queue Pointer to a circular queue.
 * @return Removes and returns the item at the head of the circular queue
 */
void *dequeue(circular_queue *circ_queue);

/*!
 * @brief Returns the element at the front of the circular queue.
 * @param circ_queue Pointer to a circular queue.
 * @return A value representing the value stored by the node at the head of circular queue.
 */
void *first(circular_queue *circ_queue);

/*!
 * @brief Returns the size (number of elements) in the circular queue.
 * @param circ_queue Pointer to a circular queue.
 * @return An integer value representing the number of elements in the circular queue.
 */
int size(circular_queue *circ_queue);

/*!
 * @brief Returns if the circular queue is empty or not.
 * @param circ_queue Pointer to a circular queue.
 * @return A boolean value representing if the circular queue is empty (1) or not empty (0).
 */
bool is_empty(circular_queue *circ_queue);

/*!
 * @brief Initializes the circular queue.
 * @param circ_queue Pointer to a circular queue
 * @param num_elements Number of allowable elements in the circular queue
 * @return None
 */
void initialize_circular_queue(circular_queue *circ_queue, int queue_size);

/*!
 * @brief Prints the relevant contents of the circular queue to the terminal.
 * @param list Pointer to a circular queue.
 * @return None
 */
void display_circular_queue(circular_queue *queue);

/*!
 * @brief Frees the dynamically allocated memory held by the circular queue
 * @param list Pointer to a circular queue.
 * @return None
 */
void free_circular_queue(circular_queue *queue);

#endif // CIRCULAR_QUEUE_H