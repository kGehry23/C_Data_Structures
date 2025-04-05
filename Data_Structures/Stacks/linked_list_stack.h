/**
 ********************************************************************************
 * @file    linked_list_stack.h
 * @author  Kai Gehry
 * @date    2025-03-25
 *
 * @brief   Defines the operations on a linked list stack.
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/
#include <stdio.h>
#include <stdbool.h>
#include "../Linked_Lists/Singly_Linked_List/singly_linked_list.h"

/*!
 * @brief Struct which represents a stack.
 */
typedef struct
{
    singly_linked_list list;
} linked_list_stack;

/*!
 * @brief Initializes the stack.
 * @param stack Pointer to a linked list stack.
 * @return None
 */
void initialize_stack(linked_list_stack *stack)
{
    initialize_list(&(stack->list));
}

/*!
 * @brief Adds an element to the top of the stack
 * @param stack Pointer to a linked list stack.
 * @return None
 */
void push(linked_list_stack *stack, int value)
{
    add_node_to_tail(&(stack->list), value);
}

/*!
 * @brief Displays the contents of the stack.
 * @param stack Pointer to a linked list stack.
 * @return The value held by the node at the top of the stack.
 */
int pop(linked_list_stack *stack)
{
    return remove_node(&(stack->list), (stack->list.tail)->value);
}

/*!
 * @brief Returns the element at the top of the stack.
 * @param stack Pointer to a linked list stack.
 * @return The value held by the node at the head of the stack.
 */
int peek(linked_list_stack *stack)
{
    return return_tail_element(&(stack->list));
}

/*!
 * @brief Returns the size (number of elements) in the stack.
 * @param stack Pointer to a linked list stack.
 * @return An integer value representing the number of elements in the stack.
 */
int size(linked_list_stack *stack)
{
    return list_length(&(stack->list));
}

/*!
 * @brief Returns if the stack is empty or not.
 * @param queue Pointer to a linked list stack.
 * @return A boolean value representing if the stack is empty (1) or not empty (0)
 */
bool is_empty(linked_list_stack *stack)
{
    return list_length(&(stack->list)) == 0;
}

/*!
 * @brief Displays the contents of the stack.
 * @param stack Pointer to a linked list stack.
 * @return None
 */
void display_stack(linked_list_stack *stack)
{
    display_linked_list(&(stack->list));
}
