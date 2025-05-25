/**
 ********************************************************************************
 * @file    hash_table.h
 * @author  Kai Gehry
 * @date    2025-05-25
 *
 * @brief   Defines a structure  and functions defined on a hash table.
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/
#include <stdio.h>
#include <strings.h>
#include "hash_node.h"

/************************************
 * PRIVATE MACROS AND DEFINES
 ************************************/
#define KEY_TYPE long
#define VALUE_TYPE (*char)[]

/*!
 * @brief Struct which represents a hash table.
 */
typedef struct hash_table
{
    int table_size;
    // Need to decide what the table should contain
    hash_node (*table_ptr)[];
    int num_elements;
    float load_factor;
    int (*hash_function)(struct hash_table *, KEY_TYPE);

} hash_table;

/*!
 * @brief Defines the division method for creating an index from a key. Uses
 *        the remainder of the hash key divided by the table size to determine the index.
 * @param hash_key Key to create an index from
 * @return An integer specifying the index into the hash table
 */
int division(hash_table *table, KEY_TYPE hash_key)
{
    int index;
    index = hash_key % (table->table_size);
    return index;
}

/*!
 * @brief Defines the folding method for creating an index from a key
 * @param hash_key Key to create an index from
 * @return An integer specifying the index into the hash table
 */
int folding(hash_table *table, KEY_TYPE hash_key)
{
    int index;
    return index;
}

/*!
 * @brief Defines the shift folding method for creating an index from a key
 * @param hash_key Key to create an index from
 * @return An integer specifying the index into the hash table
 */
int shift_folding(hash_table *table, KEY_TYPE hash_key)
{
    int index;
    return index;
}

/*!
 * @brief Produces an index into the hash table given a key
 * @param hash_key Key to create an index from
 * @return An integer specifying the index into the hash table
 */
void put(hash_table *table, long hash_key, void *hash_value)
{
    int index;
    index = (table->hash_function)(table, hash_key);
    printf("%d", index);
    ((*(table->table_ptr))[index]).value = hash_value;
    table->num_elements++;
}

/*!
 * @brief Allows for selecting the hash function to use
 * @param table Pointer to a hash table
 * @param function_select Integer specifying which hash function to use
 * @return None
 */
void hash_function_select(hash_table *table, int function_select)
{

    switch (function_select)
    {
    case 0:
        table->hash_function = &division;
        break;
    case 1:
        table->hash_function = &folding;
        break;
    case 2:
        table->hash_function = &shift_folding;
        break;
    }
}

/*!
 * @brief Initializes the hash table
 * @param table Pointer to a hash table
 * @param size Number of elements in the hash table
 * @param load_factor Percentage of table full at which to dynamically resize
 * @param function_select Integer specifying which hash function to use
 * @return None
 */
void initialize_hash_table(hash_table *table, int size, float load_factor, int function_select)
{
    table->table_size = size;
    hash_node table_contents[size];

    table->table_ptr = &table_contents;
    table->load_factor = load_factor;

    table->num_elements = 0;
    hash_function_select(table, function_select);
}
