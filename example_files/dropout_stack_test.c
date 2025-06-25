/**
 ********************************************************************************
 * @file    dropout_stack_test.c
 * @author  Kai Gehry
 * @date    2025-04-06
 *
 * @brief   Tests the functionality of the operations defined in
 *          the dropout header file.
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/
#include <stdio.h>
#include "../data_structures/stacks/dropout_stack/dropout_stack.h"

/*!
 * @brief Displays the contents of the stack.
 * @param stack Pointer to a dropout stack.
 * @return None
 */
void display_do_stack(dropout_stack *stack)
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

/*!
 * @brief main function used to test the functionality of the dropout_stack header file.
 */
int main(void)
{
    // Creates a new dropout stack
    dropout_stack stack;

    // Initializes the stack and sets a dropout limit
    initialize_do_stack(&stack, 5);

    // Pushes items onto the stack and displays the contents
    push(&stack, 1);
    display_do_stack(&stack);
    push(&stack, 2);
    display_do_stack(&stack);
    push(&stack, 3);
    display_do_stack(&stack);

    // Pops an element off of the stack
    printf("\n\nPopped off stack: %d", pop(&stack));
    push(&stack, 4);
    display_do_stack(&stack);
    push(&stack, 5);
    display_do_stack(&stack);
    push(&stack, 6);
    display_do_stack(&stack);
    push(&stack, 7);
    display_do_stack(&stack);

    // Returns the size of the stack
    printf("\n\nList Size: %d", size(&stack));

    return 0;
}