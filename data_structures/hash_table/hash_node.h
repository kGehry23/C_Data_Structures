/**
 ********************************************************************************
 * @file    hash_node.h
 * @author  Kai Gehry
 * @date    2025-05-25
 *
 * @brief   Defines node for the chaining method for resolving collisions.
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/
#include <stdio.h>

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
} hash_node;
