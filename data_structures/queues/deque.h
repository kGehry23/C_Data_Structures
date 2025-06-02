/**
 ********************************************************************************
 * @file    deque.h
 * @author  Kai Gehry
 * @date    2025-04-06
 *
 * @brief   Defines the operations on a deque.
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/
#include <stdio.h>
#include <stdbool.h>
#include "../linked_lists/doubly_linked_list/doubly_linked_list.h"

/************************************
 * COMPILER DIRECTIVES
 ************************************/
// Added for void* to required type conversions
#pragma GCC diagnostic ignored "-Wint-conversion"

/*!
 * @brief Struct which represents a deque.
 */
typedef struct
{
    doubly_linked_list list;
} linked_deque;

/*!
 * @brief Initializes the deque.
 * @param deque Pointer to a deque.
 * @return None
 */
void initialize_deque(linked_deque *deque)
{
    deque->list.list_size = 0;
}

/*!
 * @brief Adds an item to the head of the deque.
 * @param deque Pointer to a deque.
 * @param value Value to add to the deque.
 * @return None
 */
void enqueue_head(linked_deque *deque, void *value)
{
    add_dl_node_to_head(&(deque->list), value);
}

/*!
 * @brief Adds an item to the tail of the deque.
 * @param deque Pointer to a deque.
 * @param value Value to add to the deque.
 * @return None
 */
void enqueue_tail(linked_deque *deque, void *value)
{
    add_dl_node_to_tail(&(deque->list), value);
}

/*!
 * @brief Removes an item from the head of the deque and returns its value.
 * @param deque Pointer to a deque.
 * @return Removes and returns the item at the head of the deque
 */
int dequeue_head(linked_deque *deque)
{
    return remove_dl_node(&(deque->list), ((deque->list).head)->value);
}

/*!
 * @brief Removes an item from the tail of the deque and returns its value.
 * @param deque Pointer to a deque.
 * @return Removes and returns the item at the tail of the deque
 */
int dequeue_tail(linked_deque *deque)
{
    return remove_dl_node(&(deque->list), ((deque->list).tail)->value);
}

/*!
 * @brief Returns the element at the front of the deque.
 * @param deque Pointer to a deque.
 * @return A value representing the value stored by the node at the head of deque.
 */
int front(linked_deque *deque)
{
    return return_dl_head(&(deque->list));
}

/*!
 * @brief Returns the element at the back of the deque.
 * @param deque Pointer to a deque.
 * @return A value representing the value stored by the node at the back of deque.
 */
int back(linked_deque *deque)
{
    return return_dl_tail(&(deque->list));
}

/*!
 * @brief Returns the size (number of elements) in the deque.
 * @param deque Pointer to a deque.
 * @return An integer value representing the number of elements in the deque.
 */
int size(linked_deque *deque)
{
    return dl_list_length(&(deque->list));
}

/*!
 * @brief Returns if the deque is empty or not.
 * @param deque Pointer to a deque.
 * @return A boolean value representing if the deque is empty (1) or not empty (0).
 */
bool is_empty(linked_deque *deque)
{
    return dl_list_length(&(deque->list)) == 0;
}

// /*!
//  * @brief Displays the contents of the deque. Can be uncommented if
//  *        data type to be added remains constant.
//  * @param deque Pointer to a deque.
//  * @return None
//  */
// void display_deque(linked_deque *deque)
// {
//     display_dl_list(&(deque->list));
// }
