#include <stdio.h>
#include <strings.h>
#include "../data_structures/graphs/undirected_graph.h"

#define RESOURCE_A 0
#define RESOURCE_B 1

int main(void)
{

    undirected_graph ud_graph;

    initialize_undirected_graph(&ud_graph, 5);

    add_vertex(&ud_graph, RESOURCE_A, 1);
    add_vertex(&ud_graph, RESOURCE_B, 2);

    add_edge(&ud_graph, RESOURCE_A, RESOURCE_B);

    printf("\nConnected: %d", is_connected(&ud_graph, RESOURCE_A, RESOURCE_B));

    printf("\n%d", ud_graph.num_vertices);

    return 0;
}