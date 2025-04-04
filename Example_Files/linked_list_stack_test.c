/**
 ********************************************************************************
 * @file    singly_linked_list_test.c
 * @author  Kai Gehry
 * @date    2025-03-25
 *
 * @brief   Tests the functionality of the operations defined in
 *          the singly_linked_list header file.
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/
#include <stdio.h>
#include "../Data_Structures/linked_list_stack.h"

/*!
 * @brief main function used to test the functionality of the linked list stack header file.
 */
int main(void)
{

    linked_list_stack stack;

    initialize_stack(&stack);

    printf("\nEmpty: %d\n", is_empty(&stack));

    push(&stack, 1);
    printf("%d", peek(&stack));

    display_stack(&stack);

    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);
    push(&stack, 5);
    push(&stack, 6);
    push(&stack, 7);
    printf("\n%d", peek(&stack));

    printf("\nSize of stack: %d", size(&stack));
    printf("\nEmpty: %d", is_empty(&stack));

    display_stack(&stack);

    printf("\nRemoved value: %d", pop(&stack));

    display_stack(&stack);
}
