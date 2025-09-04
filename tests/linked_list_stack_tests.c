/**
 ********************************************************************************
 * @file    linked_list_stack_tests.c
 * @author  Kai Gehry
 * @date    2025-08-06
 *
 * @brief   Test the operations defined in the linked_list_stack.c file.
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/
#include <assert.h>
#include "../data_structures/stacks/linked_list_stack/linked_list_stack.h"

/************************************
 * TESTS
 ************************************/

/*!
 * @brief Tests initialization of a linked list stack
 * @param list  Pointer to a linked list stack
 * @return  None
 */
void init_test()
{
    linked_list_stack stack;

    initialize_stack(&stack);

    assert(stack.list.list_size == 0);
    assert(stack.list.head == NULL);
    assert(stack.list.tail == NULL);

    free_linked_list_stack(&stack);
}

/*!
 * @brief Tests the result of attempting to free memory on an empty linked list stack
 * @param list  Pointer to a linked list stack
 * @return  None
 */
void free_empty_test()
{
    linked_list_stack stack;

    initialize_stack(&stack);

    free_linked_list_stack(&stack);

    assert(stack.list.head == NULL);
    assert(stack.list.tail == NULL);
}

/*!
 * @brief Tests a return of the length function when the stack is empty
 * @param list  Pointer to the linked list stack
 * @return  None
 */
void empty_list_test()
{
    linked_list_stack stack;

    initialize_stack(&stack);

    assert(size(&stack) == 0);

    free_linked_list_stack(&stack);
}

/*!
 * @brief Tests if the stack is empty
 * @return  None
 */
void empty_test()
{
    linked_list_stack stack;

    initialize_stack(&stack);

    assert(is_empty(&stack) == true);

    free_linked_list_stack(&stack);
}

/*!
 * @brief Tests a return of the top element on an empty stack
 * @param list  Pointer to a linked list queue
 * @return  None
 */
void peek_on_empty_test()
{
    linked_list_stack stack;

    initialize_stack(&stack);

    assert(peek(&stack) == NULL);

    free_linked_list_stack(&stack);
}

/*!
 * @brief Checks the result of popping when the stack is empty
 * @return  None
 */
void pop_on_empty_test()
{
    linked_list_stack stack;

    initialize_stack(&stack);

    assert(pop(&stack) == NULL);

    free_linked_list_stack(&stack);
}

/*!
 * @brief Checks the result of pushing one element onto the stack
 * @return  None
 */
void push_one_test()
{
    linked_list_stack stack;

    initialize_stack(&stack);

    push(&stack, 1);

    assert(stack.list.head->value == 1);
    assert(stack.list.tail->value == 1);
    assert(size(&stack) == 1);
    assert(peek(&stack) == 1);

    free_linked_list_stack(&stack);
}

/*!
 * @brief Checks the result of pushing multiple elements onto the stack
 * @return  None
 */
void push_multiple_test(void *val1, void *val2, void *val3, void *val4)
{
    linked_list_stack stack;

    initialize_stack(&stack);

    // Enqueue multiple elements
    push(&stack, val1);
    push(&stack, val2);
    push(&stack, val3);
    push(&stack, val4);

    assert(size(&stack) == 4);
    assert(stack.list.tail->value == val1);
    assert(stack.list.head->value == val4);
    assert(peek(&stack) == val4);

    free_linked_list_stack(&stack);
}

/*!
 * @brief Checks the result of adding and removing multiple elements
 * @return  None
 */
void add_remove_multiple_test(void *val1, void *val2, void *val3, void *val4)
{
    linked_list_stack stack;

    initialize_stack(&stack);

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

    free_linked_list_stack(&stack);
}

/*!
 * @brief Checks the result of adding, removing, and re-adding elements
 * @return  None
 */
void remove_re_add_test(void *val1, void *val2, void *val3, void *val4, void *val5)
{

    linked_list_stack stack;

    initialize_stack(&stack);

    // Push multiple elements
    push(&stack, val1);
    push(&stack, val2);
    push(&stack, val3);
    push(&stack, val4);

    pop(&stack);
    pop(&stack);
    pop(&stack);

    // Add another element
    push(&stack, val5);

    assert(size(&stack) == 2);
    assert(stack.list.head->value == val5);
    assert(stack.list.tail->value == val1);
    assert(peek(&stack) == val5);

    free_linked_list_stack(&stack);
}

/*!
 * @brief Checks the result of adding and removing all elements added to the stack
 * @return  None
 */
void remove_all_test(void *val1, void *val2, void *val3, void *val4)
{

    linked_list_stack stack;

    initialize_stack(&stack);

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

    free_linked_list_stack(&stack);
}

int main(void)
{
    init_test();
    free_empty_test();
    empty_list_test();
    empty_test();

    peek_on_empty_test();
    pop_on_empty_test();
    push_one_test();

    push_multiple_test(1, 2, 3, 4);
    push_multiple_test('a', 'b', 'c', 'd');
    push_multiple_test("Test1", "Test2", "Test3", "Test4");

    double d1 = 1.0;
    double d2 = 2.0;
    double d3 = 3.0;
    double d4 = 4.0;

    push_multiple_test(&d1, &d2, &d3, &d4);

    float f1 = 1.0f;
    float f2 = 2.0f;
    float f3 = 3.0f;
    float f4 = 4.0f;

    push_multiple_test(&f1, &f2, &f3, &f4);

    add_remove_multiple_test(1, 2, 3, 4);
    add_remove_multiple_test('a', 'b', 'c', 'd');
    add_remove_multiple_test("Test1", "Test2", "Test3", "Test4");
    add_remove_multiple_test(&d1, &d2, &d3, &d4);
    add_remove_multiple_test(&f1, &f2, &f3, &f4);

    remove_re_add_test(1, 2, 3, 4, 5);
    remove_re_add_test('a', 'b', 'c', 'd', 'e');
    remove_re_add_test("Test1", "Test2", "Test3", "Test4", "Test5");

    double d5 = 5.0;
    remove_re_add_test(&d1, &d2, &d3, &d4, &d5);

    float f5 = 5.0f;
    remove_re_add_test(&f1, &f2, &f3, &f4, &f5);

    remove_all_test(1, 2, 3, 4);
    remove_all_test('a', 'b', 'c', 'd');
    remove_all_test("Test1", "Test2", "Test3", "Test4");
    remove_all_test(&d1, &d2, &d3, &d4);
    remove_all_test(&f1, &f2, &f3, &f4);

    printf("\nLinked list stack tests passed.\n\n");

    return 0;
}
