#include <stdio.h>
#include "Singly_Linked_List_Node.h"

// Struct which defines the node at the head of the linked list
struct Singly_Linked_List_Node *head;
// Holds the value of the list size
int list_size;

void display_linked_list()
{

    struct Singly_Linked_List_Node node = *head;

    while (node.next != NULL)
    {
        printf("\nCurrent Address: %p", node.next);
        printf("\nStored Value: %d", node.value);
        node = *(node.next);
    }
}

// void add_node(int value)
// {

//     printf("List Size: %d", list_size);

//     struct Singly_Linked_List_Node new_node;
//     struct Singly_Linked_List_Node next_node;

//     if (list_size == 0)
//     {
//         head = &new_node;
//     }

//     new_node.value = value;
//     new_node.next = &next_node;
//     next_node.next = NULL;

//     list_size++;
// }
