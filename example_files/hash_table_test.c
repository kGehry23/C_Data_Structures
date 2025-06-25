/**
 ********************************************************************************
 * @file    hash_table.h
 * @author  Kai Gehry
 * @date    2025-05-30
 *
 * @brief   Tests the functionality of the operations defined in
 *          the hash_table header file.
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/
#include <stdio.h>
#include "../data_structures/hash_table/hash_table.h"

/*!
 * @brief main function used to test the functionality of the hash_table header file.
 */
int main(void)
{
    hash_table table;

    // Initialize the hash table
    initialize_hash_table(&table, 5, 0);

    // Add key value pairs
    put(&table, 756473, 4);
    put(&table, 756472, 3);
    put(&table, 756471, 2);
    put(&table, 756478, 1);
    put(&table, 657435, 7);

    // Return the values associated with specified keys
    printf("\nValue for key 756473: %d", get(&table, 756473));
    printf("\nValue for key 756471: %d", get(&table, 756471));
    printf("\nValue for key 756478: %d", get(&table, 756478));
    printf("\nValue for key 657435: %d", get(&table, 657435));

    // Remove hashed elements
    remove_hash(&table, 756473);
    remove_hash(&table, 756471);

    // Check resulting return values once an element has been removed
    printf("\n\nValue for key 756473: %s", get(&table, 756473));
    printf("\nValue for key 756471: %d", get(&table, 756471));
    printf("\nValue for key 756478: %d", get(&table, 756478));
    printf("\nValue for key 657435: %d", get(&table, 657435));

    // Return the number of elements at different indices in the table
    printf("\n\nSize: %d", table.num_elements);
    // Return the percentage of the table occupied
    printf("\nPercent Occupied: %.2f", percent_occupied(&table));

    // Free the memory held by the hash table
    free_hash_table(&table);

    return 0;
}
