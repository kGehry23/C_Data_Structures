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
#include <stdlib.h>
#include <strings.h>
#include "hash_node.h"

/************************************
 * PRIVATE MACROS AND DEFINES
 ************************************/
#define KEY_TYPE long

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
    // Calculate the index to store the element at
    int index = (table->hash_function)(table, hash_key);

    if (((*(table->table_ptr))[index]).value == NULL)
    {
        ((*(table->table_ptr))[index]).value = hash_value;
        hash_node *next_node = (hash_node *)malloc(sizeof(hash_node));
        ((*(table->table_ptr))[index]).next = next_node;

        char test_str1[9] = "Entered1";

        printf("\n%s", test_str1);
    }

    else if (((*(table->table_ptr))[index]).value != NULL)
    {
        hash_node *node_ptr = &((*(table->table_ptr))[index]);

        char test_str2[9] = "Entered2";

        printf("\n%s", test_str2);

        while (node_ptr->value != hash_key)
        {
            node_ptr = node_ptr->next;
        }

        node_ptr->value = hash_value;
    }

    table->num_elements++;
}

void *get(hash_table *table, void *hash_key)
{
    // Calculate index
    int index = (table->hash_function)(table, hash_key);

    // return ((*(table->table_ptr))[index]).value;

    if (((*(table->table_ptr))[index]).next != NULL)
    {
        // Return associated value in hash table
        return ((*(table->table_ptr))[index]).value;
    }

    // else
    // {
    //     if (((*(table->table_ptr))[index]).key == hash_key)
    //     {
    //         // Return associated value in hash table
    //         return ((*(table->table_ptr))[index]).value;
    //     }
    // }
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

    for (int i = 0; i < size; i++)
    {
        table_contents[i].next = NULL;
        table_contents[i].value = NULL;
    }

    table->table_ptr = &table_contents;
    table->load_factor = load_factor;

    table->num_elements = 0;
    hash_function_select(table, function_select);
}
