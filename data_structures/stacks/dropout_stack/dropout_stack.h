/**
 ********************************************************************************
 * @file    dropout_stack.h
 * @author  Kai Gehry
 * @date    2025-06-24
 *
 * @brief   Defines the structure and operations defined on a dropout stack
 ********************************************************************************
 */

#ifndef DROPOUT_STACK_H
#define DROPOUT_STACK_H

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
 * @brief Struct which represents a dropout stack.
 */
typedef struct
{
    // Defines the size limit of the dropout stack
    int stack_limit;
    singly_linked_list list;
} dropout_stack;

/************************************
 * FUNCTION PROTOTYPES
 ************************************/

/*!
 * @brief Initializes the dropout stack.
 * @param stack Pointer to a dropout stack stack.
 * @param dropout_limit Limit for the number of items to keep in the
 *                      stack. Items at the bottom of the stack are
 *                      dropped off when the limit is exceeded.
 * @return None
 */
void initialize_do_stack(dropout_stack *stack, int dropout_limit);

/*!
 * @brief Adds an element to the top of the stack
 * @param stack Pointer to a dropout stack.
 * @param value Element to push onto the stack.
 * @return None
 */
void push(dropout_stack *stack, void *value);

/*!
 * @brief Displays the contents of the dropout stack.
 * @param stack Pointer to a dropout stack.
 * @return The value held by the node at the top of the stack.
 */
void *pop(dropout_stack *stack);

/*!
 * @brief Returns the element at the top of the stack.
 * @param stack Pointer to a dropout stack.
 * @return The value held by the node at the top of the stack.
 */
void *peek(dropout_stack *stack);

/*!
 * @brief Returns the size (number of elements) in the stack.
 * @param stack Pointer to a dropout stack.
 * @return An integer value representing the number of elements in the stack.
 */
int size(dropout_stack *stack);

/*!
 * @brief Returns if the dropout stack is empty or not.
 * @param queue Pointer to a dropout stack.
 * @return A boolean value representing if the stack is empty or not
 */
bool is_empty(dropout_stack *stack);

/*!
 * @brief Displays the contents of the stack
 * @param stack Pointer to a dropout stack
 * @return None
 */
void display_do_stack(dropout_stack *stack);

/*!
 * @brief Frees the dynamically allocated memory held by the dropout stack
 * @param stack Pointer to a dropout stack
 * @return None
 */
void free_do_stack(dropout_stack *stack);

#endif // DROPOUT_STACK_H
