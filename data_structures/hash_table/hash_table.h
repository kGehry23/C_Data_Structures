/**
 ********************************************************************************
 * @file    hash_table.h
 * @author  Kai Gehry
 * @date    2025-05-25
 *
 * @brief   Defines the structure and functions defined on a hash table with
 *          chaining used to resolve collisions.
 ********************************************************************************
 */

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

/************************************
 * INCLUDES
 ************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/************************************
 * TYPEDEFS
 ************************************/

/*!
 * @brief Struct representing a hash table element.
 */
typedef struct hash_node
{
    // Key associated with the hash node
    void *key;
    // Value held by the node
    void *value;
    // Pointer to the next node
    struct hash_node *next;
    // Pointer to the previous node
    struct hash_node *previous;
} hash_node;

/*!
 * @brief Struct which represents a hash table.
 */
typedef struct hash_table
{
    // Size of the hash table
    int table_size;
    // Number of elements stored in the hash table
    int num_elements;
    // Load factor to specify when to resize the hash table
    float load_factor;
    // Pointer to a hash function
    int (*hash_function)(struct hash_table *, void *);
    // Pointer to an array of hash nodes (hash table elements)
    hash_node *array;

} hash_table;

/************************************
 * FUNCTION PROTOTYPES
 ************************************/

/*!
 * @brief Defines the division method for creating an index from a key. Uses
 *        the remainder of the hash key divided by the table size to determine the index.
 * @param hash_key Key to create an index from
 * @return An integer specifying the index into the hash table
 */
int division(hash_table *table, void *hash_key);

/*!
 * @brief Adds an element to the hash table
 * @param table Pointer to a hash table
 * @param hash_key Key to create an index from
 * @param hash_value Value to place into the hash table
 * @return None
 */
void put(hash_table *table, void *hash_key, void *hash_value);

/*!
 * @brief Returns the element associated with a key
 * @param table Pointer to a hash table
 * @param hash_key Key associated with the element
 * @return The value associated with the specified key
 */
void *get(hash_table *table, void *hash_key);

/*!
 * @brief Removes a key value pair from the hash table
 * @param table Pointer to a hash table
 * @param hash_key Key to create an index from
 * @return None
 */
void remove_hash(hash_table *table, void *hash_key);

/*!
 * @brief Returns the percent of the hash table occupied
 * @param table Pointer to a hash table
 * @return A float representing the percentage of the hash table that is occupied
 */
float percent_occupied(hash_table *table);

/*!
 * @brief Allows for selecting the hash function to use
 * @param table Pointer to a hash table
 * @param function_select Integer specifying which hash function to use
 * @return None
 */
static void hash_function_select(hash_table *table, int function_select);

/*!
 * @brief Initializes the hash table
 * @param table Pointer to a hash table
 * @param size Number of elements in the hash table
 * @param load_factor Percentage of table full at which to dynamically resize
 * @param function_select Integer specifying which hash function to use
 * @return None
 */
void initialize_hash_table(hash_table *table, int size, float load_factor, int function_select);

/*!
 * @brief Resizes the hash table when the load factor is exceeded
 * @param table Pointer to a hash table
 * @return None
 */
void resize(hash_table *table);

/*!
 * @brief Frees the memory held by the hash table.
 * @param table Pointer to a hash table
 * @return None
 */
void free_hash_table(hash_table *table);

#endif // HASH_TABLE_H