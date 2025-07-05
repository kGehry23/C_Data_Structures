/**
 ********************************************************************************
 * @file    d_graph_traversal_test.c
 * @author  Kai Gehry
 * @date    2025-07-04
 *
 * @brief   Tests the output of the traversal algorithms as well as connectivity
 *          and existence of cycles defined in the directed_graph header file.
 *
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
#define RESOURCE_D 3
#define RESOURCE_E 4
#define RESOURCE_F 5
#define RESOURCE_G 6

/*!
 * @brief main function used to test the functionality of the directed_graph header file.
 */
int main(void)
{
    directed_graph d_graph;

    // Initializes the directed graph
    initialize_directed_graph(&d_graph, 10);

    // Adds vertices to the graph
    add_vertex(&d_graph, "A", RESOURCE_A, 1);
    add_vertex(&d_graph, "B", RESOURCE_B, 2);
    add_vertex(&d_graph, "C", RESOURCE_C, 3);
    add_vertex(&d_graph, "D", RESOURCE_D, 4);
    add_vertex(&d_graph, "E", RESOURCE_E, 5);
    add_vertex(&d_graph, "F", RESOURCE_F, 6);
    add_vertex(&d_graph, "G", RESOURCE_G, 7);

    // Adds an edge
    add_edge(&d_graph, RESOURCE_D, RESOURCE_A);
    add_edge(&d_graph, RESOURCE_D, RESOURCE_E);
    add_edge(&d_graph, RESOURCE_E, RESOURCE_A);
    add_edge(&d_graph, RESOURCE_A, RESOURCE_C);
    add_edge(&d_graph, RESOURCE_C, RESOURCE_G);
    add_edge(&d_graph, RESOURCE_B, RESOURCE_C);
    add_edge(&d_graph, RESOURCE_C, RESOURCE_F);
    add_edge(&d_graph, RESOURCE_F, RESOURCE_B);

    // Checks if graph is connected
    printf("\nIs connected: %d", d_is_connected(&d_graph));
    printf("\nContains Cycle: %d", d_contains_cycle(&d_graph));

    printf("\n\nBreadth First Traversals: \n");

    // Perform breadth first traversals
    printf("\nNumber of elements: %d", d_graph_breadth_first(&d_graph, RESOURCE_A, 1));
    printf("\nNumber of elements: %d", d_graph_breadth_first(&d_graph, RESOURCE_C, 1));
    printf("\nNumber of elements: %d", d_graph_breadth_first(&d_graph, RESOURCE_E, 1));

    printf("\n\n\nDepth First Traversals: \n");

    // Perform depth first traversals
    printf("\n\nNumber of elements: %d", d_graph_depth_first(&d_graph, RESOURCE_A, 1));
    printf("\nNumber of elements: %d", d_graph_depth_first(&d_graph, RESOURCE_C, 1));
    printf("\nNumber of elements: %d", d_graph_depth_first(&d_graph, RESOURCE_E, 1));

    // Free the memory held by the undirected graph
    free_d_graph(&d_graph);

    return 0;
}