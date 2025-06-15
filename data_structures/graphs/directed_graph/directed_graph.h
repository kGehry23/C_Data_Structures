/**
 ********************************************************************************
 * @file    directed_graph.h
 * @author  Kai Gehry
 * @date    2025-06-15
 *
 * @brief   Defines the structure of an directed graph and the functions
 *          defined on it
 ********************************************************************************
 */

#ifndef DIRECTED_GRAPH_H
#define DIRECTED_GRAPH_H

/************************************
 * INCLUDES
 ************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <strings.h>

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

/************************************
 * TYPEDEFS
 ************************************/

/*!
 * @brief Struct which represents an directed graph vertex
 */
typedef struct
{
    // Value held by the node
    void *value;
    // Vertex identifier
    void *identifier;
    // Stores the index of the vertex in the adjacency matrix
    int adj_index;
    // Indicates if the vertex position in the vertex list has been allocated
    bool allocated;

} directed_graph_vertex;

/*!
 * @brief Struct which represents a directed graph
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
    directed_graph_vertex **vertices;
    // Pointer to 2D array to indicate if two vertices are connected
    int **adjacency_matrix;

} directed_graph;

/************************************
 * FUNCTION PROTOTYPES
 ************************************/

/*!
 * @brief Adds a vertex to the directed graph
 * @param ud_graph Pointer to an directed graph
 * @param identifier Value to identify the vertex by
 * @param vertex_value Value stored by the vertex
 * @return None
 */
void add_vertex(directed_graph *ud_graph, int identifier, void *vertex_value);

/*!
 * @brief Removes and returns the value associated with the specified vertex
 *        in the directed graph
 * @param ud_graph Pointer to an directed graph
 * @param identifier Value to identify the vertex by
 * @return None
 */
void *remove_vertex(directed_graph *ud_graph, int identifier);

/*!
 * @brief Returns the value stored by the specified vertex.
 * @param ud_graph Pointer to an directed graph
 * @param identifier Value to identify the vertex by
 * @return The value stored by the specified vertex
 */
void *return_vertex_value(directed_graph *ud_graph, int identifier);

/*!
 * @brief Adds an edge between two vertices in the directed graph
 * @param ud_graph Pointer to an directed graph
 * @param vertex_id_1 Identifier of the first vertex
 * @param vertex_id_2 Identifier of the second vertex
 * @return None
 */
void add_edge(directed_graph *ud_graph, int vertex_id_1, int vertex_id_2);

/*!
 * @brief Removes an edge between two vertices in the directed graph
 * @param ud_graph Pointer to an directed graph
 * @param vertex_id_1 Identifier of the first vertex
 * @param vertex_id_2 Identifier of the second vertex
 * @return None
 */
void remove_edge(directed_graph *ud_graph, int vertex_id_1, int vertex_id_2);

/*!
 * @brief Checks if there is an edge between two vertices
 * @param ud_graph Pointer to an directed graph
 * @param vertex_id_1 Identifier of the first vertex
 * @param vertex_id_2 Identifier of the second vertex
 * @return A boolean value indicating if an edge exists between the specified vertices
 */
bool edge_exists(directed_graph *ud_graph, int vertex_id_1, int vertex_id_2);

/*!
 * @brief Returns the number of vertices in the graph
 * @return An integer representing the number of vertices in the graph
 */
int graph_size(directed_graph *ud_graph);

/*!
 * @brief Initializes an directed graph
 * @param ud_graph Pointer to an directed graph
 * @param size_upper_bound Row and column dimension of the adjacency matrix
 * @return None
 */
void initialize_directed_graph(directed_graph *ud_graph, int size_upper_bound);

#endif // DIRECTED_GRAPH_H