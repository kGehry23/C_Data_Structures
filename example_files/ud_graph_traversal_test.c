/**
 ********************************************************************************
 * @file    ud_graph_traversal_test.c
 * @author  Kai Gehry
 * @date    2025-06-08
 *
 * @brief   Tests the output of the breadth first traversal function defined
 *          in the undirected_graph.h file. Example graph tested is that shown
 *          in:
 *
 *          example_files/depth_first_example.png
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/
#include <stdio.h>
#include <strings.h>
#include "../data_structures/graphs/undirected_graph/undirected_graph.h"

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
 * @brief main function used to test the functionality of the undirected_graph header file.
 */
int main(void)
{
    undirected_graph ud_graph;

    // Initializes the undirected graph
    initialize_undirected_graph(&ud_graph, 10);

    // Adds vertices to the graph
    add_vertex(&ud_graph, "A", RESOURCE_A, 1);
    add_vertex(&ud_graph, "B", RESOURCE_B, 2);
    add_vertex(&ud_graph, "C", RESOURCE_C, 3);
    add_vertex(&ud_graph, "D", RESOURCE_D, 4);
    add_vertex(&ud_graph, "E", RESOURCE_E, 5);
    add_vertex(&ud_graph, "F", RESOURCE_F, 6);
    add_vertex(&ud_graph, "G", RESOURCE_G, 7);

    // Adds an edge
    add_edge(&ud_graph, RESOURCE_D, RESOURCE_A);
    add_edge(&ud_graph, RESOURCE_A, RESOURCE_E);
    add_edge(&ud_graph, RESOURCE_A, RESOURCE_C);
    add_edge(&ud_graph, RESOURCE_E, RESOURCE_C);
    add_edge(&ud_graph, RESOURCE_C, RESOURCE_G);
    add_edge(&ud_graph, RESOURCE_C, RESOURCE_B);
    add_edge(&ud_graph, RESOURCE_C, RESOURCE_F);
    add_edge(&ud_graph, RESOURCE_F, RESOURCE_B);

    // Checks if graph is connected
    printf("\nIs connected: %d", ud_is_connected(&ud_graph));
    printf("\nContains Cycle: %d", ud_contains_cycle(&ud_graph));

    // printf("\n\nBreadth First Traversals: \n");

    // Perform breadth first traversals
    printf("\nNumber of elements: %d", ud_graph_breadth_first(&ud_graph, RESOURCE_A, 1));
    printf("\nNumber of elements: %d", ud_graph_breadth_first(&ud_graph, RESOURCE_C, 1));
    printf("\nNumber of elements: %d", ud_graph_breadth_first(&ud_graph, RESOURCE_E, 1));

    printf("\n\n\nDepth First Traversals: \n");

    // Perform depth first traversals
    printf("\n\nNumber of elements: %d", ud_graph_depth_first(&ud_graph, RESOURCE_A, 1));
    printf("\nNumber of elements: %d", ud_graph_depth_first(&ud_graph, RESOURCE_C, 1));
    printf("\nNumber of elements: %d", ud_graph_depth_first(&ud_graph, RESOURCE_E, 1));

    // Free the memory held by the undirected graph
    free_ud_graph(&ud_graph);

    return 0;
}