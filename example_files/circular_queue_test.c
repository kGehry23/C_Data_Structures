/**
 ********************************************************************************
 * @file    circular_queue_test.c
 * @author  Kai Gehry
 * @date    2025-06-07
 *
 * @brief   Tests the functionality of the operations defined in
 *          the circular_queue header file.
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/
#include <stdio.h>
#include "../data_structures/queues/circular_queue.h"

/*!
 * @brief Prints the relevant contents of the circular queue to the terminal.
 * @param list Pointer to a circular queue.
 * @return None
 */
void display_circular_queue(circular_queue *queue)
{
    // Counter variable used to track how many elements have been traversed
    int j = 0;
    // Variable which indicates which index to begin traversal at
    int i = queue->front_index;

    printf("\nQueue contents: [ ");

    // Displays only the elements from the front to the end index
    while (j < queue->num_elements)
    {
        if (i == queue->front_index)
            printf("->%d ", (queue->array)[i]);
        else if (j + 1 == queue->num_elements)
            printf("%d-> ", (queue->array)[i]);
        else
            printf("%d ", (queue->array)[i]);

        // Update the element index
        i = (i + 1) % (queue->size);
        // Increment the counter
        j++;
    }

    printf("]\n");
}

/*!
 * @brief main function used to test the functionality of the circular_queue header file.
 */
int main(void)
{
    circular_queue circ_queue;

    // Initializes the circular queue
    initialize_circular_queue(&circ_queue, 5);

    // Attempts to remove an element from an empty queue
    dequeue(&circ_queue);

    // Checks if the queue is empty
    printf("\nEmpty: %d\n", is_empty(&circ_queue));

    // Adds elements to the queue
    enqueue(&circ_queue, 1);
    enqueue(&circ_queue, 2);
    enqueue(&circ_queue, 3);
    enqueue(&circ_queue, 4);
    enqueue(&circ_queue, 5);

    display_circular_queue(&circ_queue);

    // Adds an element beyond the capacity of the queue
    printf("\nAttempt to add an element when queue is full: ");
    enqueue(&circ_queue, 6);

    /*Elements removed until there is only one element left in the queue.
      This element's index is at the final position of the queue.*/
    dequeue(&circ_queue);
    dequeue(&circ_queue);
    dequeue(&circ_queue);
    dequeue(&circ_queue);

    display_circular_queue(&circ_queue);

    printf("Front Index: %d", circ_queue.front_index);
    printf("\nEnd Index: %d\n", circ_queue.end_index);

    // Add an element and check that the front and end indices have been updated correctly
    enqueue(&circ_queue, 6);

    display_circular_queue(&circ_queue);

    printf("Front Index: %d", circ_queue.front_index);
    printf("\nEnd Index: %d\n", circ_queue.end_index);

    dequeue(&circ_queue);

    display_circular_queue(&circ_queue);

    printf("Front Index: %d", circ_queue.front_index);
    printf("\nEnd Index: %d\n", circ_queue.end_index);

    enqueue(&circ_queue, 7);
    display_circular_queue(&circ_queue);

    printf("Front Index: %d", circ_queue.front_index);
    printf("\nEnd Index: %d\n", circ_queue.end_index);

    // Returns the number of elements in the queue
    printf("\nNumber of elements in queue: %d\n", size(&circ_queue));

    // Removes an element and displays the contents
    dequeue(&circ_queue);
    display_circular_queue(&circ_queue);

    printf("Front Index: %d", circ_queue.front_index);
    printf("\nEnd Index: %d\n", circ_queue.end_index);

    enqueue(&circ_queue, 8);
    display_circular_queue(&circ_queue);

    enqueue(&circ_queue, 9);
    display_circular_queue(&circ_queue);

    // Checks if the circular queue is empty
    printf("\nEmpty: %d\n", is_empty(&circ_queue));

    printf("Front Index: %d", circ_queue.front_index);
    printf("\nEnd Index: %d\n", circ_queue.end_index);

    return 0;
}