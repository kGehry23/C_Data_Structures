#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Singly_Linked_List_Node.h"

// struct Singly_Linked_List
// {
// };

// Struct which defines the node at the head of the linked list
struct Singly_Linked_List_Node head;
// Struct which defines the node at the end of the linked list (set as null)
struct Singly_Linked_List_Node *current;
// Holds the value of the list size
int list_size;

// Prints the linked list to the terminal
void display_linked_list()
{
    struct Singly_Linked_List_Node node = head;
    printf("\n");

    while (node.next != NULL)
    {
        printf("%d->", (node).value);
        node = *(node.next);
    }

    printf("NULL");
}

// Returns the element at the head of the linked list
int return_head_element()
{
    return head.value;
}

// Returns the length of the linked list
int list_length()
{
    return list_size;
}

// Adds a node to the linked list
void add_node(int value)
{
    // Linked list node pointer which represents the new node to be added
    struct Singly_Linked_List_Node *new_node = (struct Singly_Linked_List_Node *)malloc(sizeof(struct Singly_Linked_List_Node));
    // Linked list node pointer which represents the next node the newly added node points to
    struct Singly_Linked_List_Node *next_node = (struct Singly_Linked_List_Node *)malloc(sizeof(struct Singly_Linked_List_Node));

    if (list_size != 0)
    {
        // Sets new node to point to the address of the node at the end of the list
        new_node = current;
        // Sets the value of the new node
        (*new_node).value = value;
        // Points to the node which will now be at the end of the list
        (*new_node).next = next_node;
    }

    // Sets the node which previously pointed to the end of the list to the new node at the end of the list
    current = next_node;
    // Sets the end of the list's next pointer to NULL
    (*current).next = NULL;

    // Defines the head of the linked list
    if (list_size == 0)
    {
        head.value = value;
        head.next = current;
    }

    list_size++;
}

// Removes a node from the linked list
void remove_node(int value)
{
    // Place holder node used to hold the nodes as the list is traversed
    struct Singly_Linked_List_Node search_node = head;
    // Pointer used to keep a reference to the previous node in the traversal
    struct Singly_Linked_List_Node *previous_node = &head;

    while (search_node.next != NULL)
    {
        // Logic for if the node to remove is found
        if (search_node.value == value)
        {
            // If the node is the head element, the head element is re-assigned
            if (search_node.value == head.value)
            {
                // search node is assigned to the following node
                search_node = *(search_node).next;
                // The value and pointer of the head node are re-assigned
                head.value = search_node.value;
                head.next = search_node.next;
            }
            // If the node to remove is any other element in the list
            else
            {
                // Re-assigns the previous node's pointer to point to the node after the node to remove
                (*previous_node).next = search_node.next;
            }

            printf("\nNode with value %d removed.", value);
            break;
        }

        // If the current node is not the head node, the pointer to the previous element is re-assigned
        if (search_node.value != head.value)
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
