/**
 ********************************************************************************
 * @file    singly_linked_list_test.c
 * @author  Kai Gehry
 * @date    2025-03-25
 * @brief
 ********************************************************************************
 */

#include <stdio.h>
#include "C:\Users\Kai Gehry\Desktop\C\C_Data_Structures\Data_Strutures\Singly_Linked_List.h"

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

    // Adds items to the list
    add_node(&list1, 1);
    add_node(&list1, 2);

    display_linked_list(&list1);

    remove_head_node(&list1);
    display_linked_list(&list1);

    // // Removes an item
    // remove_node(&list1, 2);
    // display_linked_list(&list1);

    // // Displays the number of elements in the list
    // int size = list_length(&list1);
    // printf("\nSize of list: %d\n\n", size);

    // // Creates another linked list and adds and removes from it
    // singly_linked_list list2;
    // initialize_list(&list2);

    // add_node(&list2, 3);
    // add_node(&list2, 4);

    // display_linked_list(&list2);
    // remove_node(&list2, 4);
    // remove_node(&list2, 3);
    // display_linked_list(&list2);

    return 0;
}