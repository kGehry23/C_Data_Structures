/**
 ********************************************************************************
 * @file    hash_table.c
 * @author  Kai Gehry
 * @date    2025-05-25
 *
 * @brief   Defines the structure of and functions on a hash table.
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/
#include "hash_table.h"

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

    printf("Hashed index: %d", index);
    // Boolean used to track if a collision has occurred.
    bool collision = false;

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
        hash_node *node = &((table->array)[index]);
        // Pointer to keep track of the previous node
        hash_node *previous_node;

        // Indicates a collision has occurred
        collision = true;

        // Traverse the hash table entry until the next reference is NULL.
        // Artifact of collisions
        while (node->next != NULL)
        {
            previous_node = node;
            node = node->next;
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
    if (collision == false)
    {
        table->num_elements++;
    }

    if (percent_occupied(table) >= (float)(table->load_factor * 100))
    {
        resize(table);
    }
}

/*!
 * @brief Returns the element associated with a key
 * @param table Pointer to a hash table
 * @param hash_key Key associated with the element
 * @return The value associated with the specified key
 */
void *get(hash_table *table, void *hash_key)
{
    printf("\nTable->array: %p", table->array);
    // Calculate index
    int index = (table->hash_function)(table, hash_key);

    // Entered if only one element is hashed to given index
    if (((table->array)[index]).next == NULL && ((table->array)[index]).key == hash_key)
    {
        return ((table->array)[index]).value;
    }
    // Entered if key is not found and only one element is hashed to a given position
    else if (((table->array)[index]).next == NULL && ((table->array)[index]).key != hash_key)
    {
        printf("\nEntered");
        return NULL;
    }
    // Entered if more than one node is assigned to a given position
    else
    {
        // Allocate memory for traversal node
        hash_node *node = &((table->array)[index]);

        // While the key does not match the one specified, continue traversing the nodes at a given index
        while (node->key != hash_key)
        {
            node = node->next;

            // If the key is not found in the table
            if (node->next == NULL && node->key != hash_key)
            {
                return NULL;
            }
        }

        return node->value;
    }
}

/*!
 * @brief Removes a key value pair from the hash table
 * @param table Pointer to a hash table
 * @param hash_key Key associated with the element
 * @return None
 */
void remove_hash(hash_table *table, void *hash_key)
{
    // Calculate index
    int index = (table->hash_function)(table, hash_key);

    // Allocate memory for traversal node
    hash_node *node = &((table->array)[index]);

    // Allocate memory for a previous node hash_node pointer
    hash_node *previous_node;

    // While the key does not match the one specified, continue traversing the nodes at a given index
    while (node != NULL && node->key != hash_key)
    {
        previous_node = node;
        node = node->next;
    }

    // If the previous node (first node at a given index) is not NULL, the previous node is reassigned
    if (node->next != NULL && node->previous != NULL)
    {
        // Correctly assigns the next node to the previous node
        previous_node->next = node->next;
        (node->next)->previous = previous_node;

        // Releases memory held by the removed node
        free(node);
        // Avoid dangling pointer
        node = NULL;
    }
    // Entered if the node to remove is the first at a table position, and there is at least one
    // other node in the chain
    else if (node->previous == NULL && node->next != NULL)
    {
        node->key = (node->next)->key;
        node->value = (node->next)->value;

        hash_node *next_node = (node->next)->next;

        // Release memory held by next node of node to remove.
        // Does not release memory allocated for hash table position.
        free(node->next);
        // Avoid dangling pointer
        node->next = NULL;

        node->next = next_node;
    }
    // If the element to remove is the only element at the table position
    else
    {
        node->key = NULL;
        node->value = NULL;
        table->num_elements--;
    }
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
 * @brief Resizes the hash table when the load factor is exceeded.
 * @param table Pointer to a hash table
 * @return None
 */
void resize(hash_table *table)
{

    // hash_node *old_array = (hash_node *)malloc(table->table_size * sizeof(hash_node));

    // for (int k = 0; k < table->table_size; k++)
    // {
    //     old_array[k] = table->array[k];
    // }

    hash_node *new_array = (hash_node *)malloc((table->table_size * 2) * sizeof(hash_node));

    for (int i = 0; i < (table->table_size * 2); i++)
    {
        // Sets the hash key to NULL
        (new_array[i]).key = NULL;
        // Sets the next pointer of the first node in the hash table position to NULL
        (new_array[i]).next = NULL;
        // Sets the previous pointer of the first node in the hash table position to NULL
        (new_array[i]).previous = NULL;
    }

    table->num_elements = 0;

    for (int i = 0; i < table->table_size; i++)
    {
        hash_node *node = &(table->array[i]);

        if (node->value == NULL)
        {
            continue;
        }

        else if (node->value != NULL)
        {
            do
            {
                if (node->key != NULL)
                {
                    put_rehash(table, new_array, node->key, node->value);
                }

                node = node->next;
            } while (node != NULL);
        }

        for (int j = 0; j < table->table_size; j++)
        {
            free(&(table->array[j]));
        }
    }

    table->array = new_array;
    table->table_size = table->table_size * 2;

    printf("\nResized. Hash table size is now %d", table->table_size);
}

void put_rehash(hash_table *table, hash_node *array, void *hash_key, void *hash_value)
{

    // Calculate the index to store the element at
    int index = (table->hash_function)(table, hash_key);
    printf("\nRehashed index: %d", index);
    // Boolean used to track if a collision has occurred.
    bool collision = false;

    // Entered if only one element is hashed to a given location
    if (array[index].key == NULL)
    {
        // Assign the value to be stored by the node in the table entry
        (array[index]).value = hash_value;
        // Assign the associated hash key to the node
        (array[index]).key = hash_key;
    }

    else
    {
        // Allocate memory for a hash_node pointer and assign to the first element in the hash table
        hash_node *node = &(array[index]);
        // Pointer to keep track of the previous node
        hash_node *previous_node;

        // Indicates a collision has occurred
        collision = true;

        // Traverse the hash table entry until the next reference is NULL.
        // Artifact of collisions
        while (node->next != NULL)
        {
            previous_node = node;
            node = node->next;
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
    if (collision == false)
    {
        table->num_elements++;
    }
}

/*!
 * @brief Allows for selecting the hash function to use
 * @param table Pointer to a hash table
 * @param function_select Integer specifying which hash function to use
 * @return None
 */
static void hash_function_select(hash_table *table, int function_select)
{
    switch (function_select)
    {
    // Selects the division method
    case 0:
        table->hash_function = &division;
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

    table->load_factor = load_factor;

    // Assigns the array pointer to an array of the desired size
    table->array = (hash_node *)malloc(size * sizeof(hash_node));

    for (int i = 0; i < size; i++)
    {
        // Sets the hash key to NULL
        ((table->array)[i]).key = NULL;
        // Sets the next pointer of the first node in the hash table position to NULL
        ((table->array)[i]).next = NULL;
        // Sets the previous pointer of the first node in the hash table position to NULL
        ((table->array)[i]).previous = NULL;
    }

    // Sets the initial counter for table elements to 0
    table->num_elements = 0;
    // Selects the desired hashing function
    hash_function_select(table, function_select);
}

/*!
 * @brief Frees the memory held by the hash table.
 * @param table Pointer to a hash table
 * @return None
 */
void free_hash_table(hash_table *table)
{
    // for (int i = 0; i < table->num_elements; i++)
    // {

    int i = 0;

    while (i < table->table_size)
    {

        if (((table->array)[i]).next != NULL)
        {
            // Frees the memory held by the next reference to the current node if one exists
            free(((table->array)[i]).next);
            // Avoid dangling pointer
            ((table->array)[i]).next = NULL;
        }

        if (((table->array)[i]).previous != NULL)
        {
            // Frees the memory held by the previous reference to the current node if one exists
            free(((table->array)[i]).previous);
            // Avoid dangling pointer
            ((table->array)[i]).previous = NULL;
        }

        // Frees the node itself
        free(&(table->array[i]));

        // Increment the index variable
        i++;
    }

    // Free the memory dynamically allocated for the hash table array
    free(table->array);
    // Avoid dangling pointer
    table->array = NULL;
}
