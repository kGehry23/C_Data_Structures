/**
 ********************************************************************************
 * @file    array_stack_tests.c
 * @author  Kai Gehry
 * @date    2025-08-04
 *
 * @brief   Test the operations defined in the array_stack.c file.
 ********************************************************************************
 */

/************************************
 * DEFINES
 ************************************/
#define STACK_SIZE 10

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

int main(void)
{
    init_test();
    free_test();
    empty_test();

    empty_num_elements_test();
    peek_on_empty_test();
    pop_on_empty_test();

    push_one_test(1);

    printf("\nAll tests passed");

    return 0;
}