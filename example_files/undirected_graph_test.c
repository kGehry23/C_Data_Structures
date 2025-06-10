/**
 ********************************************************************************
 * @file    undirected_graph_test.c
 * @author  Kai Gehry
 * @date    2025-06-08
 *
 * @brief   Defines the functionality of the operations defined in the
 *          undirected graph header file.
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/
#include <stdio.h>
#include <strings.h>
#include "../data_structures/graphs/undirected_graph.h"
#include <math.h>

/************************************
 * PRIVATE MACROS AND DEFINES
 ************************************/
// Unique identifiers for each vertex
#define RESOURCE_A 0
#define RESOURCE_B 1
#define RESOURCE_C 2

/*!
 * @brief main function used to test the functionality of the undirected_graph header file.
 */
int main(void)
{
    undirected_graph ud_graph;

    // Initializes the undirected graph
    initialize_undirected_graph(&ud_graph, 5);

    // Adds vertices to the graph
    add_vertex(&ud_graph, RESOURCE_A, 1);
    add_vertex(&ud_graph, RESOURCE_B, 2);
    add_vertex(&ud_graph, RESOURCE_C, 3);

    // Adds an edge
    add_edge(&ud_graph, RESOURCE_A, RESOURCE_B);

    // Checks that the edge exists between the two vertices
    printf("\nEdge between A and B exists: %d", edge_exists(&ud_graph, RESOURCE_A, RESOURCE_B));

    // Removes a vertex from the graph
    remove_vertex(&ud_graph, RESOURCE_C);

    // Removes an edge
    remove_edge(&ud_graph, RESOURCE_A, RESOURCE_B);

    // Checks that the edge exists between the two vertices
    printf("\nEdge between A and B exists: %d", edge_exists(&ud_graph, RESOURCE_A, RESOURCE_B));

    // Returns the value associated with an vertex
    printf("\nValue held by resource B: %d", return_vertex_value(&ud_graph, RESOURCE_B));

    // Displays the number of vertices
    printf("\nNumber of vertices: %d", graph_size(&ud_graph));

    return 0;
}