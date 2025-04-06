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
#include "../linked_lists/singly_linked_list/singly_linked_list.h"

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
    initialize_sl_list(&(stack->list));
}

/*!
 * @brief Adds an element to the top of the stack
 * @param stack Pointer to a linked list stack.
 * @param value Element to push onto the stack.
 * @return None
 */
void push(linked_list_stack *stack, int value)
{
    add_sl_node_to_head(&(stack->list), value);
}

/*!
 * @brief Displays the contents of the stack.
 * @param stack Pointer to a linked list stack.
 * @return The value held by the node at the top of the stack.
 */
int pop(linked_list_stack *stack)
{
    return remove_sl_node(&(stack->list), (stack->list.head)->value);
}

/*!
 * @brief Returns the element at the top of the stack.
 * @param stack Pointer to a linked list stack.
 * @return The value held by the node at the head of the stack.
 */
int peek(linked_list_stack *stack)
{
    return return_sl_head(&(stack->list));
}

/*!
 * @brief Returns the size (number of elements) in the stack.
 * @param stack Pointer to a linked list stack.
 * @return An integer value representing the number of elements in the stack.
 */
int size(linked_list_stack *stack)
{
    return sl_list_length(&(stack->list));
}

/*!
 * @brief Returns if the stack is empty or not.
 * @param queue Pointer to a linked list stack.
 * @return A boolean value representing if the stack is empty (1) or not empty (0)
 */
bool is_empty(linked_list_stack *stack)
{
    return sl_list_length(&(stack->list)) == 0;
}

/*!
 * @brief Displays the contents of the stack.
 * @param stack Pointer to a linked list stack.
 * @return None
 */
void display_stack(linked_list_stack *stack)
{
    // If the stack is empty, NULL is printed
    if (stack->list.list_size == 0)
    {
        printf("\nNULL");
    }
    // If the stack is not empty, the stack is traversed and the elements are printed to the terminal
    else
    {
        singly_linked_list_node *node = stack->list.head;
        printf("\n");
        printf("\nNULL->");

        do
        {
            printf("%d", node->value);
            node = node->next;

            if (node != NULL)
            {
                printf("->");
            }

        } while (node != NULL);
    }
}
