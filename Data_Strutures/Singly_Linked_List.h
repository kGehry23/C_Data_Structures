/**
 ********************************************************************************
 * @file    Singly_Linked_List_Test.c
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
    struct Singly_Linked_List_Node head;
    struct Singly_Linked_List_Node *current;
    int list_size;
} Singly_Linked_List;

/*
    Initializes a singly linked list type by setting its list_size variable to 0.
*/
void initialize_list(Singly_Linked_List *list)
{
    list->list_size = 0;
}

/*
    Prints the contents of the singly linked list to the terminal.
*/
void display_linked_list(Singly_Linked_List *list)
{

    // If the list is empty, NULL is printed
    if ((list->list_size == 0))
    {
        printf("\nNULL");
    }
    else
    {
        struct Singly_Linked_List_Node node = list->head;
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
int return_head_element(Singly_Linked_List *list)
{
    return (list->head).value;
}

/*
    Returns the length of the singly linked list.
*/
int list_length(Singly_Linked_List *list)
{
    return list->list_size;
}

/*
    Adds a node to the singly linked list.
*/
void add_node(Singly_Linked_List *list, int value)
{
    // Linked list node pointer which represents the new node to be added
    struct Singly_Linked_List_Node *new_node = (struct Singly_Linked_List_Node *)malloc(sizeof(struct Singly_Linked_List_Node));
    // Linked list node pointer which represents the next node the newly added node points to
    struct Singly_Linked_List_Node *next_node = (struct Singly_Linked_List_Node *)malloc(sizeof(struct Singly_Linked_List_Node));

    if (list->list_size != 0)
    {
        // Sets new node to point to the address of the node at the end of the list
        new_node = list->current;
        // Sets the value of the new node
        (*new_node).value = value;
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
        (list->head).value = value;
        (list->head).next = list->current;
    }

    list->list_size++;
}

/*
    Removes a node from the singly linked list.
*/
void remove_node(Singly_Linked_List *list, int value)
{
    // Place holder node used to hold the nodes as the list is traversed
    struct Singly_Linked_List_Node search_node = list->head;
    // Pointer used to keep a reference to the previous node in the traversal
    struct Singly_Linked_List_Node *previous_node = &(list->head);

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
