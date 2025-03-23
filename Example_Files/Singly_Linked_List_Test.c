#include <stdio.h>
#include "C:\Users\Kai Gehry\Desktop\C\C_Data_Structures\Data_Strutures\Singly_Linked_List.h"

// Used to test the functions defined in the singly linked list header file

int main()
{

    struct Singly_Linked_List_Node Node1;
    struct Singly_Linked_List_Node Node2;
    struct Singly_Linked_List_Node Node3;

    Node1.value = 1;
    head = &Node1;
    Node1.next = &Node2;

    Node2.value = 2;
    Node2.next = &Node3;
    Node3.next = NULL;

    printf("\nPointer to head of linked list: %p", head);

    // add_node(1);
    // add_node(2);

    display_linked_list();
    int head_element = return_head_element();

    printf("\nHead Element: %d", head_element);

    return 0;
}