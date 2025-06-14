/**
 ********************************************************************************
 * @file    deque.h
 * @author  Kai Gehry
 * @date    2025-04-06
 *
 * @brief   Defines the structure and operations defined on a deque.
 ********************************************************************************
 */

#ifndef DEQUE_H
#define DEQUE_H

/************************************
 * INCLUDES
 ************************************/
#include <stdbool.h>
#include "data_structures/linked_lists/doubly_linked_list/doubly_linked_list.c"

/************************************
 * COMPILER DIRECTIVES
 ************************************/
// Added for void* to required type conversions
#pragma GCC diagnostic ignored "-Wint-conversion"

/************************************
 * TYPEDEFS
 ************************************/

/*!
 * @brief Struct which represents a deque.
 */
typedef struct
{
    // Doubly linked list to store the elements within the deque
    doubly_linked_list list;
} linked_deque;

/************************************
 * FUNCTION PROTOTYPES
 ************************************/

/*!
 * @brief Initializes the deque.
 * @param deque Pointer to a deque.
 * @return None
 */
void initialize_deque(linked_deque *deque);

/*!
 * @brief Adds an item to the head of the deque.
 * @param deque Pointer to a deque.
 * @param value Value to add to the deque.
 * @return None
 */
void enqueue_head(linked_deque *deque, void *value);

/*!
 * @brief Adds an item to the tail of the deque.
 * @param deque Pointer to a deque.
 * @param value Value to add to the deque.
 * @return None
 */
void enqueue_tail(linked_deque *deque, void *value);

/*!
 * @brief Removes an item from the head of the deque and returns its value.
 * @param deque Pointer to a deque.
 * @return Removes and returns the item at the head of the deque
 */
int dequeue_head(linked_deque *deque);

/*!
 * @brief Removes an item from the tail of the deque and returns its value.
 * @param deque Pointer to a deque.
 * @return Removes and returns the item at the tail of the deque
 */
int dequeue_tail(linked_deque *deque);
/*!
 * @brief Returns the element at the front of the deque.
 * @param deque Pointer to a deque.
 * @return A value representing the value stored by the node at the head of deque.
 */
int front(linked_deque *deque);

/*!
 * @brief Returns the element at the back of the deque.
 * @param deque Pointer to a deque.
 * @return A value representing the value stored by the node at the back of deque.
 */
int back(linked_deque *deque);

/*!
 * @brief Returns the size (number of elements) in the deque.
 * @param deque Pointer to a deque.
 * @return An integer value representing the number of elements in the deque.
 */
int size(linked_deque *deque);

/*!
 * @brief Returns if the deque is empty or not.
 * @param deque Pointer to a deque.
 * @return A boolean value representing if the deque is empty (1) or not empty (0).
 */
bool is_empty(linked_deque *deque);

/*!
 * @brief Displays the contents of the deque. Can be uncommented if
 *        data type to be added remains constant.
 * @param deque Pointer to a deque.
 * @return None
 */
void display_deque(linked_deque *deque);

#endif // DEQUE_H