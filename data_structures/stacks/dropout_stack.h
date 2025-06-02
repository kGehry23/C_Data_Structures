/**
 ********************************************************************************
 * @file    dropout_stack.h
 * @author  Kai Gehry
 * @date    2025-04-06
 *
 * @brief   Defines the operations on a dropout stack.
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/
#include <stdio.h>
#include <stdbool.h>
#include "../linked_lists/singly_linked_list/singly_linked_list.h"

/************************************
 * COMPILER DIRECTIVES
 ************************************/
// Added for void* to required type conversions
#pragma GCC diagnostic ignored "-Wint-conversion"

/*!
 * @brief Struct which represents a dropout stack.
 */
typedef struct
{
    // Defines the size limit of the dropout stack
    int stack_limit;
    singly_linked_list list;
} dropout_stack;

/*!
 * @brief Initializes the dropout stack.
 * @param stack Pointer to a dropout stack stack.
 * @param dropout_limit Limit for the number of items to keep in the
 *                      stack. Items at the bottom of the stack are
 *                      dropped off as when the limit is exceeded.
 * @return None
 */
void initialize_do_stack(dropout_stack *stack, int dropout_limit)
{
    initialize_sl_list(&(stack->list));
    stack->stack_limit = dropout_limit;
}

/*!
 * @brief Adds an element to the top of the stack
 * @param stack Pointer to a dropout stack.
 * @param value Element to push onto the stack.
 * @return None
 */
void push(dropout_stack *stack, void *value)
{
    add_sl_node_to_head(&(stack->list), value);

    if (stack->list.list_size > stack->stack_limit)
    {
        remove_sl_node(&(stack->list), (stack->list.tail)->value);
    }
}

/*!
 * @brief Displays the contents of the dropout stack.
 * @param stack Pointer to a dropout stack.
 * @return The value held by the node at the top of the stack.
 */
int pop(dropout_stack *stack)
{
    return remove_sl_node(&(stack->list), (stack->list.head)->value);
}

/*!
 * @brief Returns the element at the top of the stack.
 * @param stack Pointer to a dropout stack.
 * @return The value held by the node at the head of the stack.
 */
int peek(dropout_stack *stack)
{
    return return_sl_head(&(stack->list));
}

/*!
 * @brief Returns the size (number of elements) in the stack.
 * @param stack Pointer to a dropout stack.
 * @return An integer value representing the number of elements in the stack.
 */
int size(dropout_stack *stack)
{
    return sl_list_length(&(stack->list));
}

/*!
 * @brief Returns if the dropout stack is empty or not.
 * @param queue Pointer to a dropout stack.
 * @return A boolean value representing if the stack is empty (1) or not empty (0)
 */
bool is_empty(dropout_stack *stack)
{
    return sl_list_length(&(stack->list)) == 0;
}

// /*!
//  * @brief Displays the contents of the stack. Can be uncommented if the data type to be
//           stored remains constant.
//  * @param stack Pointer to a dropout stack.
//  * @return None
//  */
// void display_do_stack(dropout_stack *stack)
// {
//     // If the stack is empty, NULL is printed
//     if (stack->list.list_size == 0)
//     {
//         printf("\nNULL");
//     }
//     // If the stack is not empty, the stack is traversed and the elements are printed to the terminal
//     else
//     {
//         singly_linked_list_node *node = stack->list.head;
//         printf("\n");
//         printf("\nNULL->");

//         do
//         {
//             printf("%d", node->value);
//             node = node->next;

//             if (node != NULL)
//             {
//                 printf("->");
//             }

//         } while (node != NULL);
//     }
// }
