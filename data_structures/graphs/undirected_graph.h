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
#include <stdbool.h>
#include "../hash_table/hash_table.h"
#include "undirected_graph_vertex.h"

/************************************
 * COMPILER DIRECTIVES
 ************************************/
// Added for void* to required type conversions
#pragma GCC diagnostic ignored "-Wint-conversion"

/*!
 * @brief Struct which represents an undirected graph
 */
typedef struct
{
    // Stores the number of vertices
    int num_vertices;
    // Stores the number of edges
    int num_edges;
    // Pointer to an array which will store pointers to the vertices
    hash_table *vertices;
    // Pointer to 2D array to indicate if two vertices are connected
    int **adjacency_matrix;

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
    // Integer which keeps track of the current index to associate with the new node in the adjacency matrix
    static int matrix_index = 0;

    // Allocate memory for a new undirected graph vertex
    undirected_graph_vertex *new_vertex = (undirected_graph_vertex *)malloc(sizeof(undirected_graph_vertex));

    /*
      Assign the specified identifier, value stored by the new node, and an associated index into the adjacency
      matrix.
    */
    new_vertex->identifier = identifier;
    new_vertex->value = vertex_value;
    new_vertex->adj_index = matrix_index;

    // Add the node to the hash table associating vertex identifiers with a pointer to the vertex
    put((ud_graph->vertices), identifier, new_vertex);

    matrix_index++;

    // Increment the number of vertices in the graph
    ud_graph->num_vertices = ud_graph->num_vertices + 1;
}

/*!
 * @brief Adds an edge between two vertices to the undirected graph
 * @param ud_graph Pointer to an undirected graph
 * @param vertex_id_1 Identifier of the first vertex
 * @param vertex_id_2 Identifier of the second vertex
 * @return None
 */
void add_edge(undirected_graph *ud_graph, void *vertex_id_1, void *vertex_id_2)
{
}

/*!
 * @brief Initializes an undirected graph
 * @param ud_graph Pointer to an undirected graph
 * @param initial_capacity Row and column dimension of the adjacency matrix
 * @return None
 */
void initialize_undirected_graph(undirected_graph *ud_graph, int size_upper_bound)
{
    // Sets the number of vertices and the number of edges to 0
    ud_graph->num_vertices = 0;
    ud_graph->num_edges = 0;

    // A good hash function should be defined for this. Best way to maintain efficient addition, retrieval and removal
    hash_table *vertex_data = (hash_table *)malloc(sizeof(hash_table));
    initialize_hash_table(vertex_data, 20, 0);

    ud_graph->vertices = vertex_data;

    // Resize the main array to the required size
    ud_graph->adjacency_matrix = (int *)malloc(size_upper_bound * sizeof(int));

    // Populate the main array with internal arrays
    for (int i = 0; i < size_upper_bound; i++)
    {
        (ud_graph->adjacency_matrix)[i] = (int *)malloc(size_upper_bound * sizeof(int));
    }

    // Initialize all elements in the adjacency matrix to 0
    for (int j = 0; j < size_upper_bound; j++)
    {
        for (int k = 0; k < size_upper_bound; k++)
        {
            (ud_graph->adjacency_matrix)[j][k] = 0;
        }
    }
}