/**
 ********************************************************************************
 * @file    hash_table_tests.c
 * @author  Kai Gehry
 * @date    2025-08-27
 *
 * @brief   Test the operations defined in the hash_table.c file.
 ********************************************************************************
 */

/************************************
 * DEFINES
 ************************************/
#define NUM_ELEMS 10

/************************************
 * INCLUDES
 ************************************/
#include <assert.h>
#include "../data_structures/hash_table/hash_table.h"

/************************************
 * TESTS
 ************************************/

/*!
 * @brief Tests initialization of a hash table
 * @return  None
 */
void init_test()
{
    hash_table table;

    initialize_hash_table(&table, NUM_ELEMS, 0);

    assert(table.table_size == NUM_ELEMS);

    for (int i = 0; i < NUM_ELEMS; i++)
    {
        assert(((table.array)[i]).key == NULL);
        assert(((table.array)[i]).next == NULL);
        assert(((table.array)[i]).previous == NULL);
    }

    free_hash_table(&table);
}

/*!
 * @brief Tests the result of attempting to free memory on an empty hash table
 * @return  None
 */
void free_empty_test()
{
    hash_table table;

    initialize_hash_table(&table, NUM_ELEMS, 0);

    free_hash_table(&table);

    assert(table.array == NULL);
}

/*!
 * @brief Tests the result adding and checking the result of the addition of an element.
 * @return  None
 */
void put_single_element_test()
{
    hash_table table;

    initialize_hash_table(&table, NUM_ELEMS, 0);

    // Maps the string "Test" to the integer 1
    put(&table, "Test", 1);

    assert(table.num_elements == 1);
    assert(get(&table, "Test") == 1);

    free_hash_table(&table);
}

/*!
 * @brief Tests the result adding and checking the result of the addition of multiple elements.
 * @return  None
 */
void put_multiple_elements_test()
{
    hash_table table;

    initialize_hash_table(&table, NUM_ELEMS, 0);

    put(&table, "Test1", 1);
    put(&table, "Test2", 2);
    put(&table, "Test3", 3);

    assert(table.num_elements == 3);

    assert(get(&table, "Test1") == 1);
    assert(get(&table, "Test2") == 2);
    assert(get(&table, "Test3") == 3);

    free_hash_table(&table);
}

int main(void)
{
    init_test();
    free_empty_test();

    put_single_element_test();
    put_multiple_elements_test();

    printf("\nAll tests passed.");

    return 0;
}
