/**
 ********************************************************************************
 * @file    singly_linked_list_test.c
 * @author  Kai Gehry
 * @date    2025-03-25
 *
 * @brief   Tests the functionality of the functions defined in
 *          the singly_linked_list header file.
 ********************************************************************************
 */

#include <stdio.h>
#include "C:\Users\Kai Gehry\Desktop\C\C_Data_Structures\Data_Strutures\singly_linked_list.h"

/*
    File used to test the functionality of the singly linked list header file.
*/
int main(void)
{

    // Creates a new linked list
    singly_linked_list list1;

    // Initializes the size of the linked list to 0
    initialize_list(&list1);
    // Displays the contents of the linked list
    display_linked_list(&list1);

    // Adds items to the head of the linked list
    add_node_to_head(&list1, 1);
    add_node_to_head(&list1, 2);

    int size = list_length(&list1);

    display_linked_list(&list1);
    printf("\nHead Element: %d", return_head_element(&list1));
    printf("\nSize of list: %d", size);

    // Removes an item
    remove_node(&list1, 2);
    display_linked_list(&list1);

    // Displays the number of elements in the list
    int size2 = list_length(&list1);

    printf("\nSize of list: %d", size2);
    printf("\nHead Element: %d\n\n", return_head_element(&list1));

    // Creates another linked list and adds and removes from it
    singly_linked_list list2;
    initialize_list(&list2);

    // Adds items to the tail of the linked list
    add_node_to_tail(&list2, 3);
    add_node_to_tail(&list2, 4);

    display_linked_list(&list2);
    remove_node(&list2, 4);
    remove_node(&list2, 3);
    display_linked_list(&list2);

    return 0;
}