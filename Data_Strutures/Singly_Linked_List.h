#include <stdio.h>
#include "Singly_Linked_List_Node.h"

// Struct which defines the node at the head of the linked list
struct Singly_Linked_List_Node *head;
// Struct which defines the node at the end of the linked list (set as null)
struct Singly_Linked_List_Node current;
// Holds the value of the list size
int list_size;

// Prints the linked list to the terminal
void display_linked_list()
{
    struct Singly_Linked_List_Node node = *head;
    printf("\n");

    while (node.next != NULL)
    {
        printf("%d->", node.value);
        node = *(node.next);
    }

    printf("NULL");
}

// Returns the element at the head of the linked list
int return_head_element()
{
    return (*head).value;
}

// Adds a node to the linked list
void add_node(int value)
{

    printf("List Size: %d", list_size);

    struct Singly_Linked_List_Node new_node = current;
    struct Singly_Linked_List_Node next_node;

    new_node.value = value;
    new_node.next = &next_node;

    if (list_size == 0)
    {
        head = &new_node;
    }

    next_node.next = NULL;
    current = next_node;

    list_size++;
}

// Removes a node from the linked list
void remove_node(int value)
{
}
