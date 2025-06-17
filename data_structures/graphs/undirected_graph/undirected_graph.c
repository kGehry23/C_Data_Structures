/**
 ********************************************************************************
 * @file    undirected_graph.c
 * @author  Kai Gehry
 * @date    2025-06-07
 *
 * @brief   Defines the operations on an undirected graph
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/
#include "undirected_graph.h"

/************************************
 * FUNCTION DEFINITIONS
 ************************************/

/*!
 * @brief Adds a vertex to the undirected graph
 * @param ud_graph Pointer to an undirected graph
 * @param identifier Value to identify the vertex by
 * @param vertex_value Value stored by the vertex
 * @return None
 */
void add_vertex(undirected_graph *ud_graph, int identifier, void *vertex_value)
{
    // Adds the vertex if a vertex has not already been allocated to the specified position in the vertex list
    if (ud_graph->vertices[identifier] == NULL)
    {
        // Allocate memory for a new undirected graph vertex
        undirected_graph_vertex *new_vertex = (undirected_graph_vertex *)malloc(sizeof(undirected_graph_vertex));

        /*
          Assign the specified identifier, value stored by the new node, and an associated index into the adjacency
          matrix.
        */
        new_vertex->identifier = identifier;
        new_vertex->value = vertex_value;
        new_vertex->adj_index = identifier;

        // Add vertex to the graph
        ud_graph->vertices[identifier] = new_vertex;

        // Increment the number of vertices in the graph
        ud_graph->num_vertices = ud_graph->num_vertices + 1;
    }
}

/*!
 * @brief Removes and returns the value associated with the specified vertex
 *        in the undirected graph
 * @param ud_graph Pointer to an undirected graph
 * @param identifier Value to identify the vertex by
 * @return None
 */
void *remove_vertex(undirected_graph *ud_graph, int identifier)
{
    // Removes the vertex if it is in the graph
    if (ud_graph->vertices[identifier] != NULL)
    {
        // Pointer to the vertex to be removed
        void *removed_vertex_value = (ud_graph->vertices[identifier])->value;

        // Free memory held by removed vertex
        free(ud_graph->vertices[identifier]);
        // Set the pointer to the vertex to NULL to avoid dangling pointer
        ud_graph->vertices[identifier] = NULL;

        // Sets all the edges that may exist attached to the node to remove to FALSE in the adjacency matrix
        for (int i = 0; i < ud_graph->adjacency_size; i++)
        {
            if ((ud_graph->adjacency_matrix)[i][identifier] == 1)
            {
                (ud_graph->adjacency_matrix)[i][identifier] = 0;
                (ud_graph->adjacency_matrix)[identifier][i] = 0;
            }
        }

        // Decrement the counter for the number of vertices
        ud_graph->num_vertices = ud_graph->num_vertices - 1;

        return removed_vertex_value;
    }
}

/*!
 * @brief Returns the value stored by the specified vertex.
 * @param ud_graph Pointer to an undirected graph
 * @param identifier Value to identify the vertex by
 * @return The value stored by the specified vertex
 */
void *return_vertex_value(undirected_graph *ud_graph, int identifier)
{
    return (ud_graph->vertices[identifier])->value;
}

/*!
 * @brief Adds an edge between two vertices in the undirected graph
 * @param ud_graph Pointer to an undirected graph
 * @param vertex_id_1 Identifier of the first vertex
 * @param vertex_id_2 Identifier of the second vertex
 * @return None
 */
void add_edge(undirected_graph *ud_graph, int vertex_id_1, int vertex_id_2)
{

    // Only adds the edge if an edge does not already exist
    if (edge_exists(ud_graph, vertex_id_1, vertex_id_2) == 0)
    {
        // Updates the relevant indices in the adjacency matrix to TRUE (1)
        (ud_graph->adjacency_matrix)[vertex_id_1][vertex_id_2] = 1;
        (ud_graph->adjacency_matrix)[vertex_id_2][vertex_id_1] = 1;

        // Increment the counter for the number of edges
        ud_graph->num_edges = ud_graph->num_edges + 1;
    }
}

/*!
 * @brief Removes an edge between two vertices in the undirected graph
 * @param ud_graph Pointer to an undirected graph
 * @param vertex_id_1 Identifier of the first vertex
 * @param vertex_id_2 Identifier of the second vertex
 * @return None
 */
void remove_edge(undirected_graph *ud_graph, int vertex_id_1, int vertex_id_2)
{

    // Removes the edge if it exists
    if (edge_exists(ud_graph, vertex_id_1, vertex_id_2) == 1)
    {
        // Updates the relevant indices in the adjacency matrix to FALSE (0)
        (ud_graph->adjacency_matrix)[vertex_id_1][vertex_id_2] = 0;
        (ud_graph->adjacency_matrix)[vertex_id_2][vertex_id_1] = 0;

        // Decrement the counter for the number of edges
        ud_graph->num_edges = ud_graph->num_edges - 1;
    }
}

/*!
 * @brief Checks if there is an edge between two vertices
 * @param ud_graph Pointer to an undirected graph
 * @param vertex_id_1 Identifier of the first vertex
 * @param vertex_id_2 Identifier of the second vertex
 * @return A boolean value indicating if an edge exists between the specified vertices
 */
bool edge_exists(undirected_graph *ud_graph, int vertex_id_1, int vertex_id_2)
{
    // Checks if the specified vertices have an edge between them
    return ((ud_graph->adjacency_matrix)[vertex_id_1][vertex_id_2] == 0);
}

/*!
 * @brief Returns the number of vertices in the graph
 * @return An integer representing the number of vertices in the graph
 */
int graph_size(undirected_graph *ud_graph)
{
    return ud_graph->num_vertices;
}

/*!
 * @brief Initializes an undirected graph
 * @param ud_graph Pointer to an undirected graph
 * @param size_upper_bound Row and column dimension of the adjacency matrix
 * @return None
 */
void initialize_undirected_graph(undirected_graph *ud_graph, int size_upper_bound)
{
    // Sets the number of vertices and the number of edges to 0
    ud_graph->num_vertices = 0;
    ud_graph->num_edges = 0;

    // Assign the number of rows and columns to the specified upper bound
    ud_graph->adjacency_size = size_upper_bound;

    ud_graph->vertices = (undirected_graph_vertex **)malloc(size_upper_bound * sizeof(undirected_graph_vertex *));

    for (int i = 0; i < size_upper_bound; i++)
    {
        (ud_graph->vertices)[i] = NULL;
    }

    // Resize the main array to the required size
    ud_graph->adjacency_matrix = (bool **)malloc(size_upper_bound * sizeof(bool *));

    // Populate the main array with internal arrays
    for (int j = 0; j < size_upper_bound; j++)
    {
        (ud_graph->adjacency_matrix)[j] = (bool *)malloc(size_upper_bound * sizeof(bool));
    }

    // Initialize all elements in the adjacency matrix to 0
    for (int k = 0; k < size_upper_bound; k++)
    {
        for (int l = 0; l < size_upper_bound; l++)
        {
            (ud_graph->adjacency_matrix)[k][l] = 0;
        }
    }
}

/*!
 * @brief Releases the memory held by an undirected graph
 * @param ud_graph Pointer to an undirected graph
 * @return None
 */
void free_ud_graph(undirected_graph *ud_graph)
{
    // Free the memory held by the list of undirected graph vertices
    for (int i = 0; i < ud_graph->adjacency_size; i++)
    {
        free(ud_graph->vertices[i]);
        ud_graph->vertices[i] = NULL;
    }

    // Free the memory held by the adjacency matrix
    for (int j = 0; j < ud_graph->adjacency_size; j++)
    {
        for (int k = 0; k < ud_graph->adjacency_size; k++)
        {
            free(&((ud_graph->adjacency_matrix)[j][k]));
        }
    }
}
