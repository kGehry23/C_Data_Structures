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
#include "../hash_table/hash_table.h"
#include "undirected_graph_vertex.h"

/************************************
 * MACROS AND DEFINES
 ************************************/
#define TRUE 1
#define FALSE 0

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
    // Capacity of the adjacency matrix
    int adjacency_size;
    // Pointer to an array which will store pointers to the vertices
    undirected_graph_vertex **vertices;
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
void add_vertex(undirected_graph *ud_graph, int identifier, void *vertex_value)
{

    // Allocate memory for a new undirected graph vertex
    undirected_graph_vertex *new_vertex = (undirected_graph_vertex *)malloc(sizeof(undirected_graph_vertex));

    /*
      Assign the specified identifier, value stored by the new node, and an associated index into the adjacency
      matrix.
    */
    new_vertex->identifier = identifier;
    new_vertex->value = vertex_value;
    new_vertex->adj_index = identifier;

    // Add vertex to the graph
    ud_graph->vertices[identifier] = new_vertex;

    // Increment the number of vertices in the graph
    ud_graph->num_vertices = ud_graph->num_vertices + 1;
}

/*!
 * @brief Removes a vertex from the undirected graph
 * @param ud_graph Pointer to an undirected graph
 * @param identifier Value to identify the vertex by
 * @return None
 */
void *remove_vertex(undirected_graph *ud_graph, int identifier)
{
    // Pointer to the vertex to be removed
    void *removed_vertex_value = (ud_graph->vertices[identifier])->value;

    // Free memory held by removed vertex
    free(ud_graph->vertices[identifier]);
    // Set the pointer to the vertex to NULL to avoid dangling pointer
    ud_graph->vertices[identifier] = NULL;

    // Sets all the edges that may exist attached to the node to remove to FALSE in the adjacency matrix
    for (int i = 0; i < ud_graph->adjacency_size; i++)
    {
        if ((ud_graph->adjacency_matrix)[i][identifier] == TRUE)
        {
            (ud_graph->adjacency_matrix)[i][identifier] = FALSE;
            (ud_graph->adjacency_matrix)[identifier][i] = FALSE;
        }
    }

    // Decrement the counter for the number of vertices
    ud_graph->num_vertices = ud_graph->num_vertices - 1;

    return removed_vertex_value;
}

/*!
 * @brief Adds an edge between two vertices in the undirected graph
 * @param ud_graph Pointer to an undirected graph
 * @param vertex_id_1 Identifier of the first vertex
 * @param vertex_id_2 Identifier of the second vertex
 * @return None
 */
void add_edge(undirected_graph *ud_graph, int vertex_id_1, int vertex_id_2)
{
    // Updates the relevant indices in the adjacency matrix to TRUE (1)
    (ud_graph->adjacency_matrix)[vertex_id_1][vertex_id_2] = TRUE;
    (ud_graph->adjacency_matrix)[vertex_id_2][vertex_id_1] = TRUE;

    // Increment the counter for the number of edges
    ud_graph->num_edges = ud_graph->num_edges + 1;
}

/*!
 * @brief Removes an edge between two vertices in the undirected graph
 * @param ud_graph Pointer to an undirected graph
 * @param vertex_id_1 Identifier of the first vertex
 * @param vertex_id_2 Identifier of the second vertex
 * @return None
 */
void remove_edge(undirected_graph *ud_graph, int vertex_id_1, int vertex_id_2)
{
    // Updates the relevant indices in the adjacency matrix to FALSE (0)
    (ud_graph->adjacency_matrix)[vertex_id_1][vertex_id_2] = FALSE;
    (ud_graph->adjacency_matrix)[vertex_id_2][vertex_id_1] = FALSE;

    // Decrement the counter for the number of edges
    ud_graph->num_edges = ud_graph->num_edges - 1;
}

/*!
 * @brief Checks if there is an edge between two vertices
 * @param ud_graph Pointer to an undirected graph
 * @param vertex_id_1 Identifier of the first vertex
 * @param vertex_id_2 Identifier of the second vertex
 * @return A boolean value indicating if an edge exists between the specified vertices
 */
bool edge_exists(undirected_graph *ud_graph, int vertex_id_1, int vertex_id_2)
{
    // Checks if the specified vertices have an edge between them
    return ((ud_graph->adjacency_matrix)[vertex_id_1][vertex_id_2] == TRUE);
}

/*!
 * @brief Initializes an undirected graph
 * @param ud_graph Pointer to an undirected graph
 * @param size_upper_bound Row and column dimension of the adjacency matrix
 * @return None
 */
void initialize_undirected_graph(undirected_graph *ud_graph, int size_upper_bound)
{
    // Sets the number of vertices and the number of edges to 0
    ud_graph->num_vertices = 0;
    ud_graph->num_edges = 0;

    // Assign the number of rows and columns to the specified upper bound
    ud_graph->adjacency_size = size_upper_bound;

    ud_graph->vertices = (undirected_graph_vertex **)malloc(size_upper_bound * sizeof(undirected_graph_vertex *));

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