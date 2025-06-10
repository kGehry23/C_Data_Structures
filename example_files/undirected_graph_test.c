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

    // Adds an edge
    add_edge(&ud_graph, RESOURCE_A, RESOURCE_B);

    // Checks that the edge exists between the two vertices
    printf("\nConnected: %d", edge_exists(&ud_graph, RESOURCE_A, RESOURCE_B));

    // // Removes an edge
    // remove_edge(&ud_graph, RESOURCE_A, RESOURCE_B);

    // // Checks that the edge exists between the two vertices
    // printf("\nConnected: %d", is_connected(&ud_graph, RESOURCE_A, RESOURCE_B));

    printf("\n%d", remove_vertex(&ud_graph, RESOURCE_A));

    // Checks that the edge exists between the two vertices
    printf("\nConnected: %d", edge_exists(&ud_graph, RESOURCE_A, RESOURCE_B));

    // Displays the number of vertices
    printf("\n%d", ud_graph.num_vertices);

    return 0;
}