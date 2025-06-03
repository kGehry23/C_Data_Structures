/**
 ********************************************************************************
 * @file    array_stack_test.c
 * @author  Kai Gehry
 * @date    2025-06-02
 *
 * @brief   Tests the functionality of the operations defined in
 *          the array_stack header file.
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/
#include <stdio.h>
#include "../data_structures/stacks/array_stack.h"

/*!
 * @brief Prints the contents of the array based stack to the terminal.
 * @param list Pointer to a stack.
 * @return None
 */
void display_stack(array_stack *stack)
{
    for (int i = (stack->size - 1); i >= 0; i--)
    {
        printf("\n%d", (stack->array)[i]);
    }
}

/*!
 * @brief main function used to test the functionality of the array_stack header file.
 */
int main(void)
{
    array_stack stack;

    // Initializes the stack
    initialize_array_stack(&stack, 5);

    // Checks if the stack is empty
    printf("\nEmpty: %d", is_empty(&stack));

    // Pushes elements onto the stack
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);
    push(&stack, 5);

    // Tests the output when the element limit is reached
    push(&stack, 6);

    // Checks if the stack is empty
    printf("\nEmpty: %d\n", is_empty(&stack));

    // Returns the number of elements in the stack
    printf("\nNumber of elements in stack: %d", size(&stack));

    // Peeks the element at the top of the stack
    printf("\nElement at top of stack: %d\n", peek(&stack));

    // Prints the contents of the stack to the terminal
    display_stack(&stack);

    // Pop elements off of the stack and view the updated content of the stack
    printf("\n\nPopped: %d\n", pop(&stack));

    display_stack(&stack);
    printf("\n\nPopped: %d", pop(&stack));

    // Returns the number of elements in the stack
    printf("\nNumber of elements in stack: %d", size(&stack));

    printf("\n\n");

    push(&stack, 7);
    display_stack(&stack);

    printf("\n\n");

    push(&stack, 8);
    display_stack(&stack);

    // Peeks the element at the top of the stack
    printf("\n\nElement at top of stack: %d\n", peek(&stack));

    return 0;
}
