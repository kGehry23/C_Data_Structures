/**
 ********************************************************************************
 * @file    n_ary_tree.h
 * @author  Kai Gehry
 * @date    2025-06-24
 *
 * @brief   Defines the structure and operations defined on an n-ary tree
 ********************************************************************************
 */

#ifndef N_ARY_TREE_H
#define N_ARY_TREE_H

/************************************
 * INCLUDES
 ************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../linked_lists/singly_linked_list/singly_linked_list.h"

/************************************
 * TYPEDEFS
 ************************************/

/*!
 * @brief Struct which represents an n-ary tree node
 */
typedef struct n_ary_node
{
    // Maximum number of children per node (Tree order)
    int max_children;
    // Value held by the node
    void *node_value;
    // Node identifier
    void *node_identifier;
    // Array of pointers to child nodes
    singly_linked_list child_nodes;

} n_ary_node;

/*!
 * @brief Struct which represents an n-ary tree
 */
typedef struct
{
    // Tree order. Ex. 2 indicates binary
    int tree_order;
    // Number of elements in the tree
    int tree_size;
    // Pointer to the root node of the tree
    n_ary_node *root;

} n_ary_tree;

/************************************
 * FUNCTION PROTOTYPES
 ************************************/

/*!
 * @brief Initializes a tree
 * @param tree Pointer to a tree
 * @param order Tree order
 * @return None
 */
void initialize_n_ary_tree(n_ary_tree *tree, int order);

/*!
 * @brief Adds a node to the tree
 * @param tree Pointer to a tree
 * @param value Value held by the node
 * @return None
 */
void add_tree_node(n_ary_tree *tree, void *value);

/*!
 * @brief Adds a node to the tree
 * @param tree Pointer to a tree
 * @param identifier Node identifier
 * @return Returns the value held by the node
 */
void *remove_tree_node(n_ary_tree *tree, void *identifier);

/*!
 * @brief Returns a pointer to a n-ary node
 * @param tree Pointer to a tree
 * @param identifier Node identifier
 * @return A pointer to an n-ary node
 */
n_ary_node *find_n_ary_node(n_ary_tree *tree, void *identifier);

/*!
 * @brief Returns the value held by the specified node
 * @param tree Pointer to a tree
 * @param identifier Node identifier
 * @return The value held by the specified node
 */
void *get_node_value(n_ary_tree *tree, void *identifier);

/*!
 * @brief Returns the number of nodes in the tree
 * @param tree Pointer to a tree
 * @return An integer representing the number of nodes in the tree
 */
int num_nodes(n_ary_tree *tree);

/*!
 * @brief Returns the height of the tree
 * @param tree Pointer to a tree
 * @return An integer representing the height of the tree
 */
int tree_height(n_ary_tree *tree);

/*!
 * @brief Returns if the tree is empty
 * @param tree Pointer to a tree
 * @return A boolean representing if the tree is empty
 */
bool n_ary_is_empty(n_ary_tree *tree);

/*!
 * @brief Returns if the tree is balanced
 * @param tree Pointer to a tree
 * @return A boolean representing if the tree is balanced
 */
bool n_ary_is_balanced(n_ary_tree *tree);

/*!
 * @brief Returns if the tree is complete
 * @param tree Pointer to a tree
 * @return A boolean representing if the tree is complete
 */
bool n_ary_is_complete(n_ary_tree *tree);

/*!
 * @brief Returns if the tree is full
 * @param tree Pointer to a tree
 * @return A boolean representing if the tree is full
 */
bool n_ary_is_full(n_ary_tree *tree);

#endif // N_ARY_TREE_H
