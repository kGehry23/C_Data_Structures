#include <stdio.h>
#include "../data_structures/queues/circular_queue.h"

void display_circular_queue(circular_queue *queue)
{
    // Counter variable used to track how many elements have been traversed
    int j = 0;

    printf("\nQueue contents: [ ");

    // Displays only the elements from the front to the end index

    int i = queue->front_index;

    while (j < queue->num_elements)
    {
        printf("%d ", (queue->array)[i]);
        i = (i + 1) % (queue->size);
        j++;
    }

    printf("]\n");
}

int main(void)
{
    circular_queue circ_queue;

    initialize_circular_queue(&circ_queue, 5);

    enqueue(&circ_queue, 1);

    display_circular_queue(&circ_queue);

    return 0;
}