/**
 ********************************************************************************
 * @file    undirected_graph_vertex.h
 * @author  Kai Gehry
 * @date    2025-06-07
 *
 * @brief   Defines a vertex for an indirected graph.
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/
#include <stdio.h>

/*!
 * @brief Struct which represents an undirected graph vertex
 */
typedef struct
{
    // Value held by the node
    void *value;
    // Vertex identifier
    void *identifier;
    // Stores the index of the vertex in the adjacency matrix
    int adj_index;

} undirected_graph_vertex;