/**
 ********************************************************************************
 * @file    deque_test.c
 * @author  Kai Gehry
 * @date    2025-03-26
 *
 * @brief   Tests the functionality of the operations defined in
 *          the deque header file.
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/
#include <stdio.h>
#include "../data_structures/queues/deque/deque.h"

/*!
 * @brief Prints the contents of the doubly ended queue to the terminal.
 * @param list Pointer to a doubly linked list struct.
 * @return None
 */
void display_deque(linked_deque *deque)
{

    // If the list is empty, NULL is printed
    if ((deque->list).list_size == 0)
    {
        printf("\nNULL");
    }

    else
    {
        doubly_linked_list_node *node = (deque->list).head;
        printf("\n", node->value);
        printf("NULL<=>");

        do
        {
            printf("%d<=>", node->value);
            node = node->next;
        } while (node != NULL);

        printf("NULL\n");
    }
}

/*!
 * @brief main function used to test the functionality of the deque header file.
 */
int main(void)
{
    // Creates a new deque
    linked_deque deque;

    // Initializes the deque
    initialize_deque(&deque);

    // Adds elements to the head of the deque
    enqueue_head(&deque, 1);
    enqueue_head(&deque, 2);
    // Adds elements to the tail of the deque
    enqueue_tail(&deque, 3);
    enqueue_tail(&deque, 4);
    enqueue_tail(&deque, 5);

    enqueue_head(&deque, 6);

    // Removes an element from the head and the tail of the deque
    dequeue_head(&deque);
    dequeue_tail(&deque);

    // Returns but does not remove the head and tail elements
    printf("\nFront element: %d", front(&deque));
    printf("\nBack element: %d", back(&deque));

    display_deque(&deque);

    // Returns the number of elements in the deque
    printf("\nSize of deque: %d", size(&deque));
    // Returns if the deque is empty or not
    printf("\nEmpty: %d", is_empty(&deque));

    return 0;
}