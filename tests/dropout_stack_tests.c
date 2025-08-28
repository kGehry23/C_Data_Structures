/**
 ********************************************************************************
 * @file    dropout_stack_tests.c
 * @author  Kai Gehry
 * @date    2025-08-10
 *
 * @brief   Test the operations defined in the dropout_stack.c file.
 ********************************************************************************
 */

/************************************
 * DEFINES
 ************************************/
#define LIMIT 4

/************************************
 * INCLUDES
 ************************************/
#include <assert.h>
#include "../data_structures/stacks/dropout_stack/dropout_stack.h"

/************************************
 * TESTS
 ************************************/

/*!
 * @brief Tests initialization of a dropout stack
 * @param list  Pointer to a dropout stack
 * @return  None
 */
void init_test()
{
    dropout_stack stack;

    initialize_do_stack(&stack, LIMIT);

    assert(stack.list.list_size == 0);
    assert(stack.stack_limit == LIMIT);
    assert(stack.list.head == NULL);
    assert(stack.list.tail == NULL);

    free_do_stack(&stack);
}

/*!
 * @brief Tests the result of attempting to free memory on an empty dropout stack
 * @param list  Pointer to a dropout stack
 * @return  None
 */
void free_empty_test()
{
    dropout_stack stack;

    initialize_do_stack(&stack, LIMIT);

    free_do_stack(&stack);

    assert(stack.list.head == NULL);
    assert(stack.list.tail == NULL);
}

/*!
 * @brief Tests if the stack is empty
 * @return  None
 */
void empty_test()
{
    dropout_stack stack;

    initialize_do_stack(&stack, LIMIT);

    assert(is_empty(&stack) == true);

    free_do_stack(&stack);
}

/*!
 * @brief Tests a return of the top element on an empty stack
 * @param list  Pointer to a linked list queue
 * @return  None
 */
void peek_on_empty_test()
{
    dropout_stack stack;

    initialize_do_stack(&stack, LIMIT);

    assert(peek(&stack) == NULL);

    free_do_stack(&stack);
}

/*!
 * @brief Checks the result of popping when the stack is empty
 * @return  None
 */
void pop_on_empty_test()
{
    dropout_stack stack;

    initialize_do_stack(&stack, LIMIT);

    assert(pop(&stack) == NULL);

    free_do_stack(&stack);
}

/*!
 * @brief Checks the result of pushing one element onto the stack
 * @return  None
 */
void push_one_test()
{
    dropout_stack stack;

    initialize_do_stack(&stack, LIMIT);

    push(&stack, 1);

    assert(stack.list.head->value == 1);
    assert(stack.list.tail->value == 1);
    assert(size(&stack) == 1);
    assert(peek(&stack) == 1);

    free_do_stack(&stack);
}

/*!
 * @brief Checks the result of pushing a number of elements equal to the limit onto
 *        onto the stack.
 * @return  None
 */
void push_limit_test(void *val1, void *val2, void *val3, void *val4)
{
    dropout_stack stack;

    initialize_do_stack(&stack, LIMIT);

    // Push multiple elements
    push(&stack, val1);
    push(&stack, val2);
    push(&stack, val3);
    push(&stack, val4);

    assert(size(&stack) == 4);
    assert(stack.list.tail->value == val1);
    assert(stack.list.head->value == val4);
    assert(peek(&stack) == val4);

    free_do_stack(&stack);
}

/*!
 * @brief Checks the result of pushing more elements than the limit onto the stack. Will expect the bottom
 *        element to be dropped off on each addition past the limit.
 * @return  None
 */
void push_one_past_limit_test(void *val1, void *val2, void *val3, void *val4, void *val5)
{
    dropout_stack stack;

    initialize_do_stack(&stack, LIMIT);

    // Push multiple elements
    push(&stack, val1);
    push(&stack, val2);
    push(&stack, val3);
    push(&stack, val4);

    // Will expect bottom item to be dropped off, therefore, val2 should be at
    // the bottom of the stack
    push(&stack, val5);

    assert(size(&stack) == 4);
    // Checks if val1 has been successfully dropped off
    assert(stack.list.tail->value == val2);
    assert(stack.list.head->value == val5);
    assert(peek(&stack) == val5);

    free_do_stack(&stack);
}

/*!
 * @brief Checks the result of pushing more elements than the limit onto the stack. Will expect the bottom
 *        element to be dropped off on each addition past the limit.
 * @return  None
 */
void push_multiple_past_limit_test(void *val1, void *val2, void *val3, void *val4, void *val5)
{
    dropout_stack stack;

    initialize_do_stack(&stack, LIMIT);

    // Push multiple elements
    push(&stack, val1);
    push(&stack, val2);
    push(&stack, val3);
    push(&stack, val4);

    push(&stack, val5);
    push(&stack, val1);
    push(&stack, val2);

    assert(size(&stack) == 4);
    // Val 3 should be the tail element
    assert(stack.list.tail->value == val4);
    assert(stack.list.head->value == val2);
    assert(peek(&stack) == val2);

    free_do_stack(&stack);
}

/*!
 * @brief Checks the result of adding and removing multiple elements
 * @return  None
 */
void add_remove_multiple_test(void *val1, void *val2, void *val3, void *val4)
{
    dropout_stack stack;

    initialize_do_stack(&stack, LIMIT);

    // Push multiple elements
    push(&stack, val1);
    push(&stack, val2);
    push(&stack, val3);
    push(&stack, val4);

    pop(&stack);
    pop(&stack);

    assert(size(&stack) == 2);
    assert(stack.list.tail->value == val1);
    assert(stack.list.head->value == val2);
    assert(peek(&stack) == val2);

    free_do_stack(&stack);
}

/*!
 * @brief Checks the result of adding, removing, and re-adding elements
 * @return  None
 */
void remove_re_add_test(void *val1, void *val2, void *val3, void *val4, void *val5, void *val6)
{

    dropout_stack stack;

    initialize_do_stack(&stack, LIMIT);

    // Push multiple elements
    push(&stack, val1);
    push(&stack, val2);
    push(&stack, val3);
    push(&stack, val4);
    push(&stack, val5);

    pop(&stack);
    pop(&stack);
    pop(&stack);

    // Add another element
    push(&stack, val6);

    assert(size(&stack) == 2);
    assert(stack.list.head->value == val6);
    assert(stack.list.tail->value == val2);
    assert(peek(&stack) == val6);

    free_do_stack(&stack);
}

/*!
 * @brief Checks the result of adding and removing all elements added to the stack
 * @return  None
 */
void remove_all_test(void *val1, void *val2, void *val3, void *val4)
{

    dropout_stack stack;

    initialize_do_stack(&stack, LIMIT);

    // Pushes multiple elements
    push(&stack, val1);
    push(&stack, val2);
    push(&stack, val3);
    push(&stack, val4);

    // Pop all elements
    pop(&stack);
    pop(&stack);
    pop(&stack);
    pop(&stack);

    assert(size(&stack) == 0);
    assert(stack.list.head == NULL);
    assert(stack.list.tail == NULL);
    assert(peek(&stack) == NULL);

    free_do_stack(&stack);
}

int main(void)
{
    init_test();
    free_empty_test();
    empty_test();

    peek_on_empty_test();
    pop_on_empty_test();
    push_one_test();

    push_limit_test(1, 2, 3, 4);
    push_limit_test('a', 'b', 'c', 'd');
    push_limit_test("Test1", "Test2", "Test3", "Test4");

    double d1 = 1.0;
    double d2 = 2.0;
    double d3 = 3.0;
    double d4 = 4.0;

    push_limit_test(&d1, &d2, &d3, &d4);

    float f1 = 1.0f;
    float f2 = 2.0f;
    float f3 = 3.0f;
    float f4 = 4.0f;

    push_limit_test(&f1, &f2, &f3, &f4);

    push_one_past_limit_test(1, 2, 3, 4, 5);
    push_one_past_limit_test('a', 'b', 'c', 'd', 'e');
    push_one_past_limit_test("Test1", "Test2", "Test3", "Test4", "Test5");

    double d5 = 5.0;
    push_one_past_limit_test(&d1, &d2, &d3, &d4, &d5);

    float f5 = 5.0f;
    push_one_past_limit_test(&f1, &f2, &f3, &f4, &f5);

    push_multiple_past_limit_test(1, 2, 3, 4, 5);
    push_multiple_past_limit_test('a', 'b', 'c', 'd', 'e');
    push_multiple_past_limit_test("Test1", "Test2", "Test3", "Test4", "Test5");
    push_one_past_limit_test(&d1, &d2, &d3, &d4, &d5);
    push_one_past_limit_test(&f1, &f2, &f3, &f4, &f5);

    add_remove_multiple_test(1, 2, 3, 4);
    add_remove_multiple_test('a', 'b', 'c', 'd');
    add_remove_multiple_test("Test1", "Test2", "Test3", "Test4");
    add_remove_multiple_test(&d1, &d2, &d3, &d4);
    add_remove_multiple_test(&f1, &f2, &f3, &f4);

    remove_re_add_test(1, 2, 3, 4, 5, 6);
    remove_re_add_test('a', 'b', 'c', 'd', 'e', 'f');
    remove_re_add_test("Test1", "Test2", "Test3", "Test4", "Test5", "Test6");

    double d6 = 6.0;
    remove_re_add_test(&d1, &d2, &d3, &d4, &d5, &d6);

    float f6 = 6.0f;
    remove_re_add_test(&f1, &f2, &f3, &f4, &f5, &f6);

    remove_all_test(1, 2, 3, 4);
    add_remove_multiple_test('a', 'b', 'c', 'd');
    add_remove_multiple_test("Test1", "Test2", "Test3", "Test4");
    add_remove_multiple_test(&d1, &d2, &d3, &d4);
    add_remove_multiple_test(&f1, &f2, &f3, &f4);

    printf("\nAll tests passed.");
    return 0;
}