/**
 ********************************************************************************
 * @file    singly_linked_list.h
 * @author  Kai Gehry
 * @date    2025-03-25
 *
 * @brief   Defines the operations on a singly linked list.
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/
#include <stdio.h>
#include <stdlib.h>
#include "singly_linked_list_node.h"

/*!
 * @brief   Struct representing a singly linked list.
 */
typedef struct
{
    singly_linked_list_node *head;
    singly_linked_list_node *tail;
    int list_size;
} singly_linked_list;

/*!
 * @brief   Initializes a singly linked list type by setting its list_size variable to 0.
 * @param list  Pointer to the singly linked list being initalized.
 * @return  None
 */
void initialize_sl_list(singly_linked_list *list)
{
    list->list_size = 0;
}

/*!
 * @brief Prints the contents of the singly linked list to the terminal.
 * @param list Pointer to a singly linked list struct.
 * @return None
 */
void display_sl_list(singly_linked_list *list)
{
    // If the list is empty, NULL is printed
    if (list->list_size == 0)
    {
        printf("\nNULL");
    }
    // If the list is not empty, the list is traversed and the elements are printed to the terminal
    else
    {
        singly_linked_list_node *node = list->head;
        printf("\n");

        do
        {
            printf("%d->", node->value);
            node = node->next;
        } while (node != NULL);

        printf("NULL");
    }
}

/*!
 * @brief Returns the element at the tail of the singly linked list.
 * @param list Pointer to a singly linked list struct.
 * @return The value held at the tail of the linked list.
 */
int return_sl_tail(singly_linked_list *list)
{
    // Returns -1 if the list is empty
    if (list->list_size == 0)
        return -1;
    else
        return (list->tail)->value;
}

/*!
 * @brief Returns the element at the head of the singly linked list.
 * @param list Pointer to a singly linked list struct.
 * @return The value held at the head of the linked list.
 */
int return_sl_head(singly_linked_list *list)
{
    // Returns -1 is the list is empty
    if (list->list_size == 0)
        return -1;
    else
        return (list->head)->value;
}

/*!
 * @brief Returns the length of the singly linked list.
 * @param list Pointer to a singly linked list struct.
 * @return An integer representing the size of the linked list.
 */
int sl_list_length(singly_linked_list *list)
{
    return list->list_size;
}

/*!
 * @brief Adds a node to the front of the singly linked list.
 * @param list Pointer to a singly linked list struct.
 * @param insert_value Value to insert at the head of the list.
 * @return None
 */
void add_sl_node_to_head(singly_linked_list *list, int insert_value)
{
    // Linked list node pointer which represents the new node to be added
    singly_linked_list_node *new_node = (singly_linked_list_node *)malloc(sizeof(singly_linked_list_node));

    // Defines the head of the linked list
    if (list->list_size == 0)
    {
        // Sets the value and next pointer of the head node
        list->head = new_node;
        (list->head)->value = insert_value;
        (list->head)->next = NULL;
        // Assigns the tail node to the head of the list
        list->tail = new_node;
    }
    else
    {
        new_node->value = (list->head)->value;
        new_node->next = (list->head)->next;
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
 * @brief Adds a node to the the end of the singly linked list.
 * @param list Pointer to a singly linked list struct.
 * @param insert_value Value to insert at the tail of the list.
 * @return None
 */
void add_sl_node_to_tail(singly_linked_list *list, int insert_value)
{
    // Linked list node pointer which represents the new node to be added
    singly_linked_list_node *new_node = (singly_linked_list_node *)malloc(sizeof(singly_linked_list_node));

    if (list->list_size != 0)
    {
        // Sets the value of the new node
        new_node->value = insert_value;
        // Points to the node which will now be at the end of the list
        new_node->next = NULL;
        (list->tail)->next = new_node;

        list->tail = new_node;
    }
    // Defines the head of the linked list
    if (list->list_size == 0)
    {
        list->head = new_node;
        (list->head)->value = insert_value;
        (list->head)->next = NULL;

        list->tail = new_node;
    }

    list->list_size++;
}

/*!
 * @brief Adds a node to a position after a specified node.
 * @param list Pointer to a singly linked list struct.
 * @param insert_value Value to insert into the list.
 * @param insert_after_value The value of the element to insert an element after.
 * @return None
 */
void insert_sl_node(singly_linked_list *list, int insert_value, int insert_after_value)
{
    // Pointer for the node to be inserted
    singly_linked_list_node *new_node = (singly_linked_list_node *)malloc(sizeof(singly_linked_list_node));
    // Pointer used to hold a reference to the tail node in the list traversal
    singly_linked_list_node *search_node = list->head;

    do
    {
        // Checks if the tail node has the value equal to the element to insert after
        if (search_node->value == insert_after_value)
        {
            // Update the pointer to the current element if the element inserted after was the tail
            if (insert_after_value == (list->tail)->value)
            {
                list->tail = new_node;
            }
            // Inserts the new node
            new_node->value = insert_value;
            new_node->next = search_node->next;
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
 * @param list Pointer to a singly linked list struct.
 * @param removal_value Value to remove from the list.
 * @return The value of the element to be removed.
 */
int remove_sl_node(singly_linked_list *list, int removal_value)
{
    // Place holder node used to hold the nodes as the list is traversed
    singly_linked_list_node *search_node = list->head;
    // Pointer used to keep a reference to the previous node in the traversal
    singly_linked_list_node *previous_node = list->head;
    // Integer to hold value of removed node
    int removed_element;

    do
    {
        // Logic for if the node to remove is found
        if (search_node->value == removal_value)
        {
            // If the node is the head element, the head element is re-assigned
            if (search_node == (list->head))
            {
                // search node is assigned to the following node
                removed_element = search_node->value;
                search_node = search_node->next;
                // The value and pointer of the head node are re-assigned
                (list->head)->value = search_node->value;
                (list->head)->next = search_node->next;
            }
            else if (search_node == list->tail)
            {
                // Re-assign the pointer to the tail element
                list->tail = previous_node;
                // Free memory held by removed node
                free(search_node);
            }
            // If the node to remove is any other element in the list
            else
            {
                removed_element = search_node->value;
                // Re-assigns the previous node's pointer to point to the node after the node to remove
                previous_node->next = search_node->next;
                // Free memory held by removed node
                free(search_node);
            }

            list->list_size--;
            return removed_element;
        }

        // If the current node is not the head node, the pointer to the previous element is re-assigned
        if (search_node->value != (list->head)->value)
        {
            previous_node = previous_node->next;
        }

        // The current node is updated to the next node in the list
        search_node = search_node->next;

        // If the node is not found or there are no elements in the list, -1 is returned
        if (search_node == NULL || list->list_size == 0)
        {
            // Free memory held by removed node
            free(search_node);

            return -1;
        }
    } while (search_node != NULL);
}
