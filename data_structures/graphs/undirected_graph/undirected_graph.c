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
void add_vertex(undirected_graph *ud_graph, char *name, int identifier, void *vertex_value)
{
    // Adds the vertex if a vertex has not already been allocated to the specified position in the vertex list
    if (ud_graph->vertices[identifier] == NULL)
    {
        // Allocate memory for a new undirected graph vertex
        undirected_graph_vertex *new_vertex = (undirected_graph_vertex *)malloc(sizeof(undirected_graph_vertex));

        // Initializes all variables associated with a vertex
        new_vertex->vertex_name = name;
        new_vertex->identifier = identifier;
        new_vertex->value = vertex_value;
        new_vertex->adj_index = identifier;
        new_vertex->visited = 0;

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
    return ((ud_graph->adjacency_matrix)[vertex_id_1][vertex_id_2] == 1);
}

/*!
 * @brief Returns the number of vertices in the graph
 * @param ud_graph Pointer to an undirected graph
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

/*!
 * @brief Prints the result of the depth first traversal to the terminal
 *
 *        Adapted from Java Foundations, 5th Ed.
 *
 * @param d_graph Pointer to an undirected graph
 * @param start Pointer to the node to begin the traversal at
 * @param print_flag A boolean indicating whether or not to print the result to the terminal
 * @return An integer representing the number of vertices in the depth first traversal
 */
int ud_graph_depth_first(undirected_graph *ud_graph, int start_id, bool print_flag)
{
    array_stack traversal_stack;
    // Initialize the traversal queue
    initialize_array_stack(&traversal_stack, ud_graph->num_vertices);

    // Initialize the result list
    int result_list[ud_graph->num_vertices];

    // Counter used to track the size of the result list
    int result_list_size = 0;
    // Current vertex id
    int current_id = start_id;
    // Boolean which indicates if all adjacent vertices to a vertex have been visited
    bool adjacent_not_visited = 0;

    // Reset the visited booleans for all vertices to false
    for (int i = 0; i < ud_graph->num_vertices; i++)
    {
        (ud_graph->vertices)[i]->visited = 0;
    }

    // Element corresponding to start id is added to the stack
    push(&traversal_stack, (ud_graph->vertices[current_id])->identifier);
    // Result list is updated with first element in traversal
    result_list[result_list_size] = (ud_graph->vertices[current_id])->identifier;
    result_list_size++;
    // Vertex marked as visited
    (ud_graph->vertices[current_id])->visited = 1;

    // While there are elements in the traversal stack, continue the traversal
    while (traversal_stack.num_elements != 0)
    {
        // Check the vertices attached to the current vertex and mark as not visited if they have not been reached
        for (int j = 0; j < ud_graph->num_vertices && adjacent_not_visited == 0; j++)
        {
            // If adjacent add vertex to stack and to result list
            if ((ud_graph->adjacency_matrix)[current_id][j] == 1 && (ud_graph->vertices[j])->visited == 0)
            {
                // Push adjacent vertex onto traversal stack
                push(&traversal_stack, (ud_graph->vertices[j])->identifier);
                // Update result list
                result_list[result_list_size] = (ud_graph->vertices[j])->identifier;
                result_list_size++;
                // Mark the vertex as visited
                (ud_graph->vertices[j])->visited = 1;

                // Indicate that all adjacent vertices to the vertex have not been reached
                // as of this iteration
                adjacent_not_visited = 1;
            }
        }

        // If there are elements in the result list and all adjacent vertices have been visited
        if (result_list_size > 0 && adjacent_not_visited == 0)
        {
            // Pops an element off of the traversal stack
            pop(&traversal_stack);
        }

        // Update the current vertex id. Peek at the appropriate element's index to continue the traversal
        current_id = peek(&traversal_stack);

        // Reset the adjacent node visited boolean for the next vertex
        adjacent_not_visited = 0;
    }

    // Prints the result of the breadth first search to the terminal
    for (int k = 0; k < result_list_size; k++)
    {
        if (print_flag == 1)
        {
            if (k == 0)
            {
                printf("\n\n[");
            }

            if (k >= 0 && k < result_list_size)
            {
                printf(" %s ", ((ud_graph->vertices)[result_list[k]])->vertex_name);
            }

            if (k == result_list_size - 1)
            {
                printf("]");
            }
        }
    }

    // Free the dynamically allocated memory allocated for the traversal queue
    free_array_stack(&traversal_stack);

    return result_list_size;
}

/*!
 * @brief Prints the result of the breadth first traversal to the terminal
 * @param ud_graph Pointer to an undirected graph
 * @param start_id Id of the vertex to start at
 * @param print_flag A boolean indicating whether or not to print the result to the terminal
 * @return An integer representing the number of vertices in the breadth first traversal
 */
int ud_graph_breadth_first(undirected_graph *ud_graph, int start_id, bool print_flag)
{
    array_queue traversal_queue;
    // Initialize the traversal queue
    initialize_array_queue(&traversal_queue, ud_graph->num_vertices);

    // Initialize the result list
    int result_list[ud_graph->num_vertices];

    // Counter used to track the size of the result list
    int result_list_size = 0;
    // Current vertex id
    int current_id = start_id;

    // Reset the visited booleans for all vertices to false
    for (int i = 0; i < ud_graph->num_vertices; i++)
    {
        (ud_graph->vertices)[i]->visited = 0;
    }

    // While there are elements in the traversal queue, continue the traversal
    do
    {
        // Check for vertices attached to the current vertex
        for (int j = 0; j < ud_graph->num_vertices; j++)
        {

            // If a vertex is attached to the current vertex and the vertex has not been visited, those vertices
            // are enqueued onto the traversal queue
            if ((ud_graph->adjacency_matrix)[current_id][j] == 1 && (ud_graph->vertices[j])->visited == 0)
            {
                enqueue(&traversal_queue, (ud_graph->vertices[j])->identifier);
                // Any enqueued vertices are marked as visited
                (ud_graph->vertices[j])->visited = 1;
            }
        }

        // If the result list is empty, add the starting identifier to the result list
        if (result_list_size == 0)
        {
            result_list[result_list_size] = (ud_graph->vertices[current_id])->identifier;
            // Set the visited boolean to 1
            (ud_graph->vertices[current_id])->visited = 1;
        }
        if (result_list_size > 0)
        {
            // Dequeues an element off of the traversal queue and adds it to the result list
            result_list[result_list_size] = dequeue(&traversal_queue);
        }

        // Increment the size of the result list
        result_list_size++;
        // Update the current vertex id
        current_id = first(&traversal_queue);

    } while (traversal_queue.num_elements != 0);

    // Prints the result of the breadth first search to the terminal
    for (int k = 0; k < result_list_size; k++)
    {
        if (print_flag == 1)
        {
            if (k == 0)
            {
                printf("\n\n[");
            }

            if (k >= 0 && k < result_list_size)
            {
                printf(" %s ", ((ud_graph->vertices)[result_list[k]])->vertex_name);
            }

            if (k == result_list_size - 1)
            {
                printf("]");
            }
        }
    }

    // Free the dynamically allocated memory allocated for the traversal queue
    free_array_queue(&traversal_queue);

    return result_list_size;
}

/*!
 * @brief Determines if the graph is connected
 * @param ud_graph Pointer to an undirected graph
 * @return A boolean representing if the graph is connected or not
 */
bool ud_is_connected(undirected_graph *ud_graph)
{
    // Counter variable used to hold the number of elements in a given breadth first traversal
    int current_count = 0;
    // Counter used to track how many of the traversals have the same number of
    // elements as vertices in the graph
    int connected_counter = 0;

    for (int i = 0; i < ud_graph->num_vertices; i++)
    {
        current_count = ud_graph_breadth_first(ud_graph, i, 0);

        if (current_count == ud_graph->num_vertices)
        {
            connected_counter = connected_counter + 1;
        }
    }

    return connected_counter == ud_graph->num_vertices;
}

/*!
 * @brief Checks if the graph contains a cycle by running depth first traversal on the graph
 * @param ud_graph Pointer to an undirected graph
 * @return A boolean representing if the graph contains a cycle or not
 */
bool ud_contains_cycle(undirected_graph *ud_graph)
{
    array_stack traversal_stack;
    // Initialize the traversal queue
    initialize_array_stack(&traversal_stack, ud_graph->num_vertices);

    // Initialize the result list
    int result_list[ud_graph->num_vertices];

    // Counter used to track the size of the result list
    int result_list_size = 0;
    // Current vertex id
    int current_id = 0;
    // Boolean which indicates if all adjacent vertices to a vertex have been visited
    bool adjacent_not_visited = 0;

    // Reset the visited booleans for all vertices to false
    for (int i = 0; i < ud_graph->num_vertices; i++)
    {
        (ud_graph->vertices)[i]->visited = 0;
    }

    // Element corresponding to start id is added to the stack
    push(&traversal_stack, (ud_graph->vertices[current_id])->identifier);
    // Result list is updated with first element in traversal
    result_list[result_list_size] = (ud_graph->vertices[current_id])->identifier;
    result_list_size++;
    // Vertex marked as visited
    (ud_graph->vertices[current_id])->visited = 1;

    // While there are elements in the traversal stack, continue the traversal
    while (traversal_stack.num_elements != 0)
    {
        // Check the vertices attached to the current vertex and mark as not visited if they have not been reached
        for (int j = 0; j < ud_graph->num_vertices && adjacent_not_visited == 0; j++)
        {
            // If adjacent add vertex to stack and to result list
            if ((ud_graph->adjacency_matrix)[current_id][j] == 1 && (ud_graph->vertices[j])->visited == 0)
            {
                // Push adjacent vertex onto traversal stack
                push(&traversal_stack, (ud_graph->vertices[j])->identifier);
                // Update result list
                result_list[result_list_size] = (ud_graph->vertices[j])->identifier;
                result_list_size++;
                // Mark the vertex as visited
                (ud_graph->vertices[j])->visited = 1;

                // Indicate that all adjacent vertices to the vertex have not been reached
                // as of this iteration
                adjacent_not_visited = 1;
            }
        }

        // If there are elements in the result list and all adjacent vertices have been visited
        if (result_list_size > 0 && adjacent_not_visited == 0)
        {
            // Pops an element off of the traversal stack
            pop(&traversal_stack);
        }

        // Update the current vertex id. Peek at the appropriate element's index to continue the traversal
        current_id = peek(&traversal_stack);

        if (adjacent_not_visited == 0)
        {
            // If an adjacent node to the current node has already been visited, a cycle exists
            break;
        }

        // Reset the adjacent node visited boolean for the next vertex
        adjacent_not_visited = 0;
    }

    // Free the dynamically allocated memory for the stack
    free_array_stack(&traversal_stack);

    // If a cycle exists
    if (traversal_stack.num_elements != 0 && adjacent_not_visited == 0)
    {
        return 1;
    }
    // If a cycle does not exist
    else
    {
        return 0;
    }
}