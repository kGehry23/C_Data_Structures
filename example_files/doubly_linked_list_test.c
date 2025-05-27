/**
 ********************************************************************************
 * @file    linked_list_queue_test.c
 * @author  Kai Gehry
 * @date    2025-03-26
 *
 * @brief   Tests the functionality of the operations defined in
 *          the doubly_linked_list header file.
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/
#include <stdio.h>
#include "../data_structures/linked_lists/doubly_linked_list/doubly_linked_list.h"

/*!
 * @brief Prints the contents of the doubly linked list to the terminal.
 * @param list Pointer to a doubly linked list struct.
 * @return None
 */
void display_dl_list(doubly_linked_list *list)
{

    // If the list is empty, NULL is printed
    if (list->list_size == 0)
    {
        printf("\nNULL");
    }

    else
    {
        doubly_linked_list_node *node = list->head;
        printf("\n", node->value);
        printf("NULL<=>");

        do
        {
            printf("%d<=>", node->value);
            node = node->next;
        } while (node != NULL);

        printf("NULL\n");
    }
}

/*!
 * @brief main function used to test the functionality of the doubly_linked_list header file.
 */
int main(void)
{
    // Creates a new doubly linked list
    doubly_linked_list dl_list;

    // Initializes the size of the linked list to 0
    initialize_dl_list(&dl_list);

    // Adds elements to the head and tail of the doubly linked list
    add_dl_node_to_tail(&dl_list, 1);
    add_dl_node_to_tail(&dl_list, 4);
    add_dl_node_to_tail(&dl_list, 2);
    add_dl_node_to_tail(&dl_list, 3);
    add_dl_node_to_tail(&dl_list, 5);
    add_dl_node_to_tail(&dl_list, 6);
    add_dl_node_to_tail(&dl_list, 7);

    // Inserts a node into an inner position in the linked list
    insert_dl_node(&dl_list, 8, 3);

    // Displays the linked list and returns the length
    display_dl_list(&dl_list);
    printf("\nSize of doubly linked list: %d\n", dl_list_length(&dl_list));

    // Returns the head and tail elements
    printf("\n\nHead Element: %d", return_dl_head(&dl_list));
    printf("\nTail Element: %d", return_dl_tail(&dl_list));

    // Removes nodes from the linked list
    printf("\n\nRemoved Element: %d", remove_dl_node(&dl_list, 4));
    printf("\nRemoved Element: %d", remove_dl_node(&dl_list, 7));
    printf("\nRemoved Element: %d\n", remove_dl_node(&dl_list, 5));

    // Displays the linked list and returns the length
    display_dl_list(&dl_list);
    printf("\nSize of doubly linked list: %d\n", dl_list_length(&dl_list));

    // Returns the head and tail elements
    printf("\n\nHead Element: %d", return_dl_head(&dl_list));
    printf("\nTail Element: %d", return_dl_tail(&dl_list));

    return 0;
}
