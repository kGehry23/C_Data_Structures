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
    // // Allocate memory for a new undirected graph node
    // undirected_graph_vertex *new_vertex = (undirected_graph_vertex *)malloc(sizeof(undirected_graph_vertex));

    // // Assign the specified identifier and value to the new node
    // new_vertex->identifier = identifier;
    // new_vertex->value = vertex_value;

    (ud_graph->adjacency_matrix)[0][0] = 1;

    printf("Value at 0,0: %d", (ud_graph->adjacency_matrix)[0][0]);

    // Increment the number of vertices in the graph
    ud_graph->num_vertices = ud_graph->num_vertices + 1;
}

/*!
 * @brief Initializes an undirected graph
 * @param ud_graph Pointer to an undirected graph
 * @param initial_capacity Row and column dimension of the adjacency matrix
 * @return None
 */
void initialize_undirected_graph(undirected_graph *ud_graph, int initial_capacity)
{
    // Sets the number of vertices and the number of edges to 0
    ud_graph->num_vertices = 0;
    ud_graph->num_edges = 0;

    // Resize the main array to the required size
    ud_graph->adjacency_matrix = (int *)malloc(initial_capacity * sizeof(int));

    // Populate the main array with internal arrays
    for (int i = 0; i < initial_capacity; i++)
    {
        (ud_graph->adjacency_matrix)[i] = (int *)malloc(initial_capacity * sizeof(int));
    }

    // Initialize all elements in the adjacency matrix to 0
    for (int j = 0; j < initial_capacity; j++)
    {
        for (int k = 0; k < initial_capacity; k++)
        {
            (ud_graph->adjacency_matrix)[j][k] = 0;
        }
    }
}