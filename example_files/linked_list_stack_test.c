/**
 ********************************************************************************
 * @file    linked_list_stack_test.c
 * @author  Kai Gehry
 * @date    2025-03-25
 *
 * @brief   Tests the functionality of the operations defined in
 *          the linked_list_stack header file.
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/
#include <stdio.h>
#include "../data_structures/stacks/linked_list_stack.h"

/*!
 * @brief main function used to test the functionality of the linked list stack header file.
 */
void main(void)
{

    // Creates a new stack
    linked_list_stack stack;

    // Initializes the stack
    initialize_stack(&stack);

    // Checks if the stack is empty
    printf("\nEmpty: %d\n", is_empty(&stack));

    // Adds an element to the stack and returns the top element without removing it.
    push(&stack, 1);
    printf("\nTop of stack: %d", peek(&stack));

    // Displays the contents of the stack
    display_stack(&stack);

    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);
    push(&stack, 5);
    push(&stack, 6);
    push(&stack, 7);
    printf("\nTop of stack: %d", peek(&stack));

    printf("\nSize of stack: %d", size(&stack));
    printf("\nEmpty: %d", is_empty(&stack));

    display_stack(&stack);

    // Removes an item from the stack
    printf("\nElement popped off stack: %d", pop(&stack));
    printf("\nTop of stack: %d", peek(&stack));

    display_stack(&stack);
}
