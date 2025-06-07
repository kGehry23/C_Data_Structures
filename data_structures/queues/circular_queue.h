/**
 ********************************************************************************
 * @file    circular_queue.h
 * @author  Kai Gehry
 * @date    2025-06-02
 *
 * @brief   Defines the operations on a circular queue
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
    void **array; // Don't know why this was causing issues

} circular_queue;
// /*!
//  * @brief Adds an element to the top of the stack
//  * @param stack Pointer to a stack
//  * @param value Element to add to the stack
//  * @return None
//  */
// void push(array_stack *stack, void *value)
// {
//     if (stack->num_elements != stack->size)
//     {
//         (stack->array)[stack->stack_pointer] = value;

//         // Increment the number of elements
//         stack->num_elements++;

//         if (stack->num_elements != stack->size)
//         {
//             // Do not update stack pointer
//         }

//         // Calculate the next index where an element can be added
//         stack->stack_pointer = (stack->stack_pointer + ((stack->size) - 1)) % stack->size;
//         // Update the index indicating the element at the top of the stack
//         stack->top_index = (stack->stack_pointer) - 1;
//     }
//     else
//     {
//         printf("\nCapacity reached");
//     }
// }

// /*!
//  * @brief Removes an element from the top of the stack
//  * @param stack Pointer to stack stack
//  * @return The value at the top of the stack
//  */
// void *pop(array_stack *stack)
// {
//     // Get the element at the top of the stack
//     void *top = (stack->array)[stack->top_index];
//     // Update the pointer to the top of the stack
//     stack->top_index = (stack->top_index + 1) % stack->size;

//     if (stack->num_elements ==)
//     {
//     }

//     return top;
// }

/*!
 * @brief Initializes the queue.
 * @param circ_queue Pointer to a dropout stack stack
 * @param circ_queue_size Number of elements allowable in the stack
 * @return None
 */
void initialize_circ_queue(circular_queue *circ_queue, int circ_queue_size)
{
    circ_queue->size = circ_queue_size;
    // Initialize the top and bottom element indices of the queue to 0
    circ_queue->front_index = 0;
    // Create an array of the specified size
    circ_queue->array = (void *)malloc(circ_queue_size * sizeof(void *));
}