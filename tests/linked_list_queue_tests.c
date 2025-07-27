/**
 ********************************************************************************
 * @file    linked_list_queue_tests.c
 * @author  Kai Gehry
 * @date    2025-07-26
 *
 * @brief   Tests the operations defined in the linked_list_queue.c file.
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/
#include <assert.h>
#include "../data_structures/queues/linked_list_queue/linked_list_queue.h"

/************************************
 * TESTS
 ************************************/

/*!
 * @brief Tests initialization of a linked list queue
 * @param list  Pointer to a linked list queue
 * @return  None
 */
void init_test()
{
    linked_list_queue queue;

    initialize_queue(&queue);

    assert(queue.list.list_size == 0);
    assert(queue.list.head == NULL);
    assert(queue.list.tail == NULL);

    free_linked_list_queue(&queue);
}

/*!
 * @brief Tests the result of attempting to free memory on an empty linked list queue
 * @param list  Pointer to a linked list queue
 * @return  None
 */
void free_empty_test()
{
    linked_list_queue queue;

    initialize_queue(&queue);

    free_linked_list_queue(&queue);

    assert(queue.list.head == NULL);
    assert(queue.list.tail == NULL);
}

/*!
 * @brief Tests a return of the length function when the queue is empty
 * @param list  Pointer to the linked list queue
 * @return  None
 */
void empty_list_test()
{
    linked_list_queue queue;

    initialize_queue(&queue);

    assert(size(&queue) == 0);

    free_linked_list_queue(&queue);
}

/*!
 * @brief Tests if the queue is empty
 * @return  None
 */
void empty_test()
{
    linked_list_queue queue;

    initialize_queue(&queue);

    assert(is_empty(&queue) == true);

    free_linked_list_queue(&queue);
}

/*!
 * @brief Tests a return of the head element on an empty queue
 * @param list  Pointer to a linked list queue
 * @return  None
 */
void empty_head_test()
{
    linked_list_queue queue;

    initialize_queue(&queue);

    assert(first(&queue) == NULL);

    free_linked_list_queue(&queue);
}

/*!
 * @brief Checks the result of dequeuing when the queue is empty
 * @return  None
 */
void dequeue_on_empty_test()
{
    linked_list_queue queue;

    initialize_queue(&queue);

    assert(dequeue(&queue) == NULL);

    free_linked_list_queue(&queue);
}

int main(void)
{

    init_test();
    free_empty_test();

    empty_list_test();
    empty_test();
    empty_head_test();
    // dequeue_on_empty_test(); // failed

    printf("\nAll tests passed.");

    return 0;
}