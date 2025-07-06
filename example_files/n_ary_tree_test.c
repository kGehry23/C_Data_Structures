/**
 ********************************************************************************
 * @file    n_ary_tree_test.c
 * @author  Kai Gehry
 * @date    2025-06-24
 *
 * @brief   Tests the functionality of the operations defined in
 *          the n_ary_tree header file.
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/
#include <stdio.h>
#include "../data_structures/trees/n_ary_tree.h"

int main(void)
{
    n_ary_tree tree;

    initialize_n_ary_tree(&tree, 2);

    add_tree_node(&tree, NULL, "Root", 5);
    add_tree_node(&tree, "Root", "Child", 10);

    printf("\n\nRoot Value: %d", get_root_node(&tree));
    printf("\n\nRoot id: %s", (tree.root)->node_identifier);

        return 0;
}