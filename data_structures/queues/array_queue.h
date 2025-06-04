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
    // If space is at the front of the queue, as elements have been added and removed
    if (queue->end_index == queue->size - 1 && queue->front_index != 0)
    {
        // Reference for the index to shift backwards
        int index_ref = queue->front_index;

        // Shifts all elements
        for (int i = 0; i < queue->num_elements; i++)
        {
            (queue->array)[i] = (queue->array)[index_ref];
            index_ref = index_ref + 1;
        }

        // Add the new element
        (queue->array)[index_ref] = element;
        // Update the element count
        queue->num_elements = queue->num_elements + 1;

        // If the end index does not currently equal the index of the element at the end of the queue
        if (index_ref + 1 <= queue->size - 1)
        {
            // Update the index for where a new element should be added
            queue->end_index = index_ref + 1;
        }
        else
        {
            // If the updated index wil be greater than the last element index, we keep the index the same
            queue->end_index = index_ref;
        }
    }

    // Need to be more concrete here with these cases
    else if (queue->num_elements == queue->size)
    {
        printf("\nCapacity Reached");
    }
    else
    {
        (queue->array)[queue->front_index] = element;
        queue->end_index = queue->end_index + 1;

        queue->size = queue->size + 1;
    }
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