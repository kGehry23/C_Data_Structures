#include <stdio.h>
#include "../data_structures/queues/array_queue.h"

int main(void)
{
    array_queue queue;

    initialize_array_queue(&queue, 5);

    enqueue(&queue, 1);

    return 0;
}