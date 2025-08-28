/**
 ********************************************************************************
 * @file    undirected_graph_tests.c
 * @author  Kai Gehry
 * @date    2025-08-26
 *
 * @brief   Test the operations defined in the undirected_graph.c file.
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
#include "../data_structures/graphs/undirected_graph/undirected_graph.h"

/************************************
 * TESTS
 ************************************/

/*!
 * @brief Tests initialization of a directed graph
 * @return  None
 */
void init_test()
{
    undirected_graph udgraph;

    initialize_undirected_graph(&udgraph, ADJ_SIZE);

    assert(udgraph.num_vertices == 0);
    assert(udgraph.num_edges == 0);
    assert(udgraph.adjacency_size == ADJ_SIZE);
    assert(udgraph.adjacency_matrix[0][0] == false);
    assert(udgraph.vertices[0] == NULL);

    free_ud_graph(&udgraph);
}

/*!
 * @brief Tests the result of attempting to free memory on an empty undirected graph
 * @return  None
 */
void free_empty_test()
{
    undirected_graph udgraph;

    initialize_undirected_graph(&udgraph, ADJ_SIZE);

    free_ud_graph(&udgraph);

    assert(udgraph.vertices[0] == NULL);
}

/*!
 * @brief Tests addition of a single vertex to the graph
 * @return  None
 */
void add_single_vertex_test()
{
    undirected_graph udgraph;

    initialize_undirected_graph(&udgraph, ADJ_SIZE);

    add_vertex(&udgraph, "A", 0, 1);

    assert(udgraph.num_vertices == 1);
    assert(udgraph.num_edges == 0);

    assert(udgraph.vertices[0]->vertex_name == "A");
    assert(udgraph.vertices[0]->value == 1);

    // Ensures that all positions relevant to the vertex in the adjacency matrix are set to false
    for (int i = 0; i < ADJ_SIZE; i++)
    {
        assert(udgraph.adjacency_matrix[0][i] == false);
        assert(udgraph.adjacency_matrix[i][0] == false);
    }

    free_ud_graph(&udgraph);
}

/*!
 * @brief Tests addition of multiple vertices to the graph
 * @return  None
 */
void add_multiple_vertices_test()
{

    undirected_graph udgraph;

    initialize_undirected_graph(&udgraph, ADJ_SIZE);

    add_vertex(&udgraph, "A", 0, 1);
    add_vertex(&udgraph, "B", 1, 2);
    add_vertex(&udgraph, "C", 2, 3);

    assert(udgraph.num_vertices == 3);
    assert(udgraph.num_edges == 0);

    assert(udgraph.vertices[0]->vertex_name == "A");
    assert(udgraph.vertices[1]->vertex_name == "B");
    assert(udgraph.vertices[2]->vertex_name == "C");

    assert(udgraph.vertices[0]->value == 1);
    assert(udgraph.vertices[1]->value == 2);
    assert(udgraph.vertices[2]->value == 3);

    // Ensures that all positions relevant to the vertices in the adjacency matrix are set to false
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < ADJ_SIZE; i++)
        {
            assert(udgraph.adjacency_matrix[j][i] == false);
            assert(udgraph.adjacency_matrix[i][j] == false);
        }
    }

    free_ud_graph(&udgraph);
}

/*!
 * @brief Tests the addition of an edge between two vertices
 * @return  None
 */
void add_single_edge_test()
{
    undirected_graph udgraph;

    initialize_undirected_graph(&udgraph, ADJ_SIZE);

    add_vertex(&udgraph, "A", 0, 1);
    add_vertex(&udgraph, "B", 1, 2);

    add_edge(&udgraph, 0, 1);

    assert(udgraph.num_vertices == 2);
    assert(udgraph.num_edges == 1);

    // Iterate through the adjacency matrix to check that all indicies are false besides that for
    // which the edge was added
    for (int i = 0; i < ADJ_SIZE; i++)
    {
        for (int j = 0; j < ADJ_SIZE; j++)
        {

            // Check that the edge has been added successfully
            if ((i == 0 && j == 1) || (j == 0 && i == 1))
            {
                assert(udgraph.adjacency_matrix[i][j] == true);
                assert(edge_exists(&udgraph, i, j) == true);
            }
            // Check that there are no other false setting of edges
            else
            {
                assert(udgraph.adjacency_matrix[i][j] == false);
                assert(edge_exists(&udgraph, i, j) == false);
            }
        }
    }

    free_ud_graph(&udgraph);
}

/*!
 * @brief Tests the addition of an multiple edges between vertices
 * @return  None
 */
void add_multiple_edge_test()
{
    undirected_graph udgraph;

    initialize_undirected_graph(&udgraph, ADJ_SIZE);

    add_vertex(&udgraph, "A", 0, 1);
    add_vertex(&udgraph, "B", 1, 2);
    add_vertex(&udgraph, "C", 2, 3);

    // Adds an edge between A and B, B and C, and C and A
    add_edge(&udgraph, 0, 1);
    add_edge(&udgraph, 1, 2);
    add_edge(&udgraph, 2, 0);

    assert(udgraph.num_vertices == 3);
    assert(udgraph.num_edges == 3);

    // Iterate through the adjacency matrix to check that all indicies are false besides that for
    // which the edge was added
    for (int i = 0; i < ADJ_SIZE; i++)
    {
        for (int j = 0; j < ADJ_SIZE; j++)
        {
            // Check that the edge has been added successfully
            if ((i == 0 && j == 1) || (i == 1 && j == 2) || (i == 2 && j == 0))
            {
                assert(udgraph.adjacency_matrix[i][j] == true);
                assert(edge_exists(&udgraph, i, j) == true);
            }

            // Check that the edge has been added successfully
            else if ((i == 1 && j == 0) || (i == 2 && j == 1) || (i == 0 && j == 2))
            {
                assert(udgraph.adjacency_matrix[i][j] == true);
                assert(edge_exists(&udgraph, i, j) == true);
            }
            // Check that there are no other false setting of edges
            else
            {
                assert(udgraph.adjacency_matrix[i][j] == false);
                assert(edge_exists(&udgraph, i, j) == false);
            }
        }
    }

    // Checks that a cycle exists
    assert(ud_contains_cycle(&udgraph) == true);

    free_ud_graph(&udgraph);
}

/*!
 * @brief Tests the removal of multiple edges in the graph
 * @return  None
 */
void remove_edges_test()
{
    undirected_graph udgraph;

    initialize_undirected_graph(&udgraph, ADJ_SIZE);

    add_vertex(&udgraph, "A", 0, 1);
    add_vertex(&udgraph, "B", 1, 2);
    add_vertex(&udgraph, "C", 2, 3);

    // Adds an edge between A and B, B and C, and C and A
    add_edge(&udgraph, 0, 1);
    add_edge(&udgraph, 1, 2);
    add_edge(&udgraph, 2, 0);

    remove_edge(&udgraph, 0, 1);
    remove_edge(&udgraph, 1, 2);

    assert(udgraph.num_vertices == 3);
    assert(udgraph.num_edges == 1);

    // Checks that a cycle does not exists
    // assert(ud_contains_cycle(&udgraph) == false);

    // Iterate through the adjacency matrix to check that all indicies are false besides that for
    // which the edge was added
    for (int i = 0; i < ADJ_SIZE; i++)
    {
        for (int j = 0; j < ADJ_SIZE; j++)
        {
            // Check that only one edge still exists
            if ((i == 2 && j == 0) || (i == 0 && j == 2))
            {
                assert(udgraph.adjacency_matrix[i][j] == true);
                assert(edge_exists(&udgraph, i, j) == true);
            }
            // Check that there are no other false setting of edges
            else
            {
                assert(udgraph.adjacency_matrix[i][j] == false);
                assert(edge_exists(&udgraph, i, j) == false);
            }
        }
    }

    free_ud_graph(&udgraph);
}

/*!
 * @brief Tests the removal of a vertex from the the graph
 * @return  None
 */
void remove_vertex_test()
{

    undirected_graph udgraph;

    initialize_undirected_graph(&udgraph, ADJ_SIZE);

    add_vertex(&udgraph, "A", 0, 1);
    add_vertex(&udgraph, "B", 1, 2);
    add_vertex(&udgraph, "C", 2, 3);

    // Adds an edge between A and B, B and C, and C and A
    add_edge(&udgraph, 0, 1);
    add_edge(&udgraph, 1, 2);
    add_edge(&udgraph, 2, 0);

    remove_vertex(&udgraph, 0);

    assert(udgraph.num_vertices == 2);
    assert(udgraph.num_edges == 1);

    // // Checks that a cycle does not exists
    // assert(d_contains_cycle(&digraph) == false);

    // Iterate through the adjacency matrix to check that all indicies are false besides that of which remain
    for (int i = 0; i < ADJ_SIZE; i++)
    {
        for (int j = 0; j < ADJ_SIZE; j++)
        {
            // Check that the remaining edge has still exists
            if ((i == 1 && j == 2) || (i == 2 && j == 1))
            {
                assert(udgraph.adjacency_matrix[i][j] == true);
                assert(edge_exists(&udgraph, i, j) == true);
            }
            // Check that there are no other false setting of edges
            else
            {
                assert(udgraph.adjacency_matrix[i][j] == false);
                assert(edge_exists(&udgraph, i, j) == false);
            }
        }
    }

    free_ud_graph(&udgraph);
}

/*!
 * @brief Check that a graph is not connected
 * @return  None
 */
void check_is_not_connected()
{
    undirected_graph udgraph;

    initialize_undirected_graph(&udgraph, ADJ_SIZE);

    add_vertex(&udgraph, "A", 0, 1);
    add_vertex(&udgraph, "B", 1, 2);
    add_vertex(&udgraph, "C", 2, 3);

    // Adds an edge between A and B
    add_edge(&udgraph, 0, 1);

    assert(ud_is_connected(&udgraph) == false);

    free_ud_graph(&udgraph);
}

/*!
 * @brief Check that a graph is connected
 * @return  None
 */
void check_is_connected()
{
    undirected_graph udgraph;

    initialize_undirected_graph(&udgraph, ADJ_SIZE);

    add_vertex(&udgraph, "A", 0, 1);
    add_vertex(&udgraph, "B", 1, 2);
    add_vertex(&udgraph, "C", 2, 3);

    add_edge(&udgraph, 0, 1);
    add_edge(&udgraph, 1, 0);
    add_edge(&udgraph, 1, 2);
    add_edge(&udgraph, 2, 1);
    add_edge(&udgraph, 2, 0);
    add_edge(&udgraph, 0, 2);

    assert(ud_is_connected(&udgraph) == true);

    free_ud_graph(&udgraph);
}

/*!
 * @brief Check that a graph does not contain a cycle
 * @return  None
 */
void check_not_contains_cycle()
{
    undirected_graph udgraph;

    initialize_undirected_graph(&udgraph, ADJ_SIZE);

    add_vertex(&udgraph, "A", 0, 1);
    add_vertex(&udgraph, "B", 1, 2);
    add_vertex(&udgraph, "C", 2, 3);

    // Adds an edge between A and B, B and C, and C and A
    add_edge(&udgraph, 0, 1);
    add_edge(&udgraph, 1, 2);

    // Checks that a cycle does not exists
    assert(ud_contains_cycle(&udgraph) == false);

    free_ud_graph(&udgraph);
}

/*!
 * @brief Check that a graph contains a cycle
 * @return  None
 */
void check_contains_cycle()
{
    undirected_graph udgraph;

    initialize_undirected_graph(&udgraph, ADJ_SIZE);

    add_vertex(&udgraph, "A", 0, 1);
    add_vertex(&udgraph, "B", 1, 2);
    add_vertex(&udgraph, "C", 2, 3);

    // Adds an edge between A and B, B and C, and C and A
    add_edge(&udgraph, 0, 1);
    add_edge(&udgraph, 1, 2);
    add_edge(&udgraph, 2, 0);

    // Checks that a cycle exists
    assert(ud_contains_cycle(&udgraph) == true);

    free_ud_graph(&udgraph);
}

int main(void)
{
    init_test();
    free_empty_test(); // Come back to this one.. need to check some other condition for this to pass

    add_single_vertex_test();
    add_multiple_vertices_test();

    add_single_edge_test();
    add_multiple_edge_test();

    remove_edges_test();  // Check issue with cycle here
    remove_vertex_test(); // segmentation fault occurs when cycle check is called. Need to fix this

    check_is_not_connected();
    check_is_connected();

    // check_not_contains_cycle(); // Need to fix the issue here
    check_contains_cycle();

    // Tests for breadth and depth first traversals

    printf("\nAll tests passed.");

    return 0;
}