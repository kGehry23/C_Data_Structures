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
#include <stdlib.h>
#include <strings.h>
#include "undirected_graph_vertex.h"
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
 * @brief Adds a vertex to the undirected graph
 * @param ud_graph Pointer to an undirected graph
 * @param identifier Value to identify the vertex by
 * @param vertex_value Value stored by the vertex
 * @return None
 */
void add_vertex(undirected_graph *ud_graph, void *identifier, void *vertex_value)
{
    // Allocate memory for a new undirected graph node
    undirected_graph_vertex *new_vertex = (undirected_graph_vertex *)malloc(sizeof(undirected_graph_vertex));

    // Assign the specified identifier and value to the new node
    new_vertex->identifier = identifier;
    new_vertex->value = vertex_value;

    // Put the identifier and a pointer to the new node in the graph's hash table
    put((ud_graph->vertex_data), identifier, new_vertex);

    // Increment the number of vertices in the graph
    ud_graph->num_vertices = ud_graph->num_vertices + 1;
}

/*!
 * @brief Initializes an undirected graph
 * @param ud_graph Pointer to an undirected graph
 * @return None
 */
void initialize_undirected_graph(undirected_graph *ud_graph)
{
    // Sets the number of vertices and the number of edges to 0
    ud_graph->num_vertices = 0;
    ud_graph->num_edges = 0;

    // Assign a hash table to the vertices hash table
    hash_table *vertex_table = (hash_table *)malloc(sizeof(hash_table));

    // 20 was chosen randomly as a size here. Make a rehash function associated with the load factor.
    // Selects division for hashing function
    initialize_hash_table(vertex_table, 5, 0);

    ud_graph->vertex_data = vertex_table;

    // // Assign a singly linked list to the vertices list
    // singly_linked_list list;
    // initialize_sl_list(&list);

    // ud_graph->vertices = &list;
}