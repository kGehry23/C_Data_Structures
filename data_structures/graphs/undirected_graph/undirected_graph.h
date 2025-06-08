/**
 ********************************************************************************
 * @file    undirected_graph.h
 * @author  Kai Gehry
 * @date    2025-06-07
 *
 * @brief   Defines the functions to create and manipulate an undirected graph.
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/
#include <stdio.h>
#include "undirected_graph_vertex.h"
#include "../linked_lists/singly_linked_list/singly_linked_list.h"
#include "../hash_table/hash_table.h"

/*!
 * @brief Struct which represents an undirected graph
 */
typedef struct
{
    // Stores the number of vertices
    int num_vertices;
    // Stores the number of edges
    int num_edges;
    // Hash table used to store vertex ids and associated pointers
    hash_table *vertex_data;
    // Linked list to store vertices present in the undirected graph
    singly_linked_list *vertices;

} undirected_graph;

/*!
 * @brief Initializes an undirected graph
 * @param undirected_graph Pointer to an undirected graph
 * @return None
 */
void initialize_undirected_graph(undirected_graph *ud_graph)
{
    // Sets the number of vertices and the number of edges to 0
    ud_graph->num_vertices = 0;
    ud_graph->num_edges = 0;

    // Assign a hash table to the vertices hash table
    hash_table vertex_table;

    // 20 was chosen randomly as a size here. Make a rehash function associated with the load factor.
    // Selects division for hashing function
    initialize_hash_table(&vertex_table, 20, 0);

    ud_graph->vertex_data = &vertex_table;

    // Assign a singly linked list to the vertices list
    singly_linked_list list;
    initialize_sl_list(&list);

    ud_graph->vertices = &list;
}