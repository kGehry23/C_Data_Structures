
/**
 ********************************************************************************
 * @file    directed_graph_example.c
 * @author  Kai Gehry
 * @date    2025-06-08
 *
 * @brief   Tests the functionality of the operations defined in the
 *          directed graph header file.
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/
#include <stdio.h>
#include <strings.h>
#include "../data_structures/graphs/directed_graph/directed_graph.h"

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
    directed_graph d_graph;

    // Initializes the undirected graph
    initialize_directed_graph(&d_graph, 5);

    // Adds vertices to the graph
    add_vertex(&d_graph, "A", RESOURCE_A, 1);
    add_vertex(&d_graph, "B", RESOURCE_B, 2);
    add_vertex(&d_graph, "C", RESOURCE_C, 3);

    // Adds an edge
    add_edge(&d_graph, RESOURCE_A, RESOURCE_B);

    // Checks that the directed edge exists between the two vertices
    printf("\nEdge between A and B exists: %d", edge_exists(&d_graph, RESOURCE_A, RESOURCE_B));

    // Checks that an edge from A to B exists. An edge from B to A should not exist in this case.
    printf("\nEdge between B and A exists: %d", edge_exists(&d_graph, RESOURCE_B, RESOURCE_A));

    // Removes a vertex from the graph
    remove_vertex(&d_graph, RESOURCE_C);

    // Removes an edge
    remove_edge(&d_graph, RESOURCE_A, RESOURCE_B);

    // Checks that the edge exists between the two vertices
    printf("\nEdge between A and B exists: %d", edge_exists(&d_graph, RESOURCE_A, RESOURCE_B));

    // Returns the value associated with an vertex
    printf("\nValue held by resource B: %d", return_vertex_value(&d_graph, RESOURCE_B));

    // Displays the number of vertices
    printf("\nNumber of vertices: %d", graph_size(&d_graph));

    // Frees the memory held by the directed graph
    free_d_graph(&d_graph);

    return 0;
}