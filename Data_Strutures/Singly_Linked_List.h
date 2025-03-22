#include <stdio.h>

// variable which defines the head of the linked list.
int *head;

// Struct used to define the attributes of a node in the linked list
typedef struct
{
    // Value held by the node
    int value;
    // pointer to the next node in the linked list
    int *next;

} Linked_List_Node;

void testPrint()
{
    printf("Testing a header file.");
}