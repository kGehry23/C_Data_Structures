/**
 ********************************************************************************
 * @file    directed_graph_tests.c
 * @author  Kai Gehry
 * @date    2025-08-26
 *
 * @brief   Test the operations defined in the directed_graph.c file.
 ********************************************************************************
 */

/************************************
 * DEFINES
 ************************************/
#define ADJ_SIZE 5

/************************************
 * INCLUDES
 ************************************/
#include <assert.h>
#include "../data_structures/graphs/directed_graph/directed_graph.h"

/************************************
 * TESTS
 ************************************/

/*!
 * @brief Tests initialization of a directed graph
 * @param list  Pointer to a directed graph
 * @return  None
 */
void init_test()
{
    directed_graph digraph;

    initialize_directed_graph(&digraph, ADJ_SIZE);

    assert(digraph.num_vertices == 0);
    assert(digraph.num_edges == 0);
    assert(digraph.adjacency_size == ADJ_SIZE);
    assert(digraph.adjacency_matrix[0][0] == false);
    assert(digraph.vertices[0] == NULL);

    free_d_graph(&digraph);
}

/*!
 * @brief Tests the result of attempting to free memory on an empty directed graph
 * @return  None
 */
void free_empty_test()
{
    directed_graph digraph;

    initialize_directed_graph(&digraph, ADJ_SIZE);

    free_d_graph(&digraph);

    assert(digraph.vertices[0] == NULL);
}

int main(void)
{

    init_test();
    free_empty_test(); // Come back to this one.. need to check some other condition for this to pass

    printf("\nAll tests passed.");

    return 0;
}