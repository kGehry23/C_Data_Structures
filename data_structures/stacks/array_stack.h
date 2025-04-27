/**
 ********************************************************************************
 * @file    dropout_stack.h
 * @author  Kai Gehry
 * @date    2025-04-27
 *
 * @brief   Defines the operations on an array based stack.
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*!
 * @brief Struct which represents an array based stack.
 */
typedef struct
{
    int size;
    void *array;

} array_stack;

void initialize_array_stack(array_stack *stack, int num_elements)
{
    stack->size = 0;

    printf("Size of void: %d", sizeof(stack->array));
    // int test[num_elements];
    // printf("\nSize of test: %d", sizeof(test));
    // stack->array = (int (*)[num_elements])malloc(sizeof(int[num_elements]));
    // stack->array = &test;

    printf("Size: %d", sizeof(&stack->array));
}

void push(array_stack *stack, int value)
{
    // (&(stack->array))[stack->size] = value;
    // stack->size = stack->size + 1;
}

void pop(array_stack *stack)
{
}

void display_array_stack(array_stack *stack)
{

    for (int i = 0; i < stack->size; i++)
    {
        printf("%d\n", (&(stack->array))[i]);
    }
}