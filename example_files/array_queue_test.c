/**
 ********************************************************************************
 * @file    array_stack_test.c
 * @author  Kai Gehry
 * @date    2025-06-02
 *
 * @brief   Tests the functionality of the operations defined in
 *          the array_stack header file.
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/
#include <stdio.h>
#include "../data_structures/queues/array_queue.h"

/*!
 * @brief main function used to test the functionality of the array_queue header file.
 */
int main(void)
{
    array_queue queue;

    initialize_array_queue(&queue, 5);

    enqueue(&queue, 1);

    return 0;
}