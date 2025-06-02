/**
 ********************************************************************************
 * @file    linked_list_queue_test.c
 * @author  Kai Gehry
 * @date    2025-03-26
 *
 * @brief   Tests the functionality of the operations defined in
 *          the linked_list_queue header file.
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/
#include <stdio.h>
#include "../data_structures/queues/linked_list_queue.h"

/*!
 * @brief Displays the contents of the queue.
 * @param queue Pointer to a linked list queue.
 * @return None
 */
void display_queue(linked_list_queue *queue)
{
    // If the list is empty, NULL is printed
    if ((queue->list).list_size == 0)
    {
        printf("\nNULL");
    }
    // If the list is not empty, the list is traversed and the elements are printed to the terminal
    else
    {
        singly_linked_list_node *node = (queue->list).head;
        printf("\n");

        do
        {
            printf("%d->", node->value);
            node = node->next;
        } while (node != NULL);

        printf("NULL");
    }
}

/*!
 * @brief main function used to test the functionality of the linked_list_queue header file.
 */
int main(void)
{

    // Creates a new queue
    linked_list_queue queue1;

    // Initializes the queue
    initialize_queue(&queue1);
    printf("\nEmpty: %d", is_empty(&queue1));

    // Adds items to the first queue
    enqueue(&queue1, 1);
    enqueue(&queue1, 2);
    enqueue(&queue1, 3);
    enqueue(&queue1, 4);
    enqueue(&queue1, 5);
    enqueue(&queue1, 6);

    // Displays the contents of the queue
    display_queue(&queue1);
    printf("\nHead element: %d", first(&queue1));
    printf("\nSize of queue: %d", size(&queue1));

    printf("\nEmpty: %d", is_empty(&queue1));

    // Removes and returns the value stored by the removed node
    int value1 = dequeue(&queue1);
    printf("\nValue: %d", value1);
    display_queue(&queue1);

    printf("\nHead element: %d", first(&queue1));
    printf("\nSize of queue: %d", size(&queue1));

    printf("\n");

    // Creates a new second queue to show more than one can exist at once
    linked_list_queue queue2;

    initialize_queue(&queue2);

    enqueue(&queue2, 9);
    enqueue(&queue2, 10);

    display_queue(&queue2);
    printf("\nHead element: %d", first(&queue2));
    printf("\nSize of queue: %d", size(&queue2));

    int value2 = dequeue(&queue2);
    printf("\nValue: %d", value2);
    display_queue(&queue2);

    return 0;
}
