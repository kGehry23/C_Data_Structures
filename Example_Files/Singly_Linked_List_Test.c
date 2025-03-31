/**
 ********************************************************************************
 * @file    singly_linked_list_test.c
 * @author  Kai Gehry
 * @date    2025-03-25
 *
 * @brief   Tests the functionality of the operations defined in
 *          the singly_linked_list header file.
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/
#include <stdio.h>
#include "C:\Users\Kai Gehry\Desktop\C\C_Data_Structures\Data_Structures\singly_linked_list.h"

/*!
 * @brief main function used to test the functionality of the singly linked list header file.
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
    add_node_to_tail(&list1, 2);
    add_node_to_tail(&list1, 3);

    // Returns the head and tail elements
    printf("\nTail Element: %d", return_tail_element(&list1));
    printf("\nHead Element: %d", return_head_element(&list1));

    int size = list_length(&list1);
    display_linked_list(&list1);
    printf("\nSize of list: %d", size);

    printf("\n\n");

    // Creates another linked list and adds and removes from it
    singly_linked_list list2;
    initialize_list(&list2);

    // Adds items to the tail of the linked list
    add_node_to_tail(&list2, 3);
    add_node_to_tail(&list2, 4);

    display_linked_list(&list2);

    // Returns the head and tail elements
    printf("\nTail Element: %d", return_tail_element(&list2));
    printf("\nHead Element: %d", return_head_element(&list2));

    // Removes a node
    printf("\nRemoved value: %d", remove_node(&list2, 4));
    display_linked_list(&list2);

    printf("\nTail Element: %d", return_tail_element(&list2));
    printf("\nHead Element: %d", return_head_element(&list2));

    return 0;
}