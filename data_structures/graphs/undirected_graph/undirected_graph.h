/**
 ********************************************************************************
 * @file    undirected_graph.h
 * @author  Kai Gehry
 * @date    2025-06-07
 *
 * @brief   Defines the structure of an undirected graph and the functions
 *          defined on it
 ********************************************************************************
 */

#ifndef UNDIRECTED_GRAPH_H
#define UNDIRECTED_GRAPH_H

/************************************
 * INCLUDES
 ************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../../queues/array_queue/array_queue.h"
#include "../../stacks/array_stack/array_stack.h"

/************************************
 * COMPILER DIRECTIVES
 ************************************/
// Added for void* to required type conversions
#pragma GCC diagnostic ignored "-Wint-conversion"

/************************************
 * TYPEDEFS
 ************************************/

/*!
 * @brief Struct which represents an undirected graph vertex
 */
typedef struct
{
    // Value held by the node
    void *value;
    // Vertex identifier
    int identifier;
    // String identifier
    char *vertex_name;
    // Stores the index of the vertex in the adjacency matrix
    int adj_index;
    // Boolean indicating if the vertex has been visited during a traversal
    bool visited;

} undirected_graph_vertex;

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
    bool **adjacency_matrix;

} undirected_graph;

/************************************
 * FUNCTION PROTOTYPES
 ************************************/

/*!
 * @brief Adds a vertex to the undirected graph
 * @param ud_graph Pointer to an undirected graph
 * @param identifier Value to identify the vertex by
 * @param vertex_value Value stored by the vertex
 * @return None
 */
void add_vertex(undirected_graph *ud_graph, char *name, int identifier, void *vertex_value);

/*!
 * @brief Removes and returns the value associated with the specified vertex
 *        in the undirected graph
 * @param ud_graph Pointer to an undirected graph
 * @param identifier Value to identify the vertex by
 * @return None
 */
void *remove_vertex(undirected_graph *ud_graph, int identifier);

/*!
 * @brief Returns the value stored by the specified vertex.
 * @param ud_graph Pointer to an undirected graph
 * @param identifier Value to identify the vertex by
 * @return The value stored by the specified vertex
 */
void *return_vertex_value(undirected_graph *ud_graph, int identifier);

/*!
 * @brief Adds an edge between two vertices in the undirected graph
 * @param ud_graph Pointer to an undirected graph
 * @param vertex_id_1 Identifier of the first vertex
 * @param vertex_id_2 Identifier of the second vertex
 * @return None
 */
void add_edge(undirected_graph *ud_graph, int vertex_id_1, int vertex_id_2);

/*!
 * @brief Removes an edge between two vertices in the undirected graph
 * @param ud_graph Pointer to an undirected graph
 * @param vertex_id_1 Identifier of the first vertex
 * @param vertex_id_2 Identifier of the second vertex
 * @return None
 */
void remove_edge(undirected_graph *ud_graph, int vertex_id_1, int vertex_id_2);

/*!
 * @brief Checks if there is an edge between two vertices
 * @param ud_graph Pointer to an undirected graph
 * @param vertex_id_1 Identifier of the first vertex
 * @param vertex_id_2 Identifier of the second vertex
 * @return A boolean value indicating if an edge exists between the specified vertices
 */
bool edge_exists(undirected_graph *ud_graph, int vertex_id_1, int vertex_id_2);

/*!
 * @brief Returns the number of vertices in the graph
 * @return An integer representing the number of vertices in the graph
 */
int graph_size(undirected_graph *ud_graph);

/*!
 * @brief Initializes an undirected graph
 * @param ud_graph Pointer to an undirected graph
 * @param size_upper_bound Row and column dimension of the adjacency matrix
 * @return None
 */
void initialize_undirected_graph(undirected_graph *ud_graph, int size_upper_bound);

/*!
 * @brief Releases the memory held by an undirected graph
 * @param ud_graph Pointer to an undirected graph
 * @return None
 */
void free_ud_graph(undirected_graph *ud_graph);

/*!
 * @brief Prints the result of the depth first traversal to the terminal
 * @param d_graph Pointer to an undirected graph
 * @param start Pointer to the node to begin the traversal at
 * @param print_flag A boolean indicating whether or not to print the result to the terminal
 * @return An integer representing the number of vertices in the depth first traversal
 */
int ud_graph_depth_first(undirected_graph *d_graph, int start, bool print_flag);

/*!
 * @brief Prints the result of the breadth first traversal to the terminal
 * @param ud_graph Pointer to an undirected graph
 * @param start_id Id of the vertex to start at
 * @param print_flag A boolean indicating whether or not to print the result to the terminal
 * @return An integer representing the number of vertices in the breadth first traversal
 */
int ud_graph_breadth_first(undirected_graph *ud_graph, int start_id, bool print_flag);

/*!
 * @brief Checks if the graph is connected
 * @param ud_graph Pointer to an undirected graph
 * @return A boolean representing if the graph is connected or not
 */
bool ud_is_connected(undirected_graph *ud_graph);

#endif // UNDIRECTED_GRAPH_H