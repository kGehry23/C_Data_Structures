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

/*!
 * @brief Tests the result adding and checking the result of the addition of multiple elements.
 * @return  None
 */
void remove_on_empty_test()
{
    hash_table table;

    initialize_hash_table(&table, NUM_ELEMS, 0);

    // Will need to modify this to make this work properly. Will currently loop forever
    remove_hash(&table, "Test");

    free_hash_table(&table);
}

/*!
 * @brief Tests the result removing a hash in the table
 * @return  None
 */
void remove_hash_test()
{
    hash_table table;

    initialize_hash_table(&table, NUM_ELEMS, 0);

    put(&table, "Test", 1);
    assert(table.num_elements == 1);
    assert(get(&table, "Test") == 1);

    remove_hash(&table, "Test");
    assert(table.num_elements == 0);
    assert(get(&table, "Test") == NULL);

    free_hash_table(&table);
}

/*!
 * @brief Tests the result of removing multiple hashes in the table
 * @return  None
 */
void remove_multiple_hashes_test()
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

    remove_hash(&table, "Test1");
    remove_hash(&table, "Test2");
    remove_hash(&table, "Test3");

    assert(table.num_elements == 0);
    assert(get(&table, "Test1") == NULL);
    assert(get(&table, "Test2") == NULL);
    assert(get(&table, "Test3") == NULL);

    free_hash_table(&table);
}

/*!
 * @brief Tests the result of when two elements hash to the same location.
 * @return  None
 */
void hash_to_same_location_test()
{
    hash_table table;

    initialize_hash_table(&table, NUM_ELEMS, 0);

    // Both elements hash to the same hash table index (2) with a table size of
    // 10 using the division method
    put(&table, 12, "Test1");
    put(&table, 2, "Test2");

    // Result should be 1 as only one index has been used
    assert(table.num_elements == 1);
    assert(get(&table, 12) == "Test1");
    assert(get(&table, 2) == "Test2");

    free_hash_table(&table);
}

/*!
 * @brief Tests the result of when two elements hash to the same location and are then removed.
 * @return  None
 */
void hash_to_same_location_remove_test()
{
    hash_table table;

    initialize_hash_table(&table, NUM_ELEMS, 0);

    // Both elements hash to the same hash table index (2) with a table size of
    // 10 using the division method
    put(&table, 12, "Test1");
    put(&table, 2, "Test2");

    // Result should be 1 as only one index has been used
    assert(table.num_elements == 1);
    assert(get(&table, 12) == "Test1");
    assert(get(&table, 2) == "Test2");

    remove_hash(&table, 12);
    remove_hash(&table, 2);

    assert(table.num_elements == 0);
    assert(get(&table, 12) == NULL);
    assert(get(&table, 2) == NULL);

    free_hash_table(&table);
}

/*!
 * @brief Tests the result of when two elements hash to the same location and only one is removed.
 * @return  None
 */
void hash_to_same_location_remove_one_test()
{
    hash_table table;

    initialize_hash_table(&table, NUM_ELEMS, 0);

    // Both elements hash to the same hash table index (2) with a table size of
    // 10 using the division method
    put(&table, 12, "Test1");
    put(&table, 2, "Test2");

    // Result should be 1 as only one index has been used
    assert(table.num_elements == 1);
    assert(get(&table, 12) == "Test1");
    assert(get(&table, 2) == "Test2");

    remove_hash(&table, 12);

    assert(table.num_elements == 1);
    assert(get(&table, 12) == NULL);
    assert(get(&table, 2) == "Test2");

    free_hash_table(&table);
}

/*!
 * @brief Tests the percent occupied function
 * @return  None
 */
void percent_occupied_test()
{
    hash_table table;

    initialize_hash_table(&table, NUM_ELEMS, 0);

    put(&table, "Test1", 1);
    put(&table, "Test2", 2);
    put(&table, "Test3", 3);

    float percent_occ = percent_occupied(&table);

    assert(percent_occ == 30.000000);

    free_hash_table(&table);
}

int main(void)
{
    init_test();
    free_empty_test();

    put_single_element_test();
    put_multiple_elements_test();

    remove_hash_test();
    remove_multiple_hashes_test();

    hash_to_same_location_test();
    hash_to_same_location_remove_test();
    hash_to_same_location_remove_one_test();

    percent_occupied_test();

    printf("\nAll tests passed.");

    return 0;
}
