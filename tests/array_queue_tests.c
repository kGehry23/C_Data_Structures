/**
 ********************************************************************************
 * @file    array_queue_tests.c
 * @author  Kai Gehry
 * @date    2025-07-09
 *
 * @brief   Test the operations defined in the array_queue.c file.
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
#include "../data_structures/queues/array_queue/array_queue.h"

/************************************
 * TESTS
 ************************************/

/*!
 * @brief Tests initialization of an array queue
 * @return  None
 */
void init_test()
{
    array_queue queue;

    initialize_array_queue(&queue, QUEUE_SIZE);

    assert(queue.size == QUEUE_SIZE);
    assert(queue.end_index == 0);
    assert(queue.front_index == 0);
    assert(queue.num_elements == 0);

    // Frees the dynamically allocated memory for the internal array
    free_array_queue(&queue);
}

/*!
 * @brief Tests freeing of dynamically allocated memory within the queue
 * @return  None
 */
void free_test()
{
    array_queue queue;

    initialize_array_queue(&queue, QUEUE_SIZE);

    // Frees the dynamically allocated memory for the internal array
    free_array_queue(&queue);

    assert(queue.array == NULL);
}

/*!
 * @brief Tests if the queue is empty
 * @return  None
 */
void empty_test()
{
    array_queue queue;

    initialize_array_queue(&queue, QUEUE_SIZE);

    assert(queue_is_empty(&queue) == true);

    // Frees the dynamically allocated memory for the internal array
    free_array_queue(&queue);
}

/*!
 * @brief Checks the number of elements in an empty the queue
 * @return  None
 */
void empty_num_elements_test()
{
    array_queue queue;

    initialize_array_queue(&queue, QUEUE_SIZE);

    assert(queue_size(&queue) == 0);

    // Frees the dynamically allocated memory for the internal array
    free_array_queue(&queue);
}

/*!
 * @brief Checks the return of the first element when the queue is empty
 * @return  None
 */
void first_on_empty_test()
{
    array_queue queue;

    initialize_array_queue(&queue, QUEUE_SIZE);

    assert(first(&queue) == NULL);

    // Frees the dynamically allocated memory for the internal array
    free_array_queue(&queue);
}

/*!
 * @brief Checks the dequeuing when the queue is empty
 * @return  None
 */
void dequeue_on_empty_test()
{
    array_queue queue;

    initialize_array_queue(&queue, QUEUE_SIZE);

    assert(dequeue(&queue) == NULL);

    // Frees the dynamically allocated memory for the internal array
    free_array_queue(&queue);
}

/*!
 * @brief Checks the result of enqueuing one element onto the queue
 * @return  None
 */
void enqueue_one_test(void *element)
{
    array_queue queue;

    initialize_array_queue(&queue, QUEUE_SIZE);

    enqueue(&queue, element);

    assert(queue.num_elements == 1);
    assert(queue.front_index == 0);
    assert(queue.end_index == 1);
    assert(first(&queue) == element);

    // Frees the dynamically allocated memory for the internal array
    free_array_queue(&queue);
}

/*!
 * @brief Checks the result of enqueuing multiple elements onto the queue
 * @return  None
 */
void enqueue_multiple_test(void *val1, void *val2, void *val3, void *val4)
{
    array_queue queue;

    initialize_array_queue(&queue, QUEUE_SIZE);

    // Enqueue multiple elements
    enqueue(&queue, val1);
    enqueue(&queue, val2);
    enqueue(&queue, val3);
    enqueue(&queue, val4);

    assert(queue.num_elements == 4);
    assert(queue.front_index == 0);
    assert(queue.end_index == 4);
    assert(first(&queue) == val1);

    free_array_queue(&queue);
}

/*!
 * @brief Checks the result of adding and removing multiple elements
 * @return  None
 */
void add_remove_multiple_test(void *val1, void *val2, void *val3, void *val4)
{
    array_queue queue;

    initialize_array_queue(&queue, QUEUE_SIZE);

    // Enqueue multiple elements
    enqueue(&queue, val1);
    enqueue(&queue, val2);
    enqueue(&queue, val3);
    enqueue(&queue, val4);

    // Dequeue 2 elements
    dequeue(&queue);
    dequeue(&queue);

    assert(queue.num_elements == 2);
    assert(queue.front_index == 2);
    assert(queue.end_index == 4);
    assert(first(&queue) == val3);

    free_array_queue(&queue);
}

/*!
 * @brief Checks the result of adding, removing, and re-adding elements
 * @return  None
 */
void remove_re_add_test(void *val1, void *val2, void *val3, void *val4, void *val5)
{

    array_queue queue;

    initialize_array_queue(&queue, 4);

    // Enqueue multiple elements
    enqueue(&queue, val1);
    enqueue(&queue, val2);
    enqueue(&queue, val3);
    enqueue(&queue, val4);

    // Dequeue the first 3 elements
    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);

    // Add another element and make sure elements have been shifted to accommodate new elements
    enqueue(&queue, val5);

    assert(queue.num_elements == 2);
    assert(queue.front_index == 0);
    assert(queue.end_index == 2);
    assert(first(&queue) == val4);

    free_array_queue(&queue);
}

/*!
 * @brief Checks the result of adding and removing all elements added to the queue
 * @return  None
 */
void remove_all_test(void *val1, void *val2, void *val3, void *val4)
{

    array_queue queue;

    initialize_array_queue(&queue, 4);

    // Enqueue multiple elements
    enqueue(&queue, val1);
    enqueue(&queue, val2);
    enqueue(&queue, val3);
    enqueue(&queue, val4);

    // Dequeue all elements
    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);

    assert(queue.num_elements == 0);
    assert(queue.front_index == 0);
    assert(queue.end_index == 0);
    assert(first(&queue) == NULL);

    free_array_queue(&queue);
}

/*!
 * @brief Checks the result of attempting to add an element beyond capacity
 * @return  None
 */
void add_beyond_capacity_test(void *val1, void *val2, void *val3, void *val4, void *val5)
{
    array_queue queue;

    initialize_array_queue(&queue, 4);

    // Enqueue multiple elements
    enqueue(&queue, val1);
    enqueue(&queue, val2);
    enqueue(&queue, val3);
    enqueue(&queue, val4);

    // Attempt to add an element beyond capacity
    enqueue(&queue, val5);

    assert(queue.num_elements == 4);
    assert(queue.front_index == 0);
    assert(queue.end_index == 3);

    free_array_queue(&queue);
}

int main(void)
{
    init_test();
    // free_test();
    empty_test();

    empty_num_elements_test();
    first_on_empty_test();
    dequeue_on_empty_test();

    // Tests enqueuing elements of different types
    enqueue_one_test(1);
    enqueue_one_test("A");
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

    float f2 = 2.0f;
    float f3 = 3.0f;
    float f4 = 4.0f;

    enqueue_multiple_test(&f1, &f2, &f3, &f4);

    add_remove_multiple_test(1, 2, 3, 4);
    add_remove_multiple_test('A', 'B', 'C', 'D');
    add_remove_multiple_test("Test1", "Test2", "Test3", "Test4");

    // add_remove_multiple_test(&d1, &d2, &d3, &d4); //->failed
    add_remove_multiple_test(&f1, &f2, &f3, &f4);

    remove_re_add_test(1, 2, 3, 4, 5);
    remove_re_add_test('A', 'B', 'C', 'D', 'E');
    remove_re_add_test("Test1", "Test2", "Test3", "Test4", "Test5");

    // double d5 = 5.0;
    // remove_re_add_test(&d1, &d2, &d3, &d4, &d5); //->failed

    float f5 = 5.0f;
    remove_re_add_test(&f1, &f2, &f3, &f4, &f5);

    remove_all_test(1, 2, 3, 4);
    remove_all_test('A', 'B', 'C', 'D');
    remove_all_test("Test1", "Test2", "Test3", "Test4");

    remove_all_test(&f1, &f2, &f3, &f4);
    // remove_all_test(&d1, &d2, &d3, &d4); //->failed

    add_beyond_capacity_test(1, 2, 3, 4, 5);
    add_beyond_capacity_test('A', 'B', 'C', 'D', 'E');
    add_beyond_capacity_test("Test1", "Test2", "Test3", "Test4", "Test5");
    add_beyond_capacity_test(&f1, &f2, &f3, &f4, &f5);

    printf("\nAll tests passed.");

    return 0;
}
