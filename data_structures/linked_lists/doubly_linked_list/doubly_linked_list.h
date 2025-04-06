/**
 ********************************************************************************
 * @file    doubly_linked_list.h
 * @author  Kai Gehry
 * @date    2025-0-05
 *
 * @brief   Defines the operations on a doubly linked list.
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/
#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list_node.h"

/*!
 * @brief   Struct representing a doubly linked list.
 */
typedef struct
{
	doubly_linked_list_node *head;
	doubly_linked_list_node *tail;
	int list_size;
} doubly_linked_list;

/*!
 * @brief   Initializes a doubly linked list type by setting its list_size variable to 0.
 * @param list  Pointer to the linked list being initalized.
 * @return  None
 */
void initialize_dl_list(doubly_linked_list *list)
{
	list->list_size = 0;
}
