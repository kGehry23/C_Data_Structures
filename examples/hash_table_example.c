/**
 ********************************************************************************
 * @file    hash_table_example.c
 * @author  Kai Gehry
 * @date    2025-05-30
 *
 * @brief   Tests the functionality of the operations defined in
 *          the hash_table header file.
 ********************************************************************************
 */

/************************************
 * DEFINES
 ************************************/
#define INIT_TABLE_SIZE 5
#define LOAD_FACTOR 0.5

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
    initialize_hash_table(&table, INIT_TABLE_SIZE, LOAD_FACTOR, 0);

    // Add key value pairs
    put(&table, 756473, 4);
    put(&table, 756472, 3);
    put(&table, 756478, 1);
    printf("\nValue for key 756473: %d", get(&table, 756473));
    printf("\nValue for key 756472: %d", get(&table, 756472));
    printf("\nValue for key 756478: %d\n", get(&table, 756478));

    printf("\nNum elems: %d", table.num_elements);

    // Table is resized at this point
    put(&table, 657435, 2);  // Hashes to index 5
    put(&table, 712345, 12); // Hashes to index 5, and will cause a collision
    put(&table, 756479, 5);

    printf("\nValue for key 756473: %d", get(&table, 756473));
    printf("\nValue for key 756472: %d", get(&table, 756472));
    printf("\nValue for key 756478: %d", get(&table, 756478));
    printf("\nValue for key 657435: %d", get(&table, 657435));
    printf("\nValue for key 712345: %d", get(&table, 712345));
    printf("\nValue for key 756479: %d\n", get(&table, 756479));

    // Remove hashed elements
    remove_hash(&table, 756479);

    // Check resulting return values once an element has been removed
    printf("\n\nValue for key 756478: %d", get(&table, 756478));
    printf("\nValue for key 657435: %d", get(&table, 657435));
    printf("\nValue for key 756479: %s", get(&table, 756479));

    // Return the number of elements at different indices in the table
    printf("\n\nSize: %d", table.num_elements);
    // Return the percentage of the table occupied
    printf("\nPercent Occupied: %f", percent_occupied(&table));

    // Free the memory held by the hash table
    free_hash_table(&table);

    return 0;
}
