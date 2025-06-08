#include <stdio.h>
#include <strings.h>
#include <stdbool.h>
#include "../data_structures/graphs/undirected_graph.h"

int main(void)
{
    undirected_graph ud_graph;

    initialize_undirected_graph(&ud_graph, 5);

    add_vertex(&ud_graph, "A", 1);
    add_vertex(&ud_graph, "B", 2);

    printf("\n%d", ud_graph.num_vertices);

    return 0;
}