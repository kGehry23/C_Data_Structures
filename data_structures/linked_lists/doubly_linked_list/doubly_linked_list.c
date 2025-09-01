/**
 ********************************************************************************
 * @file    doubly_linked_list.c
 * @author  Kai Gehry
 * @date    2025-04-05
 *
 * @brief   Defines the operations on a doubly linked list.
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/
#include "doubly_linked_list.h"

/************************************
 * FUNCTION DEFINITIONS
 ************************************/

/*!
 * @brief   Initializes a doubly linked list type.
 * @param list  Pointer to the doubly linked list being initalized.
 * @return  None
 */
void initialize_dl_list(doubly_linked_list *list)
{
	list->list_size = 0;
	list->head = NULL;
	list->tail = NULL;
}

/*!
 * @brief Returns the element at the tail of the doubly linked list.
 * @param list Pointer to a doubly linked list struct.
 * @return The value held at the tail of the doubly linked list.
 */
void *return_dl_tail(doubly_linked_list *list)
{
	// Returns NULL if the list is empty
	if (list->list_size == 0)
		return NULL;
	else
		return (list->tail)->value;
}

/*!
 * @brief Returns the element at the head of the doubly linked list.
 * @param list Pointer to a doubly linked list.
 * @return The value held at the head of the doubly linked list.
 */
void *return_dl_head(doubly_linked_list *list)
{
	// Returns NULL is the list is empty
	if (list->list_size == 0)
		return NULL;
	else
		return (list->head)->value;
}

/*!
 * @brief Returns the length of the doubly linked list.
 * @param list Pointer to a doubly linked list struct.
 * @return An integer representing the size of the linked list.
 */
int dl_list_length(doubly_linked_list *list)
{
	return list->list_size;
}

/*!
 * @brief Adds a node to the front of the doubly linked list.
 * @param list Pointer to a doubly linked list struct.
 * @param insert_value Value to insert at the head of the list.
 * @return None
 */
void add_dl_node_to_head(doubly_linked_list *list, void *insert_value)
{
	// Linked list node pointer which represents the new node to be added
	doubly_linked_list_node *new_node = (doubly_linked_list_node *)malloc(sizeof(doubly_linked_list_node));

	// Defines the head of the linked list
	if (list->list_size == 0)
	{
		// Sets the value and next pointer of the head node
		list->head = new_node;
		(list->head)->value = insert_value;
		(list->head)->next = NULL;

		// Sets the node's previous reference to NULL
		(list->head)->previous = NULL;
		// Assigns the tail node to the head of the list
		list->tail = new_node;
	}
	else
	{
		new_node->value = (list->head)->value;
		new_node->next = (list->head)->next;
		new_node->previous = (list->head);

		(list->head)->value = insert_value;
		(list->head)->next = new_node;

		// Tail pointer is appropriately reassigned if nodes are only
		// added to the head of the list
		if ((list->head->next)->next == NULL)
		{
			list->tail = new_node;
		}
	}

	list->list_size++;
}

/*!
 * @brief Adds a node to the the end of the doubly linked list.
 * @param list Pointer to a doubly linked list struct.
 * @param insert_value Value to insert at the tail of the list.
 * @return None
 */
void add_dl_node_to_tail(doubly_linked_list *list, void *insert_value)
{
	// Linked list node pointer which represents the new node to be added
	doubly_linked_list_node *new_node = (doubly_linked_list_node *)malloc(sizeof(doubly_linked_list_node));

	if (list->list_size != 0)
	{
		// Sets the value of the new node
		new_node->value = insert_value;
		// Points to the node which will now be at the end of the list
		new_node->next = NULL;
		(list->tail)->next = new_node;

		// Sets the previous node to the original tail element
		new_node->previous = list->tail;
		list->tail = new_node;
	}
	// Defines the head of the linked list
	if (list->list_size == 0)
	{
		list->head = new_node;
		(list->head)->value = insert_value;
		(list->head)->next = NULL;
		(list->head)->previous = NULL;

		list->tail = new_node;
	}

	list->list_size++;
}

/*!
 * @brief Adds a node to a position after a specified node.
 * @param list Pointer to a doubly linked list struct.
 * @param insert_value Value to insert into the list.
 * @param insert_after_value The value of the element to insert an element after.
 * @return None
 */
void insert_dl_node(doubly_linked_list *list, int insert_value, void *insert_after_value)
{

	// Pointer used to hold a reference to the tail node in the list traversal
	doubly_linked_list_node *search_node = list->head;

	do
	{
		// Checks if the tail node has the value equal to the element to insert after
		if (search_node->value == insert_after_value)
		{
			// Pointer for the node to be inserted
			doubly_linked_list_node *new_node = (doubly_linked_list_node *)malloc(sizeof(doubly_linked_list_node));

			// Update the pointer to the current element if the element inserted after was the tail
			if (insert_after_value == (list->tail)->value)
			{
				list->tail = new_node;
			}
			// Inserts the new node
			new_node->value = insert_value;
			new_node->next = search_node->next;
			// Sets the previous reference of the new node
			new_node->previous = search_node;

			// Sets the previous pointer for the node after the newly inserted value node to the newly inserted node
			(search_node->next)->previous = new_node;

			// Updates the next reference of the node which was inserted after
			search_node->next = new_node;

			list->list_size++;
			break;
		}
		else
		{
			// Updates the pointer to the next node in the list
			search_node = search_node->next;
		}
	} while (search_node != NULL);
}

/*!
 * @brief Removes and returns the value of an element.
 * @param list Pointer to a doubly linked list struct.
 * @param removal_value Value to remove from the list.
 * @return The value of the element to be removed.
 */
void *remove_dl_node(doubly_linked_list *list, void *removal_value)
{
	// Place holder node used to hold the nodes as the list is traversed
	doubly_linked_list_node *search_node = list->head;
	// Pointer used to keep a reference to the previous node in the traversal
	doubly_linked_list_node *previous_node = list->head;
	// Integer to hold value of removed node
	void *removed_element;

	do
	{
		// Logic for if the node to remove is found
		if (search_node->value == removal_value)
		{
			// If the node is the head element, the head element is re-assigned
			if (search_node == list->head)
			{
				if (search_node->next != NULL)
				{
					// search node is assigned to the following node
					search_node = search_node->next;
					// The value and pointer of the head node are re-assigned
					(list->head)->value = search_node->value;
					(list->head)->next = search_node->next;
				}
			}
			else if (search_node == list->tail)
			{
				// Re-assign the pointer to the tail element
				list->tail = previous_node;
				// Re-assigns the previous node's next pointer
				previous_node->next = NULL;
			}
			// If the node to remove is any other element in the list
			else
			{
				// Re-assigns the next node's previous pointer
				(search_node->next)->previous = previous_node;
				// Re-assigns the previous node's next pointer
				previous_node->next = search_node->next;
			}

			removed_element = search_node->value;

			// Free memory held by removed node
			free(search_node);
			// Avoid dangling pointer
			search_node = NULL;

			list->list_size--;

			// If there are no elements in the list, free the memory held by the head and tail pointers
			if (list->list_size == 0)
			{
				free(list->head);
				// Avoid dangling pointer
				list->head = NULL;

				free(list->tail);
				list->tail = NULL;
			}

			return removed_element;
		}

		else if (search_node->value != removal_value && dl_list_length(list) != 0)
		{
			// If the current node is not the head node, the pointer to the previous element is re-assigned
			if (search_node->value != (list->head)->value)
			{
				previous_node = previous_node->next;
			}
			// The current node is updated to the next node in the list
			search_node = search_node->next;
		}

	} while (search_node != NULL);
}

/*!
 * @brief Frees the memory held by a doubly linked list struct
 * @param list Pointer to a doubly linked list struct
 * @return None
 */
void free_doubly_linked_list(doubly_linked_list *list)
{

	// Freeing only valid if there are elements in the list
	if (list->list_size != 0)
	{
		// Node pointer used to keep track of current node in list
		doubly_linked_list_node *node = list->head;
		// Array of node pointers
		doubly_linked_list_node *array[list->list_size];

		// Counter to add a node pointer to a position in the array
		int i = 0;

		// Traverse the linked list and add the nodes to the array
		while (node != NULL)
		{
			array[i] = node;
			// Update the pointer to the node in the traversal
			node = node->next;
			i++;
		}

		// Free the memory held by the nodes
		for (int j = 0; j < list->list_size; j++)
		{
			// Free the dynamically allocated memory held by the current node
			free(array[j]);
			// Avoid dangling pointer
			array[j] = NULL;
		}
	}
}

/*!
 * @brief Prints the contents of the doubly linked list to the terminal. If the type
 *        of element added to the linked list remains constant for a given implementation, this
 *        can be uncommented and used
 * @param list Pointer to a doubly linked list struct.
 * @return None
 */
// void display_dl_list(doubly_linked_list *list)
// {
// 	// If the list is empty, NULL is printed
// 	if (list->list_size == 0)
// 	{
// 		printf("\nNULL");
// 	}
// 	// If the list is not empty, the list is traversed and the elements are printed to the terminal
// 	else
// 	{
// 		doubly_linked_list_node *node = list->head;
// 		printf("\n");
// 		printf("NULL<=>");

// 		do
// 		{
// 			printf("%d<=>", node->value);
// 			node = node->next;
// 		} while (node != NULL);

// 		printf("NULL");
// 	}
// }
