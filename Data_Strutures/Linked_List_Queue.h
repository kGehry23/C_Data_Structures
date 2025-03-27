#include <stdio.h>
#include "Singly_Linked_List.h"

// Struct which represents a queue
typedef struct linked_list_queue
{
    singly_linked_list *list;

} linked_list_queue;

// Adds an item to the queue
void enqueue(linked_list_queue *queue, int value)
{
    add_node(queue->list, value);
}

// Removes an item from the queue
void dequeue(linked_list_queue *queue)
{
    remove_head_node(queue->list);
}
