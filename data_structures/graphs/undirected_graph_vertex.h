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

} undirected_graph_vertex;