/**
 ********************************************************************************
 * @file    n_ary_tree.c
 * @author  Kai Gehry
 * @date    2025-06-24
 *
 * @brief   Defines the operations on an n-ary tree
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/
#include "n_ary_tree.h"

/************************************
 * FUNCTION DEFINITIONS
 ************************************/

/*!
 * @brief Initializes a tree
 * @param tree Pointer to a tree
 * @param order Tree order
 * @return None
 */
void initialize_n_ary_tree(n_ary_tree *tree, int order)
{
    tree->tree_size = 0;
    tree->tree_order = order;
    tree->root = NULL;
}

/*!
 * @brief Adds a node to the tree
 * @param tree Pointer to a tree
 * @param parent_identifier Identifier of the parent node
 * @param node_id Identifier for a node
 * @param value Value held by the node
 * @return None
 */
void add_tree_node(n_ary_tree *tree, char *parent_identifier, char *node_id, void *value)
{

    // Create a new node pointer
    n_ary_node *node = (n_ary_node *)malloc(sizeof(n_ary_node));

    // Set the node id of the new node
    node->node_identifier = node_id;
    // Set the value held by the new node
    node->node_value = value;
    // Set the maximum number of children for the node
    node->max_children = tree->tree_order;
    // Initialize the singly linked list of child nodes
    initialize_sl_list(&(node->child_nodes));

    // Set the root node if there are no other nodes in the tree
    if (parent_identifier == NULL && tree->root == NULL)
    {
        tree->root = node;
    }
    else
    {
        n_ary_node *parent = find_n_ary_node(tree, parent_identifier);

        add_sl_node_to_tail(&(parent->child_nodes), node);
    }
}

/*!
 * @brief Adds a node to the tree
 * @param tree Pointer to a tree
 * @param identifier Node identifier
 * @return Returns the value held by the node
 */
void *remove_tree_node(n_ary_tree *tree, char *identifier)
{
    return NULL;
}

/*!
 * @brief Returns a pointer to an n-ary node
 * @param tree Pointer to a tree
 * @param identifier Node identifier
 * @return A pointer to an n-ary node
 */
n_ary_node *find_n_ary_node(n_ary_tree *tree, char *identifier)
{

    n_ary_node *current = tree->root;

    /*
        In the worst case, this search should have O(n) complexity and in
        the best case O(1).
     */

    // Begin search from root node n_ary_node *current = tree->root;
    if (current->node_identifier)
    {
        return current;
    }
    else
    {
        return NULL;
    }
}

/*!
 * @brief Returns the value held by the specified node
 * @param tree Pointer to a tree
 * @param identifier Node identifier
 * @return The value held by the specified node
 */
void *get_node_value(n_ary_tree *tree, char *identifier)
{
    return NULL;
}

/*!
 * @brief Returns the value held by the root node
 * @param tree Pointer to a tree
 * @return The value held by the root node
 */
void *get_root_node(n_ary_tree *tree)
{
    return (tree->root)->node_value;
}

/*!
 * @brief Returns the number of nodes in the tree
 * @param tree Pointer to a tree
 * @return An integer representing the number of nodes in the tree
 */
int num_nodes(n_ary_tree *tree)
{
    return 0;
}

/*!
 * @brief Returns the height of the tree
 * @param tree Pointer to a tree
 * @return An integer representing the height of the tree
 */
int tree_height(n_ary_tree *tree)
{
    return 0;
}

/*!
 * @brief Returns if the tree is empty
 * @param tree Pointer to a tree
 * @return A boolean representing if the tree is empty
 */
bool n_ary_is_empty(n_ary_tree *tree)
{
    return 0;
}

/*!
 * @brief Returns if the tree is balanced
 * @param tree Pointer to a tree
 * @return A boolean representing if the tree is balanced
 */
bool n_ary_is_balanced(n_ary_tree *tree)
{
    return 0;
}

/*!
 * @brief Returns if the tree is complete
 * @param tree Pointer to a tree
 * @return A boolean representing if the tree is complete
 */
bool n_ary_is_complete(n_ary_tree *tree)
{
    return 0;
}

/*!
 * @brief Returns if the tree is full
 * @param tree Pointer to a tree
 * @return A boolean representing if the tree is full
 */
bool n_ary_is_full(n_ary_tree *tree)
{
    return 0;
}
