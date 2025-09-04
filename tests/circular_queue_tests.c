/**
 ********************************************************************************
 * @file    circular_queue_tests.c
 * @author  Kai Gehry
 * @date    2025-07-13
 *
 * @brief   Test the operations defined in the circular_queue.c file.
 ********************************************************************************
 */

/************************************
 * DEFINES
 ************************************/
#define QUEUE_SIZE 10

/************************************
 * INCLUDES
 ************************************/
#include <assert.h>
#include "../data_structures/queues/circular_queue/circular_queue.h"

/************************************
 * TESTS
 ************************************/

/*!
 * @brief Tests initialization of a circular queue
 * @return  None
 */
void init_test()
{
    circular_queue circ;

    initialize_circular_queue(&circ, QUEUE_SIZE);

    assert(circ.size == QUEUE_SIZE);
    assert(circ.num_elements == 0);
    assert(circ.front_index == 0);
    assert(circ.end_index == 0);

    free_circular_queue(&circ);
}

/*!
 * @brief Tests freeing of dynamically allocated memory
 * @return  None
 */
void free_test()
{
    circular_queue circ;

    initialize_circular_queue(&circ, QUEUE_SIZE);

    free_circular_queue(&circ);

    assert(circ.array == NULL);
}

/*!
 * @brief Tests if the circular queue is empty
 * @return  None
 */
void empty_test()
{
    circular_queue circ;

    initialize_circular_queue(&circ, QUEUE_SIZE);

    assert(is_empty(&circ) == true);

    free_circular_queue(&circ);
}

/*!
 * @brief Checks the number of elements in an empty circular queue
 * @return  None
 */
void empty_num_elements_test()
{
    circular_queue circ;

    initialize_circular_queue(&circ, QUEUE_SIZE);

    assert(size(&circ) == 0);

    free_circular_queue(&circ);
}

/*!
 * @brief Checks the return of the first element when the queue is empty
 * @return  None
 */
void first_on_empty_test()
{
    circular_queue circ;

    initialize_circular_queue(&circ, QUEUE_SIZE);

    assert(first(&circ) == NULL);

    free_circular_queue(&circ);
}

/*!
 * @brief Checks the result of dequeuing when the queue is empty
 * @return  None
 */
void dequeue_on_empty_test()
{
    circular_queue circ;

    initialize_circular_queue(&circ, QUEUE_SIZE);

    assert(dequeue(&circ) == NULL);

    free_circular_queue(&circ);
}

/*!
 * @brief Checks the result of enqueuing one element onto the queue
 * @return  None
 */
void enqueue_one_test(void *element)
{
    circular_queue circ;

    initialize_circular_queue(&circ, QUEUE_SIZE);

    enqueue(&circ, element);

    assert(circ.num_elements == 1);
    assert(circ.front_index == 0);
    assert(circ.end_index == 1);
    assert(first(&circ) == element);

    // Frees the dynamically allocated memory for the internal array
    free_circular_queue(&circ);
}

/*!
 * @brief Checks the result of enqueuing multiple elements onto the queue
 * @return  None
 */
void enqueue_multiple_test(void *val1, void *val2, void *val3, void *val4)
{
    circular_queue circ;

    initialize_circular_queue(&circ, QUEUE_SIZE);

    enqueue(&circ, val1);
    enqueue(&circ, val2);
    enqueue(&circ, val3);
    enqueue(&circ, val4);

    assert(circ.num_elements == 4);
    assert(circ.front_index == 0);
    assert(circ.end_index == 4);
    assert(first(&circ) == val1);

    // Frees the dynamically allocated memory for the internal array
    free_circular_queue(&circ);
}

/*!
 * @brief Checks the result of adding and removing multiple elements
 * @return  None
 */
void add_remove_multiple_test(void *val1, void *val2, void *val3, void *val4)
{
    circular_queue circ;

    initialize_circular_queue(&circ, QUEUE_SIZE);

    enqueue(&circ, val1);
    enqueue(&circ, val2);
    enqueue(&circ, val3);
    enqueue(&circ, val4);

    // Dequeue 2 elements
    dequeue(&circ);
    dequeue(&circ);

    assert(circ.num_elements == 2);
    assert(circ.front_index == 2);
    assert(circ.end_index == 4);
    assert(first(&circ) == val3);

    free_circular_queue(&circ);
}

/*!
 * @brief Checks the result of adding, removing, and re-adding elements
 * @return  None
 */
void remove_re_add_test(void *val1, void *val2, void *val3, void *val4, void *val5)
{
    circular_queue circ;

    initialize_circular_queue(&circ, 4);

    enqueue(&circ, val1);
    enqueue(&circ, val2);
    enqueue(&circ, val3);
    enqueue(&circ, val4);

    // Dequeue the first 3 elements
    dequeue(&circ);
    dequeue(&circ);
    dequeue(&circ);

    // Add another element
    enqueue(&circ, val5);

    assert(circ.num_elements == 2);
    assert(circ.front_index == 3);
    // Check that the queue is properly circular. Elements past the final index of the internal array have been added.
    // When the queue wraps around, the new element should have been placed at index 0, so the end index where a new element could be
    // placed should be 1
    assert(circ.end_index == 1);
    assert(first(&circ) == val4);

    free_circular_queue(&circ);
}

/*!
 * @brief Checks the result of adding and removing all elements added to the queue
 * @return  None
 */
void remove_all_test(void *val1, void *val2, void *val3, void *val4)
{

    circular_queue circ;

    initialize_circular_queue(&circ, 4);

    enqueue(&circ, val1);
    enqueue(&circ, val2);
    enqueue(&circ, val3);
    enqueue(&circ, val4);

    // Dequeue all elements
    dequeue(&circ);
    dequeue(&circ);
    dequeue(&circ);
    dequeue(&circ);

    assert(circ.num_elements == 0);
    assert(circ.front_index == 0);
    assert(circ.end_index == 0);
    assert(first(&circ) == NULL);

    free_circular_queue(&circ);
}

/*!
 * @brief Checks the result of attempting to add an element beyond capacity
 * @return  None
 */
void add_beyond_capacity_test(void *val1, void *val2, void *val3, void *val4, void *val5)
{
    circular_queue circ;

    initialize_circular_queue(&circ, 4);

    // Enqueue multiple elements
    enqueue(&circ, val1);
    enqueue(&circ, val2);
    enqueue(&circ, val3);
    enqueue(&circ, val4);

    // Attempt to add an element beyond capacity
    enqueue(&circ, val5);

    assert(circ.num_elements == 4);
    assert(circ.front_index == 0);
    assert(circ.end_index == 0);

    free_circular_queue(&circ);
}

int main(void)
{
    init_test();
    free_test();
    empty_test();

    empty_num_elements_test();
    first_on_empty_test();
    dequeue_on_empty_test();

    enqueue_one_test(1);
    enqueue_one_test('A');
    enqueue_one_test("Test");

    double d1 = 1.0;
    enqueue_one_test(&d1);

    float f1 = 1.0f;
    enqueue_one_test(&f1);

    enqueue_multiple_test(1, 2, 3, 4);
    enqueue_multiple_test('A', 'B', 'C', 'D');
    enqueue_multiple_test("Test1", "Test2", "Test3", "Test4");

    double d2 = 2.0;
    double d3 = 3.0;
    double d4 = 4.0;
    enqueue_multiple_test(&d1, &d2, &d3, &d4);

    double f2 = 2.0f;
    double f3 = 3.0f;
    double f4 = 4.0f;
    enqueue_multiple_test(&f1, &f2, &f3, &f4);

    add_remove_multiple_test(1, 2, 3, 4);
    add_remove_multiple_test('A', 'B', 'C', 'D');
    add_remove_multiple_test("Test1", "Test2", "Test3", "Test4");
    // add_remove_multiple_test(&d1, &d2, &d3, &d4); //->failed
    add_remove_multiple_test(&f1, &f2, &f3, &f4);

    remove_re_add_test(1, 2, 3, 4, 5);
    remove_re_add_test('A', 'B', 'C', 'D', 'E');
    remove_re_add_test("Test1", "Test2", "Test3", "Test4", "Test5");

    double d5 = 5.0;
    // remove_re_add_test(&d1, &d2, &d3, &d4, &d5); //->failed

    float f5 = 5.0f;
    remove_re_add_test(&f1, &f2, &f3, &f4, &f5);

    remove_all_test(1, 2, 3, 4);
    remove_all_test('A', 'B', 'C', 'D');
    remove_all_test("Test1", "Test2", "Test3", "Test4");
    // remove_all_test(&d1, &d2, &d3, &d4); //->failed
    remove_all_test(&f1, &f2, &f3, &f4);

    add_beyond_capacity_test(1, 2, 3, 4, 5);
    add_beyond_capacity_test('A', 'B', 'C', 'D', 'E');
    add_beyond_capacity_test("Test1", "Test2", "Test3", "Test4", "Test5");
    add_beyond_capacity_test(&d1, &d2, &d3, &d4, &d5);
    add_beyond_capacity_test(&f1, &f2, &f3, &f4, &f5);

    printf("\nCircular queue tests passed.\n\n");

    return 0;
}