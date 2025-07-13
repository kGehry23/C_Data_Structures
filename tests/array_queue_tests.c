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

int main(void)
{
    init_test();
    free_test();
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

    float f1 = 1.105;
    enqueue_one_test(&f1);

    printf("\nAll tests passed.");

    return 0;
}
