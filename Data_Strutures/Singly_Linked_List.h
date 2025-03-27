/**
 ********************************************************************************
 * @file    singly_linked_list.h
 * @author  Kai Gehry
 * @date    2025-03-25
 * @brief
 ********************************************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include "Singly_Linked_List_Node.h"

/*
    Struct representing a singly linked list.
*/
typedef struct
{
    singly_linked_list_node head;
    singly_linked_list_node *current;
    int list_size;
} singly_linked_list;

/*
    Initializes a singly linked list type by setting its list_size variable to 0.
*/
void initialize_list(singly_linked_list *list)
{
    list->list_size = 0;
}

/*
    Prints the contents of the singly linked list to the terminal.
*/
void display_linked_list(singly_linked_list *list)
{

    // If the list is empty, NULL is printed
    if ((list->list_size == 0))
    {
        printf("\nNULL");
    }
    else
    {
        singly_linked_list_node node = list->head;
        printf("\n");

        while (node.next != NULL)
        {
            printf("%d->", (node).value);
            node = *(node.next);
        }

        printf("NULL");
    }
}

/*
    Returns the element at the head of the singly linked list.
*/
int return_head_element(singly_linked_list *list)
{
    return (list->head).value;
}

/*
    Returns the length of the singly linked list.
*/
int list_length(singly_linked_list *list)
{
    return list->list_size;
}

/*
    Adds a node to the front of the singly linked list.
*/
void add_node_to_head(singly_linked_list *list, int insert_value)
{

    // Defines the head of the linked list
    if (list->list_size == 0)
    {
        // Linked list node pointer which represents the next node the newly added node points to
        singly_linked_list_node *next_node = (singly_linked_list_node *)malloc(sizeof(singly_linked_list_node));

        // Sets the node which previously pointed to the end of the list to the new node at the end of the list
        list->current = next_node;
        // Sets the end of the list's next pointer to NULL
        (*(list->current)).next = NULL;

        (list->head).value = insert_value;
        (list->head).next = list->current;
    }
    else
    {
        // Linked list node pointer which represents the new node to be added
        singly_linked_list_node *new_node = (singly_linked_list_node *)malloc(sizeof(singly_linked_list_node));

        // FIGURE THIS OUT. Issues with a head pointer not being able to be reassigned.
    }

    list->list_size++;
}

/*
    Adds a node to the the end of the singly linked list.
*/
void add_node_to_tail(singly_linked_list *list, int insert_value)
{

    // Linked list node pointer which represents the next node the newly added node points to
    singly_linked_list_node *next_node = (singly_linked_list_node *)malloc(sizeof(singly_linked_list_node));

    if (list->list_size != 0)
    {
        // Linked list node pointer which represents the new node to be added
        singly_linked_list_node *new_node = (singly_linked_list_node *)malloc(sizeof(singly_linked_list_node));
        // Sets new node to point to the address of the node at the end of the list
        new_node = list->current;
        // Sets the value of the new node
        (*new_node).value = insert_value;
        // Points to the node which will now be at the end of the list
        (*new_node).next = next_node;
    }

    // Sets the node which previously pointed to the end of the list to the new node at the end of the list
    list->current = next_node;
    // Sets the end of the list's next pointer to NULL
    (*(list->current)).next = NULL;

    // Defines the head of the linked list
    if (list->list_size == 0)
    {
        (list->head).value = insert_value;
        (list->head).next = list->current;
    }

    list->list_size++;
}

/*
    Removes a node from the singly linked list.
*/
void remove_node(singly_linked_list *list, int value)
{
    // Place holder node used to hold the nodes as the list is traversed
    singly_linked_list_node search_node = list->head;
    // Pointer used to keep a reference to the previous node in the traversal
    singly_linked_list_node *previous_node = &(list->head);

    while (search_node.next != NULL)
    {
        // Logic for if the node to remove is found
        if (search_node.value == value)
        {
            // If the node is the head element, the head element is re-assigned
            if (search_node.value == (list->head).value)
            {
                // search node is assigned to the following node
                search_node = *(search_node).next;
                // The value and pointer of the head node are re-assigned
                (list->head).value = search_node.value;
                (list->head).next = search_node.next;
            }
            // If the node to remove is any other element in the list
            else
            {
                // Re-assigns the previous node's pointer to point to the node after the node to remove
                (*previous_node).next = search_node.next;
            }

            list->list_size--;
            break;
        }

        // If the current node is not the head node, the pointer to the previous element is re-assigned
        if (search_node.value != (list->head).value)
        {
            previous_node = (*previous_node).next;
        }

        search_node = *(search_node).next;

        if (search_node.next == NULL)
        {
            printf("\nNode with value %d not found.", value);
        }
    }
}
