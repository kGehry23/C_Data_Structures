/**
 ********************************************************************************
 * @file    hash_table.h
 * @author  Kai Gehry
 * @date    2025-05-25
 *
 * @brief   Defines the structure of and functions on a hash table.
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <stdbool.h>
#include "hash_node.h"

/*!
 * @brief Struct which represents a hash table.
 */
typedef struct hash_table
{
    // Size of the hash table
    int table_size;
    // Number of elements stored in the hash table
    int num_elements;
    // Percentage of hash table populated at which to resize
    float load_factor;
    // Pointer to a hash function
    int (*hash_function)(struct hash_table *, void *);
    // Pointer to the array holding the table elements
    hash_node *array;

} hash_table;

/*!
 * @brief Defines the division method for creating an index from a key. Uses
 *        the remainder of the hash key divided by the table size to determine the index.
 * @param hash_key Key to create an index from
 * @return An integer specifying the index into the hash table
 */
int division(hash_table *table, void *hash_key)
{
    int index;
    // Casts the hash key to a long type
    long cast_hash_key = (long *)hash_key;
    // Calculates the index
    index = cast_hash_key % (table->table_size);

    return index;
}

/*!
 * @brief Defines the shift folding method for creating an index from a key
 * @param hash_key Key to create an index from
 * @return An integer specifying the index into the hash table
 */
int shift_folding(hash_table *table, long hash_key)
{
    int index;
    return index;
}

/*!
 * @brief Adds an element to the hash table
 * @param table Pointer to a hash table
 * @param hash_key Key to create an index from
 * @param hash_value Value to place into the hash table
 * @return None
 */
void put(hash_table *table, void *hash_key, void *hash_value)
{
    // Calculate the index to store the element at
    int index = (table->hash_function)(table, hash_key);
    // Boolean used to track if a collision has occurred.
    bool collision = 0;

    // Entered if only one element is hashed to a given location
    if (((table->array)[index]).key == NULL)
    {
        // Assign the value to be stored by the node in the table entry
        ((table->array)[index]).value = hash_value;
        // Assign the associated hash key to the node
        ((table->array)[index]).key = hash_key;
    }

    else
    {
        // Allocate memory for a hash_node pointer and assign to the first element in the hash table
        hash_node *node = (hash_node *)malloc(sizeof(hash_node));
        node = &((table->array)[index]);

        // Allocate memory for a previous node hash_node pointer
        hash_node *previous_node = (hash_node *)malloc(sizeof(hash_node));

        // Indicates a collision has occurred
        collision = 1;

        if (node->next != NULL)
        {
            // Traverse the hash table entry until the next reference is NULL.
            // Artifact of collisions
            while (node->next != NULL)
            {
                previous_node = node;
                node = node->next;
            }
        }

        // Allocate memory for the next node at a given table location
        hash_node *next_node = (hash_node *)malloc(sizeof(hash_node));

        // Assign this node's next node to NULL
        next_node->next = NULL;
        // Assign the previous node pointer to the predecessor of the current node
        next_node->previous = previous_node;
        // Assign the value to be stored by the node in the table entry
        next_node->value = hash_value;
        // Assign the associated hash key to the node
        next_node->key = hash_key;

        // Assigns the next node
        node->next = next_node;
    }

    // If a collision did not occur, the counter for the number of elements is incremented
    if (collision == 0)
    {
        table->num_elements++;
    }
}

/*!
 * @brief Returns the element associated with a key
 * @param table Pointer to a hash table
 * @param hash_key Key to create an index from
 * @return The value associated with the specified key
 */
void *get(hash_table *table, void *hash_key)
{
    // Calculate index
    int index = (table->hash_function)(table, hash_key);

    // Entered if only one element is hashed to given index
    if (((table->array)[index]).next == NULL)
    {
        return ((table->array)[index]).value;
    }

    else
    {
        // Allocate memory for traversal node
        hash_node *node = (hash_node *)malloc(sizeof(hash_node));
        node = &((table->array)[index]);

        // While the key does not match the one specified, continue traversing the nodes at a given index
        while (node->key != hash_key)
        {
            node = node->next;
        }

        return node->value;
    }
}

void remove_hash(hash_table *table, void *hash_key)
{
    // Calculate index
    int index = (table->hash_function)(table, hash_key);

    // Allocate memory for traversal node
    hash_node *node = (hash_node *)malloc(sizeof(hash_node));
    node = &((table->array)[index]);

    // While the key does not match the one specified, continue traversing the nodes at a given index
    while (node->key != hash_key)
    {
        node = node->next;
    }

    node->key = NULL;

    // will get rid of all following nodes immediately. Cannot have this
    // Consider adding a previous pointer to each hash node to deal with this
    node->next = NULL;
}

/*!
 * @brief Returns the percent of the hash table occupied
 * @param table Pointer to a hash table
 * @return A float representing the percentage of the hash table that is occupied
 */
float percent_occupied(hash_table *table)
{
    return ((float)table->num_elements / table->table_size) * 100;
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
    // Selects the division method
    case 0:
        table->hash_function = &division;
        break;
    // Selects the shift folding method
    case 1:
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
    // Defines the size of the hash table
    table->table_size = size;
    // Defines the load factor
    table->load_factor = load_factor;

    // Assigns the array pointer to an array of the desired size
    table->array = (hash_node *)malloc(size * sizeof(hash_node));

    // Assigns the next pointer of all hash nodes to null
    for (int i = 0; i < size; i++)
    {
        ((table->array)[i]).key = NULL;
        ((table->array)[i]).next = NULL;
        ((table->array)[i]).previous = NULL;
    }

    // Sets the initial counter for table elements to 0
    table->num_elements = 0;
    // Selects the desired hashing function
    hash_function_select(table, function_select);
}