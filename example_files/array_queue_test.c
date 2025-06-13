/**
 ********************************************************************************
 * @file    array_stack_test.c
 * @author  Kai Gehry
 * @date    2025-06-07
 *
 * @brief   Tests the functionality of the operations defined in
 *          the array_queue header file.
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/
#include <stdio.h>
#include "../data_structures/queues/array_queue/array_queue.h"

/*!
 * @brief Prints the relevant contents of the array based queue to the terminal.
 * @param list Pointer to a queue.
 * @return None
 */
void display_queue(array_queue *queue)
{
    // Counter variable used to track how many elements have been traversed
    int j = 0;

    printf("\nQueue contents: [ ");

    // Displays only the elements from the front to the end index
    for (int i = queue->front_index; j < queue->num_elements; i++)
    {
        printf("%d ", (queue->array)[i]);
        j++;
    }

    printf("]\n");
}

/*!
 * @brief main function used to test the functionality of the array_queue header file.
 */
int main(void)
{
    array_queue queue;

    // Initializes the queue
    initialize_array_queue(&queue, 5);

    // Adds elements to the queue
    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);

    // Displays the contents of the queue
    display_queue(&queue);

    enqueue(&queue, 4);
    enqueue(&queue, 5);

    // Adds an element beyond the capacity of the queue
    printf("\nAttempt to add an element when queue is full: ");
    enqueue(&queue, 6);

    display_queue(&queue);

    // Removes an element from the queue
    dequeue(&queue);

    display_queue(&queue);

    // Returns the element at the front of the queue
    printf("\nElement at front of queue: %d\n", first(&queue));

    // Add an element where a shift is required
    enqueue(&queue, 7);
    display_queue(&queue);

    // Adds an element beyond the capacity of the queue
    printf("\nAttempt to add an element when queue is full: ");
    enqueue(&queue, 8);

    display_queue(&queue);

    printf("Front Index: %d", queue.front_index);
    printf("\nEnd Index: %d\n", queue.end_index);

    // Removes elements sequentially from the front of the queue
    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);

    display_queue(&queue);

    printf("Front Index: %d", queue.front_index);
    printf("\nEnd Index: %d\n", queue.end_index);

    // Returns the number of elements in the queue
    printf("\nNumber of elements in queue: %d\n", size(&queue));

    // Add elements where a shift is required
    enqueue(&queue, 9);
    enqueue(&queue, 10);
    enqueue(&queue, 11);

    display_queue(&queue);

    printf("Front Index: %d", queue.front_index);
    printf("\nEnd Index: %d\n", queue.end_index);

    // Returns the number of elements in the queue
    printf("\nNumber of elements in queue: %d\n\n", size(&queue));

    return 0;
}