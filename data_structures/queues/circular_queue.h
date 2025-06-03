/**
 ********************************************************************************
 * @file    array_stack.h
 * @author  Kai Gehry
 * @date    2025-06-02
 *
 * @brief   Defines the operations on an array based stack.
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
 * @brief Struct which represents an array based stack.
 */
typedef struct
{
    // Defines the number of elements allowable in the stack
    int size;
    // Integer index indicating the top of the stack
    int top_index;
    // Integer indicating the next index at the top of the stack
    int stack_pointer;
    // Number of elements currently in the stack
    int num_elements;
    //  Integer pointer to an array
    int *array;

} array_stack;

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

// void display_array_stack(array_stack *stack)
// {

//     for (int i = 0; i < stack->size; i++)
//     {
//         printf("%d\n", (&(stack->array))[i]);
//     }
// }

/*!
 * @brief Initializes the stack.
 * @param stack Pointer to a dropout stack stack
 * @param num_elements Number of elements allowable in the stack
 * @return None
 */
void initialize_array_stack(array_stack *stack, int size)
{
    stack->size = size;
    // Initialize the top and bottom element indices of the stack to 0
    stack->top_index = 0;
    // Create an array of the specified size
    stack->array = (int *)malloc(size * sizeof(int *));
}