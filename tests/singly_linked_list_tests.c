/**
 ********************************************************************************
 * @file    singly_linked_list_tests.c
 * @author  Kai Gehry
 * @date    2025-07-06
 *
 * @brief   Test the operations defined in the singly_linked_list.c file.
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/
#include <assert.h>
#include "../data_structures/linked_lists/singly_linked_list/singly_linked_list.h"

/************************************
 * TESTS
 ************************************/

/*!
 * @brief Tests initialization of a singly linked list
 * @param list  Pointer to the singly linked list
 * @return  None
 */
void init_test()
{
    singly_linked_list list;

    // Initialize the list
    initialize_sl_list(&list);

    // Checks that that the size of the list has been initialized to 0
    assert(list.list_size == 0);
    // Checks that the head pointer is initialized to NULL
    assert(list.head == NULL);
    // Checks that the tail pointer is initialized to NULL
    assert(list.tail == NULL);
}

/*!
 * @brief Tests the result of attempting to free memory on an empty list
 * @param list  Pointer to the singly linked list
 * @return  None
 */
void free_empty()
{
    singly_linked_list list;

    // Initialize the list
    initialize_sl_list(&list);

    free_singly_linked_list(&list);

    assert(list.head == NULL);
    assert(list.tail == NULL);
}

/*!
 * @brief Tests a return of the length function when the list is empty
 * @param list  Pointer to the singly linked list
 * @return  None
 */
void empty_list_test()
{
    singly_linked_list list;

    // Initialize the list
    initialize_sl_list(&list);

    assert(sl_list_length(&list) == 0);
}

/*!
 * @brief Tests a return of the head element on an empty list
 * @param list  Pointer to the singly linked list
 * @return  None
 */
void empty_head_test()
{
    singly_linked_list list;

    // Initialize the list
    initialize_sl_list(&list);

    assert(return_sl_head(&list) == NULL);
}

/*!
 * @brief Tests a return of the tail element on an empty list
 * @param list  Pointer to the singly linked list
 * @return  None
 */
void empty_tail_test()
{
    singly_linked_list list;

    // Initialize the list
    initialize_sl_list(&list);

    assert(return_sl_tail(&list) == NULL);
}

// remove from empty head test here

/*!
 * @brief Tests adding a node to the head of the list when empty
 * @param list  Pointer to the singly linked list
 * @return  None
 */
void add_node_h_empty_test()
{
    singly_linked_list list;

    // Initialize the list
    initialize_sl_list(&list);
    // Adds an element to the head of the list
    add_sl_node_to_head(&list, 5);

    // Check that the assigned value is correct
    assert((list.head)->value == 5);
    // Check that the next element is set to NULL
    assert((list.head)->next == NULL);
    // Check that the pointers to the head and tail elements are identical
    assert((list.head) == (list.tail));

    // Frees the dynamically allocated memory as part of the list
    free_singly_linked_list(&list);
}

/*!
 * @brief Tests adding a node to the tail of the list when empty
 * @param list  Pointer to the singly linked list
 * @return  None
 */
void add_node_t_empty_test()
{
    singly_linked_list list;

    // Initialize the list
    initialize_sl_list(&list);
    // Adds a node to the tail of the list
    add_sl_node_to_tail(&list, 6);

    /// Check that the assigned value is correct
    assert((list.tail)->value == 6);
    // Check that the next element is set to NULL
    assert((list.tail)->next == NULL);
    // Check that the pointers to the head and tail elements are identical
    assert((list.tail) == (list.head));
}

/*!
 * @brief Tests a removal of the head element
 * @param list  Pointer to the singly linked list
 * @return  None
 */
void remove_test()
{
    singly_linked_list list;

    // Initialize the list
    initialize_sl_list(&list);
    // Adds an element to the head of the list
    add_sl_node_to_head(&list, 5);

    assert(remove_sl_node(&list, 5) == 5);
}

/*!
 * @brief Tests a removal of a node that does not exist
 * @param list  Pointer to the singly linked list
 * @return  None
 */
void remove_non_existent_test()
{
    singly_linked_list list;

    // Initialize the list
    initialize_sl_list(&list);
    // Adds a node to the head of the list
    add_sl_node_to_head(&list, 6);

    // Attempts to remove a node that does not exist
    assert(remove_sl_node(&list, 10) == NULL);

    // Frees the dynamically allocated memory as part of the list
    free_singly_linked_list(&list);
}

/*!
 * @brief Adds multiple elements to the head and tail of the list
 * @param list  Pointer to the singly linked list
 * @return  None
 */
void add_multiple_test()
{
    singly_linked_list list;

    // Initialize the list
    initialize_sl_list(&list);

    // Add elements to the head
    add_sl_node_to_head(&list, 1);
    add_sl_node_to_head(&list, 2);

    // Adds elements to the tail
    add_sl_node_to_tail(&list, 3);
    add_sl_node_to_tail(&list, 4);

    // Checks that the number of elements in the list is correct
    assert(list.list_size == 4);
    // Checks that the value of the node at the head of the list is correct
    assert((list.head)->value == 2);
    // Checks that the value of the node at the head of the list is correct
    assert((list.tail)->value == 4);

    // Frees the dynamically allocated memory as part of the list
    free_singly_linked_list(&list);
}

/*!
 * @brief Adds and removes multiple elements to/from the head and tail of the list
 * @param list  Pointer to the singly linked list
 * @return  None
 */
void add_remove_multiple_test()
{
    singly_linked_list list;

    // Initialize the list
    initialize_sl_list(&list);

    // Add elements to the head
    add_sl_node_to_head(&list, 1);
    add_sl_node_to_head(&list, 2);

    // Adds elements to the tail
    add_sl_node_to_tail(&list, 3);
    add_sl_node_to_tail(&list, 4);

    // Removes the node at the head of the list
    remove_sl_node(&list, 1);
    // Removes the node at the tail of the list
    remove_sl_node(&list, 4);

    // Checks that the number of elements in the list is correct
    assert(list.list_size == 2);
    // Checks that the value of the node at the head of the list is correct
    assert((list.head)->value == 2);
    // Checks that the value of the node at the tail of the list is correct
    assert((list.tail)->value == 3);

    // Frees the dynamically allocated memory as part of the list
    free_singly_linked_list(&list);
}

/*!
 * @brief Adds multiple elements to the head and tail of the list and removes them all
 * @param list  Pointer to the singly linked list
 * @return  None
 */
void add_remove_all_test()
{
    singly_linked_list list;

    // Initialize the list
    initialize_sl_list(&list);

    add_sl_node_to_head(&list, 1);
    add_sl_node_to_head(&list, 2);
    add_sl_node_to_head(&list, 3);
    add_sl_node_to_head(&list, 4);
    add_sl_node_to_head(&list, 5);

    // Removes all added nodes
    remove_sl_node(&list, 1);
    remove_sl_node(&list, 2);
    remove_sl_node(&list, 3);
    remove_sl_node(&list, 4);
    remove_sl_node(&list, 5);

    // Checks that the size of the list is 0
    assert(list.list_size == 0);
    // Check that the head element is set to NULL
    assert(list.head == NULL);
    // Check that the tail element is set to NULL
    assert(list.head == NULL);
}

/*!
 * @brief Removes all elements and adds elements back again
 * @param list  Pointer to the singly linked list
 * @return  None
 */
void remove_all_add_again_test()
{
    singly_linked_list list;

    // Initialize the list
    initialize_sl_list(&list);

    add_sl_node_to_head(&list, 1);
    add_sl_node_to_head(&list, 2);

    // Removes all added nodes
    remove_sl_node(&list, 1);
    remove_sl_node(&list, 2);

    // Re-adds elements
    add_sl_node_to_head(&list, 5);
    add_sl_node_to_tail(&list, 6);

    // Checks that the number of elements in the list is correct
    assert(list.list_size == 2);
    // Checks that the value of the node at the head of the list is correct
    assert((list.head)->value == 5);
    // Checks that the value of the node at the tail of the list is correct
    assert((list.tail)->value == 6);

    free_singly_linked_list(&list);
}

/*!
 * @brief Removes an element from the middle of the list
 * @param list  Pointer to the singly linked list
 * @return  None
 */
void remove_middle()
{
    singly_linked_list list;

    // Initialize the list
    initialize_sl_list(&list);

    add_sl_node_to_head(&list, 1);
    add_sl_node_to_tail(&list, 2);
    add_sl_node_to_tail(&list, 3);

    // Removes the element at the middle of the list
    remove_sl_node(&list, 2);

    // Checks that the number of elements in the list is correct
    assert(list.list_size == 2);
    // Checks that the value held by the node at the head of the list is correct
    assert((list.head)->value == 1);
    // Checks that the value held by the node at the tail of the list is correct
    assert((list.tail)->value == 3);
    // Checks that the head elements points to the correct node after removal
    assert(((list.head)->next)->value == 3);
}

/*!
 * @brief Runs the above tests
 */
int main(void)
{
    init_test();
    free_empty();

    empty_list_test();
    empty_head_test();
    empty_tail_test();

    add_node_h_empty_test();
    add_node_t_empty_test();

    remove_test();
    remove_non_existent_test();

    add_multiple_test();
    add_remove_multiple_test();
    add_remove_all_test();
    remove_all_add_again_test();
    remove_middle();

    // Prints only if all tests pass
    printf("All tests passed.");

    return 0;
}