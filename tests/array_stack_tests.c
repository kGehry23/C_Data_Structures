/**
 ********************************************************************************
 * @file    array_stack_tests.c
 * @author  Kai Gehry
 * @date    2025-08-05
 *
 * @brief   Test the operations defined in the array_stack.c file.
 ********************************************************************************
 */

/************************************
 * DEFINES
 ************************************/
#define STACK_SIZE 5

/************************************
 * INCLUDES
 ************************************/
#include <assert.h>
#include "../data_structures/stacks/array_stack/array_stack.h"

/************************************
 * TESTS
 ************************************/

/*!
 * @brief Tests initialization of an array stack
 * @return  None
 */
void init_test()
{
    array_stack stack;

    initialize_array_stack(&stack, STACK_SIZE);

    assert(stack.size == STACK_SIZE);
    assert(stack.top_index == 0);
    assert(stack.stack_pointer == 0);

    // Frees the dynamically allocated memory for the internal array
    free_array_stack(&stack);
}

/*!
 * @brief Tests freeing of dynamically allocated memory within the stack
 * @return  None
 */
void free_test()
{
    array_stack stack;

    initialize_array_stack(&stack, STACK_SIZE);

    // Frees the dynamically allocated memory for the internal array
    free_array_stack(&stack);

    assert(stack.array == NULL);
}

/*!
 * @brief Tests if the stack is empty
 * @return  None
 */
void empty_test()
{
    array_stack stack;

    initialize_array_stack(&stack, STACK_SIZE);

    assert(stack_is_empty(&stack) == true);

    // Frees the dynamically allocated memory for the internal array
    free_array_stack(&stack);
}

/*!
 * @brief Checks the number of elements in an empty the stack
 * @return  None
 */
void empty_num_elements_test()
{
    array_stack stack;

    initialize_array_stack(&stack, STACK_SIZE);

    assert(stack_size(&stack) == 0);

    // Frees the dynamically allocated memory for the internal array
    free_array_stack(&stack);
}

/*!
 * @brief Checks the return of the top element when the stack is empty
 * @return  None
 */
void peek_on_empty_test()
{
    array_stack stack;

    initialize_array_stack(&stack, STACK_SIZE);

    assert(peek(&stack) == NULL);

    // Frees the dynamically allocated memory for the internal array
    free_array_stack(&stack);
}

/*!
 * @brief Checks the result of popping when the stack is empty
 * @return  None
 */
void pop_on_empty_test()
{
    array_stack stack;

    initialize_array_stack(&stack, STACK_SIZE);

    assert(pop(&stack) == NULL);

    // Frees the dynamically allocated memory for the internal array
    free_array_stack(&stack);
}

/*!
 * @brief Checks the result of pushing one element onto the stack
 * @return  None
 */
void push_one_test(void *element)
{
    array_stack stack;

    initialize_array_stack(&stack, STACK_SIZE);

    push(&stack, element);

    assert(stack_size(&stack) == 1);
    assert(stack.top_index == 0);
    assert(stack.stack_pointer == 1);
    assert(peek(&stack) == element);

    // Frees the dynamically allocated memory for the internal array
    free_array_stack(&stack);
}

/*!
 * @brief Checks the result of pushing multiple elements onto the stack
 * @return  None
 */
void enqueue_multiple_test(void *val1, void *val2, void *val3, void *val4)
{
    array_stack stack;

    initialize_array_stack(&stack, STACK_SIZE);

    // Push multiple elements
    push(&stack, val1);
    push(&stack, val2);
    push(&stack, val3);
    push(&stack, val4);

    assert(stack_size(&stack) == 4);
    assert(stack.top_index == 3);
    assert(stack.stack_pointer == 4);
    assert(peek(&stack) == val4);

    free_array_stack(&stack);
}

/*!
 * @brief Checks the result of adding and removing multiple elements
 * @return  None
 */
void add_remove_multiple_test(void *val1, void *val2, void *val3, void *val4)
{
    array_stack stack;

    initialize_array_stack(&stack, STACK_SIZE);

    // Push multiple elements
    push(&stack, val1);
    push(&stack, val2);
    push(&stack, val3);
    push(&stack, val4);

    // Pop 2 elements
    pop(&stack);
    pop(&stack);

    assert(stack_size(&stack) == 2);
    assert(stack.top_index == 1);
    assert(stack.stack_pointer == 2);
    assert(peek(&stack) == val2);

    free_array_stack(&stack);
}

/*!
 * @brief Checks the result of adding, removing, and re-adding elements
 * @return  None
 */
void remove_re_add_test(void *val1, void *val2, void *val3, void *val4, void *val5)
{

    array_stack stack;

    initialize_array_stack(&stack, 4);

    // Push multiple elements
    push(&stack, val1);
    push(&stack, val2);
    push(&stack, val3);
    push(&stack, val4);

    // Pop the first 3 elements
    pop(&stack);
    pop(&stack);
    pop(&stack);

    // Add another element
    push(&stack, val5);

    assert(stack_size(&stack) == 2);
    assert(stack.top_index == 1);
    assert(stack.stack_pointer == 2);
    assert(peek(&stack) == val5);

    free_array_stack(&stack);
}

/*!
 * @brief Checks the result of adding and removing all elements added to the stack
 * @return  None
 */
void remove_all_test(void *val1, void *val2, void *val3, void *val4)
{
    array_stack stack;

    initialize_array_stack(&stack, 4);

    // Push multiple elements
    push(&stack, val1);
    push(&stack, val2);
    push(&stack, val3);
    push(&stack, val4);

    // Pop all elements
    pop(&stack);
    pop(&stack);
    pop(&stack);
    pop(&stack);

    assert(stack_size(&stack) == 0);
    assert(stack.top_index == 0);
    assert(stack.stack_pointer == 0);
    assert(peek(&stack) == NULL);

    free_array_stack(&stack);
}

/*!
 * @brief Checks the result of attempting to add an element beyond capacity
 * @return  None
 */
void add_beyond_capacity_test(void *val1, void *val2, void *val3, void *val4, void *val5)
{
    array_stack stack;

    initialize_array_stack(&stack, 4);

    // Enqueue multiple elements
    push(&stack, val1);
    push(&stack, val2);
    push(&stack, val3);
    push(&stack, val4);

    // Attempt to add an element beyond capacity
    push(&stack, val5);

    assert(stack_size(&stack) == 4);
    assert(stack.top_index == 3);
    assert(stack.stack_pointer == 3);

    free_array_stack(&stack);
}

int main(void)
{
    init_test();
    free_test();
    empty_test();

    empty_num_elements_test();
    peek_on_empty_test();
    pop_on_empty_test();

    push_one_test(1);
    push_one_test('a');
    push_one_test("Test");

    float f1 = 1.0f;
    push_one_test(&f1);

    double d1 = 1.0;
    push_one_test(&d1);

    enqueue_multiple_test(1, 2, 3, 4);
    enqueue_multiple_test('a', 'b', 'c', 'd');
    enqueue_multiple_test("Test1", "Test2", "Test3", "Test4");

    float f2 = 2.0f;
    float f3 = 3.0f;
    float f4 = 4.0f;
    enqueue_multiple_test(&f1, &f2, &f3, &f4);

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
    remove_re_add_test('a', 'b', 'c', 'd', 'e');
    remove_re_add_test("Test1", "Test2", "Test3", "Test4", "Test5");

    float f5 = 5.0f;
    remove_re_add_test(&f1, &f2, &f3, &f4, &f5);

    double d5 = 5.0;
    remove_re_add_test(&d1, &d2, &d3, &d4, &d5);

    remove_all_test(1, 2, 3, 4);
    remove_all_test('a', 'b', 'c', 'd');
    remove_all_test("Test1", "Test2", "Test3", "Test4");
    remove_all_test(&f1, &f2, &f3, &f4);
    remove_all_test(&d1, &d2, &d3, &d4);

    add_beyond_capacity_test(1, 2, 3, 4, 5);
    add_beyond_capacity_test('a', 'b', 'c', 'd', 'e');
    add_beyond_capacity_test("Test1", "Test2", "Test3", "Test4", "Test5");
    add_beyond_capacity_test(&f1, &f2, &f3, &f4, &f5);
    add_beyond_capacity_test(&d1, &d2, &d3, &d4, &d5);

    printf("\nArray stack tests passed.\n\n");

    return 0;
}