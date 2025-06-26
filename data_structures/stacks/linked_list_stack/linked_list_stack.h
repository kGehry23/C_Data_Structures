/**
 ********************************************************************************
 * @file    linked_list_stack.h
 * @author  Kai Gehry
 * @date    2025-06-24
 *
 * @brief   Defines the structure and operations defined on a linked list stack
 ********************************************************************************
 */

#ifndef LINKED_LIST_STACK_H
#define LINKED_LIST_STACK_H

/************************************
 * INCLUDES
 ************************************/
#include <stdio.h>
#include <stdbool.h>
#include "../../linked_lists/singly_linked_list/singly_linked_list.h"

/************************************
 * COMPILER DIRECTIVES
 ************************************/
// Added for void* to required type conversions
#pragma GCC diagnostic ignored "-Wint-conversion"

/************************************
 * TYPEDEFS
 ************************************/

/*!
 * @brief Struct which represents a stack.
 */
typedef struct
{
    singly_linked_list list;
} linked_list_stack;

/************************************
 * FUNCTION PROTOTYPES
 ************************************/

/*!
 * @brief Initializes the stack.
 * @param stack Pointer to a linked list stack.
 * @return None
 */
void initialize_stack(linked_list_stack *stack);

/*!
 * @brief Adds an element to the top of the stack
 * @param stack Pointer to a linked list stack.
 * @param value Element to push onto the stack.
 * @return None
 */
void push(linked_list_stack *stack, void *value);

/*!
 * @brief Displays the contents of the stack.
 * @param stack Pointer to a linked list stack.
 * @return The value held by the node at the top of the stack.
 */
int pop(linked_list_stack *stack);

/*!
 * @brief Returns the element at the top of the stack.
 * @param stack Pointer to a linked list stack.
 * @return The value held by the node at the head of the stack.
 */
void *peek(linked_list_stack *stack);

/*!
 * @brief Returns the size (number of elements) in the stack.
 * @param stack Pointer to a linked list stack.
 * @return An integer value representing the number of elements in the stack.
 */
int size(linked_list_stack *stack);

/*!
 * @brief Returns if the stack is empty or not.
 * @param queue Pointer to a linked list stack.
 * @return A boolean value representing if the stack is empty (1) or not empty (0)
 */
bool is_empty(linked_list_stack *stack);

/*!
 * @brief Displays the contents of the stack
 * @param stack Pointer to a linked list stack
 * @return None
 */
void display_stack(linked_list_stack *stack);

/*!
 * @brief Frees the dynamically allocated memory held by the linked list stack
 * @param stack Pointer to a linked list stack
 * @return None
 */
void free_linked_list_stack(linked_list_stack *stack);

#endif // LINKED_LIST_STACK_H