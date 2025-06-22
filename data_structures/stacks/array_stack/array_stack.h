/**
 ********************************************************************************
 * @file    array_stack.h
 * @author  Kai Gehry
 * @date    2025-06-02
 *
 * @brief   Defines the structure and operations defined on an array-based stack
 ********************************************************************************
 */

#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

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
    //  Pointer to a void* type which will point to the underlying array
    void **array;

} array_stack;

/************************************
 * FUNCTION PROTOTYPES
 ************************************/

/*!
 * @brief Adds an element to the top of the stack
 * @param stack Pointer to a stack
 * @param element Element to add to the stack
 * @return None
 */
void push(array_stack *stack, void *element);

/*!
 * @brief Returns and removes the element at the top of the stack
 * @param stack Pointer to a stack
 * @return The element at the top of the stack
 */
void *pop(array_stack *stack);

/*!
 * @brief Returns but does not remove the element at the top of the stack
 * @param stack Pointer to a stack
 * @return Element at the top of the stack
 */
void *peek(array_stack *stack);

/*!
 * @brief Returns the size (number of elements) in the stack.
 * @param stack Pointer to a stack.
 * @return An integer value representing the number of elements in the stack.
 */
int size(array_stack *stack);

/*!
 * @brief Returns if the stack is empty or not.
 * @param queue Pointer to a stack.
 * @return A boolean value representing if the stack is empty (1) or not empty (0)
 */
bool is_empty(array_stack *stack);

/*!
 * @brief Initializes the stack.
 * @param stack Pointer to a stack
 * @param num_elements Number of allowable elements in the stack
 * @return None
 */
void initialize_array_stack(array_stack *stack, int stack_size);

/*!
 * @brief Prints the contents of the array based stack to the terminal. Can be
 *        uncommented if the type of the element to be stored remains constant.
 * @param stack Pointer to a stack
 * @return None
 */
void display_stack(array_stack *stack);

/*!
 * @brief Frees the memory dynamically allocated for the stack
 * @param stack Pointer to a stack
 * @return None
 */
void free_array_stack(array_stack *stack);

#endif // ARRAY_STACK_H