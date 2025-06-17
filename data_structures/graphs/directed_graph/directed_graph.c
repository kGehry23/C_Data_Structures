/**
 ********************************************************************************
 * @file    directed_graph.c
 * @author  Kai Gehry
 * @date    2025-06-15
 *
 * @brief   Defines the operations on a directed graph
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/
#include "directed_graph.h"

/************************************
 * FUNCTION DEFINITIONS
 ************************************/

/*!
 * @brief Adds a vertex to the directed graph
 * @param d_graph Pointer to an directed graph
 * @param identifier Value to identify the vertex by
 * @param vertex_value Value stored by the vertex
 * @return None
 */
void add_vertex(directed_graph *d_graph, int identifier, void *vertex_value)
{
    // Adds the vertex if a vertex has not already been allocated to the specified position in the vertex list
    if (d_graph->vertices[identifier] == NULL)
    {
        // Allocate memory for a new directed graph vertex
        directed_graph_vertex *new_vertex = (directed_graph_vertex *)malloc(sizeof(directed_graph_vertex));

        /*
          Assign the specified identifier, value stored by the new node, and an associated index into the adjacency
          matrix.
        */
        new_vertex->identifier = identifier;
        new_vertex->value = vertex_value;
        new_vertex->adj_index = identifier;

        // Add vertex to the graph
        d_graph->vertices[identifier] = new_vertex;

        // Increment the number of vertices in the graph
        d_graph->num_vertices = d_graph->num_vertices + 1;
    }
}

/*!
 * @brief Removes and returns the value associated with the specified vertex
 *        in the undirected graph
 * @param d_graph Pointer to an directed graph
 * @param identifier Value to identify the vertex by
 * @return The value associated with the specified vertex if it exists
 */
void *remove_vertex(directed_graph *d_graph, int identifier)
{
    // Removes the vertex if it is in the graph
    if (d_graph->vertices[identifier] != NULL)
    {
        // Pointer to the vertex to be removed
        void *removed_vertex_value = (d_graph->vertices[identifier])->value;

        // Free memory held by removed vertex
        free(d_graph->vertices[identifier]);
        // Set the pointer to the vertex to NULL to avoid dangling pointer
        d_graph->vertices[identifier] = NULL;

        // Sets all the edges that may exist attached to the node to remove to FALSE in the adjacency matrix
        for (int i = 0; i < d_graph->adjacency_size; i++)
        {
            if ((d_graph->adjacency_matrix)[i][identifier] == 1)
            {
                (d_graph->adjacency_matrix)[i][identifier] = 0;
                (d_graph->adjacency_matrix)[identifier][i] = 0;
            }
        }

        // Decrement the counter for the number of vertices
        d_graph->num_vertices = d_graph->num_vertices - 1;

        return removed_vertex_value;
    }

    else
    {
        return NULL;
    }
}

/*!
 * @brief Returns the value stored by the specified vertex.
 * @param d_graph Pointer to a directed graph
 * @param identifier Value to identify the vertex by
 * @return The value stored by the specified vertex
 */
void *return_vertex_value(directed_graph *d_graph, int identifier)
{
    return (d_graph->vertices[identifier])->value;
}

/*!
 * @brief Checks if there is an edge between two vertices
 * @param d_graph Pointer to a directed graph
 * @param vertex_id_1 Identifier of the first vertex
 * @param vertex_id_2 Identifier of the second vertex
 * @return A boolean value indicating if an edge exists between the specified vertices
 */
bool edge_exists(directed_graph *d_graph, int vertex_id_1, int vertex_id_2)
{
    // Checks if the specified vertices have an edge between them
    return ((d_graph->adjacency_matrix)[vertex_id_1][vertex_id_2] == 1);
}

/*!
 * @brief Adds an edge between two vertices in the directed graph
 * @param d_graph Pointer to a directed graph
 * @param from_vertex_id Identifier of the first from which the edge is directed from.
 * @param to_vertex_id Identifier of the vertex to which the edge goes.
 * @return None
 */
void add_edge(directed_graph *d_graph, int from_vertex_id, int to_vertex_id)
{
    // Only adds the edge if an edge does not already exist
    if (edge_exists(d_graph, from_vertex_id, to_vertex_id) == 0)
    {
        // Updates the relevant indices in the adjacency matrix to TRUE (1)
        (d_graph->adjacency_matrix)[from_vertex_id][to_vertex_id] = 1;

        // Increment the counter for the number of edges
        d_graph->num_edges = d_graph->num_edges + 1;
    }
}

/*!
 * @brief Removes an edge between two vertices in the directed graph
 * @param ud_graph Pointer to a directed graph
 * @param from_vertex_id Identifier of the first from which the edge is directed from.
 * @param to_vertex_id Identifier of the vertex to which the edge goes.
 * @return None
 */
void remove_edge(directed_graph *d_graph, int from_vertex_id, int to_vertex_id)
{
    // Removes the edge if it exists
    if (edge_exists(d_graph, from_vertex_id, to_vertex_id) == 1)
    {
        // Updates the relevant indices in the adjacency matrix to FALSE (0)
        (d_graph->adjacency_matrix)[from_vertex_id][to_vertex_id] = 0;

        // Decrement the counter for the number of edges
        d_graph->num_edges = d_graph->num_edges - 1;
    }
}

/*!
 * @brief Returns the number of vertices in the graph
 * @return An integer representing the number of vertices in the graph
 */
int graph_size(directed_graph *d_graph)
{
    return d_graph->num_vertices;
}

/*!
 * @brief Initializes a directed graph
 * @param ud_graph Pointer to a directed graph
 * @param size_upper_bound Row and column dimension of the adjacency matrix
 * @return None
 */
void initialize_directed_graph(directed_graph *d_graph, int size_upper_bound)
{
    // Sets the number of vertices and the number of edges to 0
    d_graph->num_vertices = 0;
    d_graph->num_edges = 0;

    // Assign the number of rows and columns to the specified upper bound
    d_graph->adjacency_size = size_upper_bound;

    d_graph->vertices = (directed_graph_vertex **)malloc(size_upper_bound * sizeof(directed_graph_vertex *));

    for (int i = 0; i < size_upper_bound; i++)
    {
        (d_graph->vertices)[i] = NULL;
    }

    // Resize the main array to the required size
    d_graph->adjacency_matrix = (bool **)malloc(size_upper_bound * sizeof(bool *));

    // Populate the main array with internal arrays
    for (int j = 0; j < size_upper_bound; j++)
    {
        (d_graph->adjacency_matrix)[j] = (bool *)malloc(size_upper_bound * sizeof(bool));
    }

    // Initialize all elements in the adjacency matrix to 0
    for (int k = 0; k < size_upper_bound; k++)
    {
        for (int l = 0; l < size_upper_bound; l++)
        {
            (d_graph->adjacency_matrix)[k][l] = 0;
        }
    }
}

/*!
 * @brief Releases the memory held by an directed graph
 * @param d_graph Pointer to a directed graph
 * @return None
 */
void free_d_graph(directed_graph *d_graph)
{
    // Free the memory held by the list of directed graph vertices
    for (int i = 0; i < d_graph->adjacency_size; i++)
    {
        free(d_graph->vertices[i]);
        d_graph->vertices[i] = NULL;
    }

    // Free the memory held by the adjacency matrix
    for (int j = 0; j < d_graph->adjacency_size; j++)
    {
        for (int k = 0; k < d_graph->adjacency_size; k++)
        {
            free(&((d_graph->adjacency_matrix)[j][k]));
        }
    }
}