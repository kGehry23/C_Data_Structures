/**
 ********************************************************************************
 * @file    array_queue.h
 * @author  Kai Gehry
 * @date    2025-06-03
 *
 * @brief   Defines the operations on an array based queue.
 ********************************************************************************
 */

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
    //  Pointer to void* type which will point to the underlying array
    void **array;

} array_queue;

/*!
 * @brief Adds an element to the end of the queue
 * @param queue Pointer to a queue
 * @param element Element to add to the queue
 * @return None
 */
void enqueue(array_queue *queue, void *element)
{
}

/*!
 * @brief Removes an item from the queue and returns its value.
 * @param queue Pointer to a linked list queue.
 * @return Removes and returns the item at the head of the queue
 */
void *dequeue(array_queue *queue)
{
    void *removed_element = (queue->array)[queue->front_index];

    (queue->array)[queue->front_index] = NULL;

    queue->front_index = queue->front_index + 1;

    queue->num_elements = queue->num_elements - 1;

    return removed_element;
}

/*!
 * @brief Returns the element at the front of the queue.
 * @param queue Pointer to a queue.
 * @return A value representing the value stored by the node at the head of queue.
 */
void *first(array_queue *queue)
{
    return (queue->array)[queue->front_index];
}

/*!
 * @brief Returns the size (number of elements) in the queue.
 * @param queue Pointer to a queue.
 * @return An integer value representing the number of elements in the queue.
 */
int size(array_queue *queue)
{
    return (queue->num_elements);
}

/*!
 * @brief Returns if the queue is empty or not.
 * @param queue Pointer to a queue.
 * @return A boolean value representing if the queue is empty (1) or not empty (0).
 */
bool is_empty(array_queue *queue)
{
    return (queue->num_elements) == 0;
}

/*!
 * @brief Initializes the queue.
 * @param queue Pointer to a queue
 * @param num_elements Number of allowable elements in the queue
 * @return None
 */
void initialize_array_queue(array_queue *queue, int queue_size)
{
    // Defines the number of allowable elements in the array
    queue->size = queue_size;
    // Set the initial top and bottom indices to 0
    queue->front_index = 0;
    queue->end_index = 0;
    queue->num_elements = 0;

    //  Create an array of the specified size
    queue->array = (void *)malloc(queue_size * sizeof(void *));
}