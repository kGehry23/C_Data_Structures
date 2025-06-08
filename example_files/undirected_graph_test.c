#include <stdio.h>
#include <strings.h>
#include "../data_structures/graphs/undirected_graph.h"

int main(void)
{
    undirected_graph ud_graph;

    initialize_undirected_graph(&ud_graph);

    add_vertex(&ud_graph, "A", 10);
    add_vertex(&ud_graph, "B", 6);

    printf("\n%d", ud_graph.num_vertices);

    return 0;
}