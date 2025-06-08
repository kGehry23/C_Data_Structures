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
#include "../linked_lists/singly_linked_list/singly_linked_list.h"

/*!
 * @brief Struct which represents an undirected graph vertex
 */
typedef struct
{
    // Value held by the node
    void *value;
    // Vertex identifier
    void *identifier;
    // Pointer to a linked list undirected graph vertex pointers
    singly_linked_list *edges;

} undirected_graph_vertex;