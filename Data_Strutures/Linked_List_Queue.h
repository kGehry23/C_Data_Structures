/**
 ********************************************************************************
 * @file    linked_list_queue.h
 * @author  Kai Gehry
 * @date    2025-03-26
 * @brief
 ********************************************************************************
 */

#include <stdio.h>
#include "Singly_Linked_List.h"

/*
    Struct which represents a queue.
*/
typedef struct
{
    singly_linked_list list;
} linked_list_queue;

/*
    Initializes the queue.
*/
void initialize_queue(linked_list_queue *queue)
{
    initialize_list(&(queue->list));
}

/*
    Adds an item to the queue.
*/
void enqueue(linked_list_queue *queue, int value)
{
    add_node(&(queue->list), value);
}

/*
    Removes an item from the queue and returns its value.
*/
int dequeue(linked_list_queue *queue)
{
    return remove_head_node(&(queue->list));
}

/*
    Displays the contents of the queue.
*/
void display_queue(linked_list_queue *queue)
{
    display_linked_list((&queue->list));
}
