#include <stdio.h>
#include <strings.h>
#include "../data_structures/graphs/undirected_graph.h"

int main(void)
{
    undirected_graph ud_graph;

    initialize_undirected_graph(&ud_graph, 5);

    add_vertex(&ud_graph);
    add_vertex(&ud_graph);

    // printf("\n%d", ud_graph.num_vertices);

    return 0;
}