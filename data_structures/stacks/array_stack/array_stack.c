/**
 ********************************************************************************
 * @file    array_stack.h
 * @author  Kai Gehry
 * @date    2025-06-02
 *
 * @brief   Defines the operations on an array based stack.
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/
#include "array_stack.h"

/************************************
 * FUNCTION DEFINITIONS
 ************************************/

/*!
 * @brief Adds an element to the top of the stack
 * @param stack Pointer to a stack
 * @param element Element to add to the stack
 * @return None
 */
void push(array_stack *stack, void *element)
{
    if (stack->num_elements != stack->size)
    {
        // Assign the new value to the top of the stack
        (stack->array)[stack->stack_pointer] = element;
        // Update the stack pointer
        stack->top_index = stack->stack_pointer;

        // Increment the number of elements
        stack->num_elements++;

        if (stack->num_elements != stack->size)
        {
            stack->stack_pointer = (stack->top_index) + 1;
        }
    }
    // If the stack is full
    else
    {
        printf("\nCapacity reached");
    }
}

/*!
 * @brief Returns and removes the element at the top of the stack
 * @param stack Pointer to a stack
 * @return The element at the top of the stack
 */
void *pop(array_stack *stack)
{

    if (stack_size(stack) > 0)
    {
        // Get the element at the top of the stack
        void *top = (stack->array)[stack->top_index];
        // Sets the removed element to NULL
        (stack->array)[stack->top_index] = NULL;

        if (stack->num_elements > 1 && stack->num_elements < stack->size)
        {
            stack->stack_pointer = stack->stack_pointer - 1;
            stack->top_index = stack->top_index - 1;
        }
        // If only one element on the stack
        else if (stack->num_elements == 1)
        {
            stack->stack_pointer = stack->stack_pointer - 1;
        }
        // If the number of elements in the stack is equal to the stack size
        else if (stack->num_elements == stack->size)
        {
            stack->top_index = stack->top_index - 1;
        }

        stack->num_elements--;
        return top;
    }
    else
    {
        printf("\nStack empty");
        return NULL;
    }
}

/*!
 * @brief Returns but does not remove the element at the top of the stack
 * @param stack Pointer to a stack
 * @return Element at the top of the stack
 */
void *peek(array_stack *stack)
{
    if (stack_size(stack) == 0)
    {
        return NULL;
    }

    return (stack->array)[stack->top_index];
}

/*!
 * @brief Returns the size (number of elements) in the stack.
 * @param stack Pointer to a stack.
 * @return An integer value representing the number of elements in the stack.
 */
int stack_size(array_stack *stack)
{
    return (stack->num_elements);
}

/*!
 * @brief Returns if the stack is empty or not.
 * @param queue Pointer to a stack.
 * @return A boolean value representing if the stack is empty or not
 */
bool stack_is_empty(array_stack *stack)
{
    return (stack->num_elements) == 0;
}

/*!
 * @brief Initializes the stack.
 * @param stack Pointer to a stack
 * @param num_elements Number of allowable elements in the stack
 * @return None
 */
void initialize_array_stack(array_stack *stack, int stack_size)
{
    stack->size = stack_size;
    // Initialize the top element index of the stack to 0
    stack->top_index = 0;
    // Initialize stack pointer to 0
    stack->stack_pointer = 0;
    // Initialize the number of elements to 0
    stack->num_elements = 0;
    // Create an array of the specified size
    stack->array = malloc(stack_size * sizeof(void *));

    // Set all elements in the stack to NULL
    for (int i = 0; i < stack->size; i++)
    {
        stack->array[i] = NULL;
    }
}

/*!
 * @brief Frees the dynamically allocated memory for the stack
 * @param stack Pointer to a stack
 * @return None
 */
void free_array_stack(array_stack *stack)
{

    for (int i = 0; i < stack->num_elements; i++)
    {
        // Free each element as part of the array
        free(&(stack->array[i]));
    }

    // Frees the memory held by the stack
    free(stack->array);
    // Avoid dangling pointer
    stack->array = NULL;
}

/*!
 * @brief Prints the contents of the array based stack to the terminal. Can be
 *        uncommented if the type of the element to be stored remains constant.
 * @param stack Pointer to a stack
 * @return None
 */
// void display_stack(array_stack *stack)
// {
//     for (int i = (stack->size - 1); i >= 0; i--)
//     {
//         printf("\n%d", (stack->array)[i]);
//     }
// }