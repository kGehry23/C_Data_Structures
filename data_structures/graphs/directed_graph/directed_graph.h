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
#include <string.h>
#include "../../queues/array_queue/array_queue.h"
#include "../../stacks/array_stack/array_stack.h"

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
    // String identifier
    char *vertex_name;
    // Stores the index of the vertex in the adjacency matrix
    int adj_index;
    // Boolean indicating if the vertex has been visited during a traversal
    bool visited;

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
    // Pointer to an array of directed graph vertex pointers
    directed_graph_vertex **vertices;
    // Pointer to 2D array of booleans which indicate if vertices are connected
    bool **adjacency_matrix;

} directed_graph;

/************************************
 * FUNCTION PROTOTYPES
 ************************************/

/*!
 * @brief Adds a vertex to the directed graph
 * @param ud_graph Pointer to a directed graph
 * @param identifier Value to identify the vertex by
 * @param vertex_value Value stored by the vertex
 * @return None
 */
void add_vertex(directed_graph *d_graph, char *name, int identifier, void *vertex_value);

/*!
 * @brief Removes and returns the value associated with the specified vertex
 *        in the directed graph
 * @param di_graph Pointer to a directed graph
 * @param identifier Value to identify the vertex by
 * @return None
 */
void *remove_vertex(directed_graph *di_graph, int identifier);

/*!
 * @brief Returns the value stored by the specified vertex.
 * @param di_graph Pointer to an directed graph
 * @param identifier Value to identify the vertex by
 * @return The value stored by the specified vertex
 */
void *return_vertex_value(directed_graph *di_graph, int identifier);

/*!
 * @brief Adds an edge between two vertices in the directed graph
 * @param di_graph Pointer to an directed graph
 * @param from_id Identifier of vertex the edge comes from
 * @param to_id Identifier of the vertex the edge goes to
 * @return None
 */
void add_edge(directed_graph *di_graph, int from_id, int to_id);

/*!
 * @brief Removes an edge between two vertices in the directed graph
 * @param di_graph Pointer to an directed graph
 * @param from_id Identifier of vertex the edge comes from
 * @param to_id Identifier of the vertex the edge goes to
 * @return None
 */
void remove_edge(directed_graph *di_graph, int from_id, int to_id);

/*!
 * @brief Checks if there is an edge between two vertices
 * @param di_graph Pointer to an directed graph
 * @param from_id Identifier of vertex the edge comes from
 * @param to_id Identifier of the vertex the edge goes to
 * @return A boolean value indicating if an edge exists between the specified vertices
 */
bool edge_exists(directed_graph *di_graph, int from_id, int to_id);

/*!
 * @brief Returns the number of vertices in the graph
 * @return An integer representing the number of vertices in the graph
 */
int graph_size(directed_graph *di_graph);

/*!
 * @brief Initializes a directed graph
 * @param di_graph Pointer to an directed graph
 * @param size_upper_bound Row and column dimension of the adjacency matrix
 * @return None
 */
void initialize_directed_graph(directed_graph *di_graph, int size_upper_bound);

/*!
 * @brief Releases the memory held by the directed graph
 * @param di_graph Pointer to a directed graph
 * @return None
 */
void free_di_graph(directed_graph *di_graph);

/*!
 * @brief Preforms a depth first traversal of the graph.
 *
 *        Adapted from Java Foundations, 5th Ed.
 *
 * @param di_graph Pointer to a directed graph
 * @param start_id Id of the vertex to start at
 * @param print_flag A boolean indicating whether or not to print the result to the terminal
 * @return An integer representing the number of vertices in the depth first traversal
 */
int di_graph_depth_first(directed_graph *di_graph, int start_id, bool print_flag);

/*!
 * @brief Performs a breadth first traversal of the graph
 * @param di_graph Pointer to a directed graph
 * @param start_id Id of the vertex to start at
 * @param print_flag A boolean indicating whether or not to print the result to the terminal
 * @return An integer representing the number of vertices in the breadth first traversal
 */
int di_graph_breadth_first(directed_graph *di_graph, int start_id, bool print_flag);

/*!
 * @brief Checks if the graph is connected
 * @param di_graph Pointer to a directed graph
 * @return A boolean representing if the graph is connected or not
 */
bool di_is_connected(directed_graph *di_graph);

/*!
 * @brief Checks if the graph contains a cycle
 * @param di_graph Pointer to a directed graph
 * @return A boolean representing if the graph contains a cycle or not
 */
bool di_contains_cycle(directed_graph *di_graph);

#endif // DIRECTED_GRAPH_H