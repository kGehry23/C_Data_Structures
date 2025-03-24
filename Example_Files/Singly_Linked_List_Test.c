#include <stdio.h>
#include "C:\Users\Kai Gehry\Desktop\C\C_Data_Structures\Data_Strutures\Singly_Linked_List.h"

// Used to test the functions defined in the singly linked list header file

int main()
{

    add_node(1);
    add_node(2);
    add_node(3);
    add_node(4);

    display_linked_list();
    int size = list_length();
    printf("\nSize of list: %d", size);

    int head_elem = return_head_element();
    printf("\nHead Elem: %d\n", head_elem);

    remove_node(2);
    display_linked_list();

    return 0;
}