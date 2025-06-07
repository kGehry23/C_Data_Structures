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
#include "../data_structures/queues/array_queue.h"
/*!
 * @brief Prints the contents of the array based queue to the terminal.
 * @param list Pointer to a queue.
 * @return None
 */
void display_queue(array_queue *queue)
{
    int j = 0;

    for (int i = queue->front_index; j < queue->num_elements; i++)
    {
        printf("\n%d", (queue->array)[i]);
        j++;
    }

    printf("\n");
}

/*!
 * @brief main function used to test the functionality of the array_queue header file.
 */
int main(void)
{
    array_queue queue;

    initialize_array_queue(&queue, 5);

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);

    display_queue(&queue);

    enqueue(&queue, 4);
    enqueue(&queue, 5);
    enqueue(&queue, 6);

    display_queue(&queue);

    dequeue(&queue);

    display_queue(&queue);

    // printf("\nFront Index: %d", queue.front_index);

    // printf("\nElement dequeued: %d", dequeue(&queue));

    // printf("\nFront Index: %d", queue.front_index);

    // printf("\nNumber of Elements: %d", size(&queue));

    // display_queue(&queue);

    // printf("\nElement at front of queue: %d", first(&queue));

    // display_queue(&queue);

    // printf("\n\nEmpty: %d", is_empty(&queue));
    // printf("\nNumber of Elements: %d", size(&queue));

    // enqueue(&queue, 4);
    // // enqueue(&queue, 5);

    // enqueue(&queue, 6);
    // display_queue(&queue);
    // printf("\nNumber of Elements: %d", size(&queue));

    // // enqueue(&queue, 7);

    // printf("\nFront Index: %d", queue.front_index);

    // printf("\nNumber of Elements: %d", size(&queue));

    // display_queue(&queue);

    return 0;
}