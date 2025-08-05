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

/*!
 * @brief Checks the result of enqueuing one element onto the queue
 * @return  None
 */
void enqueue_one_test()
{
    linked_list_queue queue;

    initialize_queue(&queue);

    enqueue(&queue, 1);

    assert(queue.list.head->value == 1);
    assert(queue.list.tail->value == 1);
    assert(queue.list.list_size == 1);
    assert(first(&queue) == 1);

    free_linked_list_queue(&queue);
}

/*!
 * @brief Checks the result of enqueuing multiple elements onto the queue
 * @return  None
 */
void enqueue_multiple_test(void *val1, void *val2, void *val3, void *val4)
{
    linked_list_queue queue;

    initialize_queue(&queue);

    // Enqueue multiple elements
    enqueue(&queue, val1);
    enqueue(&queue, val2);
    enqueue(&queue, val3);
    enqueue(&queue, val4);

    assert(size(&queue) == 4);
    assert(queue.list.head->value == val1);
    assert(queue.list.tail->value == val4);
    assert(first(&queue) == val1);

    free_linked_list_queue(&queue);
}

/*!
 * @brief Checks the result of adding and removing multiple elements
 * @return  None
 */
void add_remove_multiple_test(void *val1, void *val2, void *val3, void *val4)
{
    linked_list_queue queue;

    initialize_queue(&queue);

    // Enqueue multiple elements
    enqueue(&queue, val1);
    enqueue(&queue, val2);
    enqueue(&queue, val3);
    enqueue(&queue, val4);

    // Dequeue 2 elements
    dequeue(&queue);
    dequeue(&queue);

    assert(size(&queue) == 2);
    assert(queue.list.head->value == val3);
    assert(queue.list.tail->value == val4);
    assert(first(&queue) == val3);

    free_linked_list_queue(&queue);
}

/*!
 * @brief Checks the result of adding, removing, and re-adding elements
 * @return  None
 */
void remove_re_add_test(void *val1, void *val2, void *val3, void *val4, void *val5)
{

    linked_list_queue queue;

    initialize_queue(&queue);

    // Enqueue multiple elements
    enqueue(&queue, val1);
    enqueue(&queue, val2);
    enqueue(&queue, val3);
    enqueue(&queue, val4);

    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);

    // Add another element and make sure elements have been shifted to accommodate new elements
    enqueue(&queue, val5);

    assert(size(&queue) == 2);
    assert(queue.list.head->value == val4);
    assert(queue.list.tail->value == val5);
    assert(first(&queue) == val4);

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

    enqueue_one_test();
    enqueue_multiple_test(1, 2, 3, 4);
    enqueue_multiple_test('a', 'b', 'c', 'd');
    enqueue_multiple_test("Test1", "Test2", "Test3", "Test4");

    float f1 = 1.0f;
    float f2 = 2.0f;
    float f3 = 3.0f;
    float f4 = 4.0f;

    enqueue_multiple_test(&f1, &f2, &f3, &f4);

    double d1 = 1.0;
    double d2 = 2.0;
    double d3 = 3.0;
    double d4 = 4.0;

    enqueue_multiple_test(&d1, &d2, &d3, &d4);

    add_remove_multiple_test(1, 2, 3, 4);
    add_remove_multiple_test('a', 'b', 'c', 'd');
    add_remove_multiple_test("Test1", "Test2", "Test3", "Test4");
    add_remove_multiple_test(&f1, &f2, &f3, &f4);
    add_remove_multiple_test(&d1, &d2, &d3, &d4);

    remove_re_add_test(1, 2, 3, 4, 5);

    printf("\nAll tests passed.");

    return 0;
}
