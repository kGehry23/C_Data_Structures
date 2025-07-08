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
void init_test(singly_linked_list *list)
{
    initialize_sl_list(list);

    // Checks that that the size of the list has been initialized to 0
    assert(list->list_size == 0);

    free_singly_linked_list(list);
}

/*!
 * @brief Tests freeing of dynamically allocated memory of a singly linked list
 * @param list  Pointer to the singly linked list
 * @return  None
 */
void free_test()
{
    singly_linked_list test_list;

    initialize_sl_list(&test_list);

    free_singly_linked_list(&test_list);

    // Checks that that the size of the list has been initialized to 0
    assert(&test_list == NULL);
}

/*!
 * @brief Tests a return of the length function when the list is empty
 * @param list  Pointer to the singly linked list
 * @return  None
 */
void empty_list_test(singly_linked_list *list)
{
    assert(sl_list_length(list) == 0);
}

/*!
 * @brief Tests a return of the head element on an empty list
 * @param list  Pointer to the singly linked list
 * @return  None
 */
void empty_head_test(singly_linked_list *list)
{
    assert(return_sl_head(list) == NULL);
}

/*!
 * @brief Tests a return of the tail element on an empty list
 * @param list  Pointer to the singly linked list
 * @return  None
 */
void empty_tail_test(singly_linked_list *list)
{
    assert(return_sl_tail(list) == NULL);
}

// remove from empty head test here

/*!
 * @brief Tests adding a node to the head of the list when empty
 * @param list  Pointer to the singly linked list
 * @return  None
 */
void add_node_h_empty_test(singly_linked_list *list)
{
    add_sl_node_to_head(list, 5);

    assert((list->head)->value == 5);
    assert((list->head)->next == NULL);
    // Check that the pointers to the head and tail elements are identical
    assert((list->head) == (list->tail));
}

/*!
 * @brief Tests a removal of the head element
 * @param list  Pointer to the singly linked list
 * @return  None
 */
void remove_test(singly_linked_list *list)
{
    assert(remove_sl_node(list, 5) == 5);
}

/*!
 * @brief Tests a removal of a node that does not exist
 * @param list  Pointer to the singly linked list
 * @return  None
 */
void remove_non_existent_test(singly_linked_list *list)
{
    add_sl_node_to_head(list, 6);
    assert(remove_sl_node(list, 10) == NULL);
    // Then, remove the node
    remove_sl_node(list, 6);
}

/*!
 * @brief Tests adding a node to the tail of the list when empty
 * @param list  Pointer to the singly linked list
 * @return  None
 */
void add_node_t_empty_test(singly_linked_list *list)
{
    add_sl_node_to_tail(list, 6);

    assert((list->tail)->value == 6);
    assert((list->tail)->next == NULL);
    // Check that the pointers to the head and tail elements are identical
    assert((list->tail) == (list->head));
}

/*!
 * @brief main function used to run the above tests
 */
int main(void)
{
    singly_linked_list list;

    // Tests initialization of a singly linked list
    init_test(&list);

    initialize_sl_list(&list);

    // Tests freeing the dynamically allocated memory for the singly linked list
    // free_test();

    // Checks the return for an empty list's length
    empty_list_test(&list);
    // Checks the return for accessing an empty list's tail
    empty_tail_test(&list);
    // Checks the return for accessing an empty list's head
    empty_head_test(&list);

    // Checks the result of adding a node to the head of the list
    add_node_h_empty_test(&list);

    // Removes a node from the head of the list with a single element added
    remove_test(&list);

    // Attempts to remove a node that does not exist from the list
    remove_non_existent_test(&list);

    // Tests addition to the tail of the list
    add_node_t_empty_test(&list);

    // Prints if no errors have occurred
    printf("All tests passed.");

    return 0;
}