/**
 ********************************************************************************
 * @file    Singly_Linked_List_Test.c
 * @author  Kai Gehry
 * @date    2025-03-25
 * @brief
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/

#include <stdio.h>
#include "C:\Users\Kai Gehry\Desktop\C\C_Data_Structures\Data_Strutures\Singly_Linked_List.h"

/************************************
 * EXTERN VARIABLES
 ************************************/

/************************************
 * PRIVATE MACROS AND DEFINES
 ************************************/

/************************************
 * PRIVATE TYPEDEFS
 ************************************/

/************************************
 * STATIC VARIABLES
 ************************************/

/************************************
 * GLOBAL VARIABLES
 ************************************/

/************************************
 * STATIC FUNCTION PROTOTYPES
 ************************************/

/************************************
 * STATIC FUNCTIONS
 ************************************/

/************************************
 * GLOBAL FUNCTIONS
 ************************************/

int main()
{

    // Creates a new linked list
    Singly_Linked_List list1;

    // Initializes the size of the linked list to 0
    initialize_list(&list1);
    // Displays the contents of the linked list
    display_linked_list(&list1);

    // Adds items to the list
    add_node(&list1, 1);
    add_node(&list1, 2);

    display_linked_list(&list1);

    // Removes an items
    remove_node(&list1, 2);
    display_linked_list(&list1);

    // Displays the number of elements in the list
    int size = list_length(&list1);
    printf("\nSize of list: %d", size);

    // Creates another linked list and adds and removes from it
    Singly_Linked_List list1;
    initialize_list(&list1);

    add_node(&list1, 3);
    add_node(&list1, 4);

    display_linked_list(&list1);
    remove_node(&list1, 4);
    remove_node(&list1, 3);
    display_linked_list(&list1);

    return 0;
}