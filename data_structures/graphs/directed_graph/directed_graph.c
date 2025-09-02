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
 * @param di_graph Pointer to an directed graph
 * @param name String identifier for the vertex
 * @param identifier Value to identify the vertex by
 * @param vertex_value Value stored by the vertex
 * @return None
 */
void add_vertex(directed_graph *di_graph, char *name, int identifier, void *vertex_value)
{
    // Adds the vertex if a vertex has not already been allocated to the specified position in the vertex list
    if (di_graph->vertices[identifier] == NULL)
    {
        // Allocate memory for a new directed graph vertex
        directed_graph_vertex *new_vertex = (directed_graph_vertex *)malloc(sizeof(directed_graph_vertex));

        // Initializes all variables associated with a vertex
        new_vertex->vertex_name = name;
        new_vertex->identifier = identifier;
        new_vertex->value = vertex_value;
        new_vertex->adj_index = identifier;
        new_vertex->visited = false;

        // Add vertex to the graph
        di_graph->vertices[identifier] = new_vertex;

        // Increment the number of vertices in the graph
        di_graph->num_vertices = di_graph->num_vertices + 1;
    }
}

/*!
 * @brief Removes and returns the value associated with the specified vertex
 *        in the undirected graph
 * @param di_graph Pointer to an directed graph
 * @param identifier Value to identify the vertex by
 * @return The value associated with the specified vertex if it exists
 */
void *remove_vertex(directed_graph *di_graph, int identifier)
{
    // Removes the vertex if it is in the graph
    if ((di_graph->vertices[identifier]->vertex_name) != NULL)
    {
        // Pointer to the vertex to be removed
        void *removed_vertex_value = (di_graph->vertices[identifier])->value;

        // Free memory held by removed vertex
        free(di_graph->vertices[identifier]);
        // Set the pointer to the vertex to NULL to avoid dangling pointer
        di_graph->vertices[identifier] = NULL;

        // Sets all the edges that may exist attached to the node to remove to FALSE in the adjacency matrix
        for (int i = 0; i < di_graph->adjacency_size; i++)
        {
            if (edge_exists(di_graph, i, identifier) == true)
            {
                (di_graph->adjacency_matrix)[i][identifier] = false;
                di_graph->num_edges--;
            }
            if (edge_exists(di_graph, identifier, i) == true)
            {
                (di_graph->adjacency_matrix)[identifier][i] = false;
                di_graph->num_edges--;
            }
        }

        // Decrement the counter for the number of vertices
        di_graph->num_vertices = di_graph->num_vertices - 1;

        return removed_vertex_value;
    }
    // If the vertex does not exist in the graph
    else
    {
        return NULL;
    }
}

/*!
 * @brief Returns the value stored by the specified vertex.
 * @param di_graph Pointer to a directed graph
 * @param identifier Value to identify the vertex by
 * @return The value stored by the specified vertex
 */
void *return_vertex_value(directed_graph *di_graph, int identifier)
{
    if (di_graph->vertices[identifier] = NULL)
    {
        return NULL;
    }

    return (di_graph->vertices[identifier])->value;
}

/*!
 * @brief Checks if there is an edge between two vertices
 * @param di_graph Pointer to an directed graph
 * @param from_id Identifier of vertex the edge comes from
 * @param to_id Identifier of the vertex the edge goes to
 * @return A boolean value indicating if an edge exists between the specified vertices
 */
bool edge_exists(directed_graph *di_graph, int from_id, int to_id)
{
    // Checks if the specified vertices have an edge between them
    return ((di_graph->adjacency_matrix)[from_id][to_id] == true);
}

/*!
 * @brief Adds an edge between two vertices in the directed graph
 * @param di_graph Pointer to a directed graph
 * @param from_vertex_id Identifier of the first from which the edge is directed from.
 * @param to_vertex_id Identifier of the vertex to which the edge goes.
 * @return None
 */
void add_edge(directed_graph *di_graph, int from_vertex_id, int to_vertex_id)
{
    // Only adds the edge if an edge does not already exist
    if (edge_exists(di_graph, from_vertex_id, to_vertex_id) == false)
    {
        // Updates the relevant indices in the adjacency matrix to true
        (di_graph->adjacency_matrix)[from_vertex_id][to_vertex_id] = true;

        // Increment the counter for the number of edges
        di_graph->num_edges = di_graph->num_edges + 1;
    }
}

/*!
 * @brief Removes an edge between two vertices in the directed graph
 * @param di_graph Pointer to a directed graph
 * @param from_vertex_id Identifier of the first from which the edge is directed from.
 * @param to_vertex_id Identifier of the vertex to which the edge goes.
 * @return None
 */
void remove_edge(directed_graph *di_graph, int from_vertex_id, int to_vertex_id)
{
    // Removes the edge if it exists
    if (edge_exists(di_graph, from_vertex_id, to_vertex_id) == true)
    {
        // Updates the relevant indices in the adjacency matrix to false
        (di_graph->adjacency_matrix)[from_vertex_id][to_vertex_id] = false;

        // Decrement the counter for the number of edges
        di_graph->num_edges = di_graph->num_edges - 1;
    }
}

/*!
 * @brief Returns the number of vertices in the graph
 * @param di_graph Pointer to a directed graph
 * @return An integer representing the number of vertices in the graph
 */
int graph_size(directed_graph *di_graph)
{
    return di_graph->num_vertices;
}

/*!
 * @brief Initializes a directed graph
 * @param di_graph Pointer to a directed graph
 * @param size_upper_bound Row and column dimension of the adjacency matrix
 * @return None
 */
void initialize_directed_graph(directed_graph *di_graph, int size_upper_bound)
{
    // Sets the number of vertices and the number of edges to 0
    di_graph->num_vertices = 0;
    di_graph->num_edges = 0;

    // Assign the number of rows and columns to the specified upper bound
    di_graph->adjacency_size = size_upper_bound;

    di_graph->vertices = (directed_graph_vertex **)malloc(size_upper_bound * sizeof(directed_graph_vertex *));

    for (int i = 0; i < size_upper_bound; i++)
    {
        (di_graph->vertices)[i] = NULL;
    }

    // Resize the main array to the required size
    di_graph->adjacency_matrix = (bool **)malloc(size_upper_bound * sizeof(bool *));

    // Populate the main array with internal arrays
    for (int j = 0; j < size_upper_bound; j++)
    {
        (di_graph->adjacency_matrix)[j] = (bool *)malloc(size_upper_bound * sizeof(bool));
    }

    // Initialize all elements in the adjacency matrix to 0
    for (int k = 0; k < size_upper_bound; k++)
    {
        for (int l = 0; l < size_upper_bound; l++)
        {
            (di_graph->adjacency_matrix)[k][l] = false;
        }
    }
}

/*!
 * @brief Releases the memory held by an directed graph
 * @param di_graph Pointer to a directed graph
 * @return None
 */
void free_di_graph(directed_graph *di_graph)
{
    // Free the memory held by the list of directed graph vertices
    for (int i = 0; i < di_graph->adjacency_size; i++)
    {
        free(di_graph->vertices[i]);
        di_graph->vertices[i] = NULL;
    }

    // Free the memory held by the adjacency matrix
    for (int j = 0; j < di_graph->adjacency_size; j++)
    {
        for (int k = 0; k < di_graph->adjacency_size; k++)
        {
            free(&((di_graph->adjacency_matrix)[j][k]));
        }
    }
}

/*!
 * @brief Preforms a depth first traversal of the graph.
 *
 *        Adapted from Java Foundations, 5th Ed.
 *
 * @param di_graph Pointer to a directed graph
 * @param start_id Id of the vertex to start at
 * @param print_flag A boolean indicating whether or not to print the result to the terminal
 * @return An integer representing the number of vertices in the depth first traversal
 */
int di_graph_depth_first(directed_graph *di_graph, int start_id, bool print_flag)
{
    array_stack traversal_stack;
    // Initialize the traversal queue
    initialize_array_stack(&traversal_stack, di_graph->num_vertices);

    // Initialize the result list
    int result_list[di_graph->num_vertices];

    // Counter used to track the size of the result list
    int result_list_size = 0;
    // Current vertex id
    int current_id = start_id;
    // Boolean which indicates if all adjacent vertices to a vertex have been visited
    bool adjacent_not_visited = 0;

    // Reset the visited booleans for all vertices to false
    for (int i = 0; i < di_graph->num_vertices; i++)
    {
        (di_graph->vertices)[i]->visited = 0;
    }

    // Element corresponding to start id is added to the stack
    push(&traversal_stack, (di_graph->vertices[current_id])->identifier);
    // Result list is updated with first element in traversal
    result_list[result_list_size] = (di_graph->vertices[current_id])->identifier;
    result_list_size++;
    // Vertex marked as visited
    (di_graph->vertices[current_id])->visited = 1;

    // While there are elements in the traversal stack, continue the traversal
    while (traversal_stack.num_elements != 0)
    {
        // Check the vertices attached to the current vertex and mark as not visited if they have not been reached
        for (int j = 0; j < di_graph->num_vertices && adjacent_not_visited == 0; j++)
        {
            // If adjacent add vertex to stack and to result list
            if ((di_graph->adjacency_matrix)[current_id][j] == 1 && (di_graph->vertices[j])->visited == 0)
            {
                // Push adjacent vertex onto traversal stack
                push(&traversal_stack, (di_graph->vertices[j])->identifier);
                // Update result list
                result_list[result_list_size] = (di_graph->vertices[j])->identifier;
                result_list_size++;
                // Mark the vertex as visited
                (di_graph->vertices[j])->visited = 1;

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
                printf(" %s ", ((di_graph->vertices)[result_list[k]])->vertex_name);
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
 * @brief Performs a breadth first traversal of the graph
 * @param di_graph Pointer to a directed graph
 * @param start_id Id of the vertex to start at
 * @param print_flag A boolean indicating whether or not to print the result to the terminal
 * @return An integer representing the number of vertices in the breadth first traversal
 */
int di_graph_breadth_first(directed_graph *di_graph, int start_id, bool print_flag)
{
    array_queue traversal_queue;
    // Initialize the traversal queue
    initialize_array_queue(&traversal_queue, di_graph->num_vertices);

    // Initialize the result list
    int result_list[di_graph->num_vertices];

    // Counter used to track the size of the result list
    int result_list_size = 0;
    // Current vertex id
    int current_id = start_id;

    // Reset the visited booleans for all vertices to false
    for (int i = 0; i < di_graph->num_vertices; i++)
    {
        (di_graph->vertices)[i]->visited = 0;
    }

    // While there are elements in the traversal queue, continue the traversal
    do
    {
        // Check for vertices attached to the current vertex
        for (int j = 0; j < di_graph->num_vertices; j++)
        {

            // If a vertex is attached to the current vertex and the vertex has not been visited, those vertices
            // are enqueued onto the traversal queue
            if ((di_graph->adjacency_matrix)[current_id][j] == 1 && (di_graph->vertices[j])->visited == 0)
            {
                enqueue(&traversal_queue, (di_graph->vertices[j])->identifier);
                // Any enqueued vertices are marked as visited
                (di_graph->vertices[j])->visited = 1;
            }
        }

        // If the result list is empty, add the starting identifier to the result list
        if (result_list_size == 0)
        {
            result_list[result_list_size] = (di_graph->vertices[current_id])->identifier;
            // Set the visited boolean to 1
            (di_graph->vertices[current_id])->visited = 1;
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
                printf(" %s ", ((di_graph->vertices)[result_list[k]])->vertex_name);
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
 * @brief Checks if the graph is connected
 * @param di_graph Pointer to a directed graph
 * @return A boolean representing if the graph is connected or not
 */
bool di_is_connected(directed_graph *di_graph)
{
    // Counter variable used to hold the number of elements in a given breadth first traversal
    int current_count = 0;
    // Counter used to track how many of the traversals have the same number of
    // elements as vertices in the graph
    int connected_counter = 0;

    for (int i = 0; i < di_graph->num_vertices; i++)
    {
        current_count = di_graph_breadth_first(di_graph, i, 0);

        if (current_count == di_graph->num_vertices)
        {
            connected_counter = connected_counter + 1;
        }
    }

    return connected_counter == di_graph->num_vertices;
}

/*!
 * @brief Checks if the graph contains a cycle
 * @param di_graph Pointer to a directed graph
 * @return A boolean representing if the graph contains a cycle or not
 */
bool di_contains_cycle(directed_graph *di_graph)
{
    array_stack traversal_stack;
    // Initialize the traversal queue
    initialize_array_stack(&traversal_stack, di_graph->num_vertices);

    // Initialize the result list
    int result_list[di_graph->num_vertices];

    // Counter used to track the size of the result list
    int result_list_size = 0;
    // Current vertex id
    int current_id = 0;
    // Boolean which indicates if all adjacent vertices to a vertex have been visited
    bool adjacent_not_visited = false;

    // Reset the visited booleans for all vertices to false
    for (int i = 0; i < di_graph->num_vertices; i++)
    {
        if ((di_graph->vertices)[i] == NULL)
        {
            continue;
        }
        (di_graph->vertices)[i]->visited = false;
    }

    // Element corresponding to start id is added to the stack
    push(&traversal_stack, (di_graph->vertices[current_id])->identifier);
    // Result list is updated with first element in traversal
    result_list[result_list_size] = (di_graph->vertices[current_id])->identifier;
    result_list_size++;
    // Vertex marked as visited
    (di_graph->vertices[current_id])->visited = true;

    // While there are elements in the traversal stack, continue the traversal
    while (stack_is_empty(&traversal_stack) == false)
    {
        // Check the vertices attached to the current vertex and mark as not visited if they have not been reached
        for (int j = 0; j < di_graph->num_vertices && adjacent_not_visited == false; j++)
        {

            printf("\nState for vertex %d: %d", j, (di_graph->vertices[j])->visited);

            // If adjacent has not been visited add vertex to stack and to result list
            if (((di_graph->adjacency_matrix)[current_id][j] == true || (di_graph->adjacency_matrix)[j][current_id] == true) && (di_graph->vertices[j])->visited == false)
            {
                // Push adjacent vertex onto traversal stack
                push(&traversal_stack, (di_graph->vertices[j])->identifier);
                // Update result list
                result_list[result_list_size] = (di_graph->vertices[j])->identifier;
                result_list_size++;
                // Mark the vertex as visited
                (di_graph->vertices[j])->visited = true;

                // Indicate that all adjacent vertices to the vertex have not been reached
                // as of this iteration
                adjacent_not_visited = true;
            }
        }

        // If there are elements in the result list and all adjacent vertices have been visited
        if (result_list_size > 0 && adjacent_not_visited == false)
        {
            // Pops an element off of the traversal stack
            pop(&traversal_stack);
        }

        // Update the current vertex id. Peek at the appropriate element's index to continue the traversal
        current_id = peek(&traversal_stack);

        if (adjacent_not_visited == false)
        {
            // If an adjacent node to the current node has already been visited, a cycle exists
            break;
        }

        // Reset the adjacent node visited boolean for the next vertex
        adjacent_not_visited = false;
    }

    // printf("\nNum elems in traversal stack: %d", traversal_stack.num_elements)

    // Free the dynamically allocated memory for the stack
    free_array_stack(&traversal_stack);

    // If a cycle exists
    if (traversal_stack.num_elements != 0 && adjacent_not_visited == false)
    {
        return true;
    }
    // If a cycle does not exist
    else
    {
        return false;
    }
}