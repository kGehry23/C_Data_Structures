/**
 ********************************************************************************
 * @file    deque_tests.c
 * @author  Kai Gehry
 * @date    2025-07-13
 *
 * @brief   Test the operations defined in the deque.c file.
 ********************************************************************************
 */

/************************************
 * DEFINES
 ************************************/
#define DEQUE_SIZE 10

/************************************
 * INCLUDES
 ************************************/
#include <assert.h>
#include "../data_structures/queues/deque/deque.h"

/************************************
 * TESTS
 ************************************/

/*!
 * @brief Tests initialization of a deque
 * @return  None
 */
void init_test()
{
    linked_deque deque;

    initialize_deque(&deque);

    assert(deque.list.list_size == 0);
    assert(deque.list.head == NULL);
    assert(deque.list.tail == NULL);

    free_deque(&deque);
}

/*!
 * @brief Tests freeing of dynamically allocated memory within the deque
 * @return  None
 */
void free_test()
{
    linked_deque deque;

    initialize_deque(&deque);

    free_deque(&deque);

    assert(deque.list.head == NULL);
    assert(deque.list.tail == NULL);
}

/*!
 * @brief Tests if the deque is empty
 * @return  None
 */
void empty_test()
{
    linked_deque deque;

    initialize_deque(&deque);

    assert(is_empty(&deque) == true);

    free_deque(&deque);
}

/*!
 * @brief Checks the number of elements in an empty the deque
 * @return  None
 */
void empty_num_elements_test()
{
    linked_deque deque;

    initialize_deque(&deque);

    assert(size(&deque) == 0);

    free_deque(&deque);
}

/*!
 * @brief Checks the return of the first element when the deque is empty
 * @return  None
 */
void front_on_empty_test()
{
    linked_deque deque;

    initialize_deque(&deque);

    assert(front(&deque) == NULL);

    free_deque(&deque);
}

/*!
 * @brief Checks the result of dequeuing from the head when the deque is empty
 * @return  None
 */
void dequeue_head_on_empty_test()
{
    linked_deque deque;

    initialize_deque(&deque);

    assert(dequeue_head(&deque) == NULL);

    free_deque(&deque);
}

/*!
 * @brief Checks the result of dequeuing from the tail when the deque is empty
 * @return  None
 */
void dequeue_tail_on_empty_test()
{
    linked_deque deque;

    initialize_deque(&deque);

    assert(dequeue_tail(&deque) == NULL);

    free_deque(&deque);
}

/*!
 * @brief Checks the result of enqueuing one element onto the head of the deque
 * @return  None
 */
void enqueue_one_head_test(void *element)
{
    linked_deque deque;

    initialize_deque(&deque);

    enqueue_head(&deque, element);

    assert(size(&deque) == 1);
    assert(front(&deque) == element);
    assert(back(&deque) == element);

    free_deque(&deque);
}

/*!
 * @brief Checks the result of enqueuing one element onto the tail of the deque
 * @return  None
 */
void enqueue_one_tail_test(void *element)
{
    linked_deque deque;

    initialize_deque(&deque);

    enqueue_tail(&deque, element);

    assert(size(&deque) == 1);
    assert(front(&deque) == element);
    assert(back(&deque) == element);

    free_deque(&deque);
}

/*!
 * @brief Checks the result of enqueuing multiple elements onto the deque
 * @return  None
 */
void enqueue_multiple_test(void *val1, void *val2, void *val3, void *val4)
{
    linked_deque deque;

    initialize_deque(&deque);

    enqueue_head(&deque, val1);
    enqueue_tail(&deque, val2);
    enqueue_head(&deque, val3);
    enqueue_tail(&deque, val4);

    assert(size(&deque) == 4);
    assert(front(&deque) == val3);
    assert(back(&deque) == val4);

    free_deque(&deque);
}

int main(void)
{
    init_test();
    free_test();
    empty_test();

    empty_num_elements_test();
    front_on_empty_test();
    dequeue_head_on_empty_test();
    dequeue_tail_on_empty_test();

    enqueue_one_head_test(1);
    enqueue_one_head_test('A');
    enqueue_one_head_test("Test");

    double d1 = 1.0;
    enqueue_one_head_test(&d1);

    double f1 = 1.0f;
    enqueue_one_head_test(&f1);

    enqueue_one_tail_test(1);
    enqueue_one_tail_test('A');
    enqueue_one_tail_test("Test");
    enqueue_one_tail_test(&d1);
    enqueue_one_tail_test(&f1);

    enqueue_multiple_test(1, 2, 3, 4);
    enqueue_multiple_test('A', 'B', 'C', 'D');

    printf("\nDequeue tests passed.\n\n");

    return 0;
}