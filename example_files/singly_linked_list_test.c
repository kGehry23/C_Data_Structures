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
#include "../data_structures/linked_lists/singly_linked_list/singly_linked_list.h"

void display_sl_list(singly_linked_list *list)
{

    // If the list is empty, NULL is printed
    if (list->list_size == 0)
    {
        printf("\nNULL");
    }

    else
    {
        singly_linked_list_node *node = list->head;
        printf("\n", node->value);

        do
        {
            printf("%d->", node->value);
            node = node->next;
        } while (node != NULL);

        printf("NULL\n");
    }
}
/*!
 * @brief main function used to test the functionality of the singly linked list header file.
 */
int main(void)
{
    // Creates a new linked list
    singly_linked_list list1;

    // Initializes the size of the linked list to 0
    initialize_sl_list(&list1);

    // Displays the contents of the linked list
    display_sl_list(&list1);

    // Adds items to the head of the linked list
    add_sl_node_to_head(&list1, 1);
    add_sl_node_to_head(&list1, 4);
    add_sl_node_to_head(&list1, 2);
    add_sl_node_to_head(&list1, 3);
    add_sl_node_to_head(&list1, 5);

    // Returns the head and tail elements
    printf("\nHead Element: %d", return_sl_head(&list1));
    printf("\nTail Element: %d", return_sl_tail(&list1));

    // Displays the contents of the linked list and returns the length
    display_sl_list(&list1);
    printf("\nSize of list: %d", sl_list_length(&list1));

    printf("\n\n");

    // Creates another linked list and adds and removes from it
    singly_linked_list list2;
    initialize_sl_list(&list2);

    // Adds items to the tail of the linked list
    add_sl_node_to_head(&list2, 2);
    add_sl_node_to_head(&list2, 3);
    add_sl_node_to_head(&list2, 4);

    display_sl_list(&list2);

    // Returns the head and tail elements
    printf("\nHead Element: %d", return_sl_head(&list2));
    printf("\nTail Element: %d", return_sl_tail(&list2));

    // Removes a node
    printf("\nRemoved value: %d", remove_sl_node(&list2, 3));
    display_sl_list(&list2);

    printf("\nTail Element: %d", return_sl_tail(&list2));
    printf("\nHead Element: %d", return_sl_head(&list2));

    return 0;
}