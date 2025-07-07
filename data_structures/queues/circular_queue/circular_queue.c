/**
 ********************************************************************************
 * @file    circular_queue.h
 * @author  Kai Gehry
 * @date    2025-06-02
 *
 * @brief   Defines the operations on a circular queue
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/
#include "circular_queue.h"

/************************************
 * FUNCTION DEFINITIONS
 ************************************/

/*!
 * @brief Adds an element to the end of the circular queue
 * @param circ_queue Pointer to a circular queue
 * @param element Element to add to the circular queue
 * @return None
 */
void enqueue(circular_queue *circ_queue, void *element)
{

    if (circ_queue->num_elements < circ_queue->size)
    {
        // Add the element to the end of the queue
        (circ_queue->array)[circ_queue->end_index] = element;

        // Calculate the new index where a new element can be placed
        circ_queue->end_index = (circ_queue->end_index + 1) % (circ_queue->size);

        // Increment the number of elements
        circ_queue->num_elements = circ_queue->num_elements + 1;
    }

    /*This can be removed if desired, but simply provides an indication that the capacity was reached and
      the element was not added.
    */
    else
    {
        printf("\nCapacity reached. Queue contents unchanged.\n");
    }
}

/*!
 * @brief Removes an item from the circular queue and returns its value.
 * @param circ_queue Pointer to a circular queue.
 * @return Removes and returns the item at the head of the circular queue
 */
void *dequeue(circular_queue *circ_queue)
{
    // If there are elements in the circular queue
    if (circ_queue->num_elements > 0)
    {
        // void pointer to store the value of the dequeued element
        void *removed_element = (circ_queue->array)[circ_queue->front_index];

        // Frees the memory held by the dequeued element
        free((circ_queue->array)[circ_queue->front_index]);
        //  Assigns the value at the position of the removed element to null
        (circ_queue->array)[circ_queue->front_index] = NULL;

        // Updates the front index
        circ_queue->front_index = (circ_queue->front_index + 1) % circ_queue->size;

        // Decrements the number of elements
        circ_queue->num_elements = circ_queue->num_elements - 1;

        return removed_element;
    }
    // If the circular queue is empty
    else
    {
        printf("\nCircular queue contains no elements.\n");
        return NULL;
    }
}

/*!
 * @brief Returns the element at the front of the circular queue.
 * @param circ_queue Pointer to a circular queue.
 * @return A value representing the value stored by the node at the head of circular queue.
 */
void *first(circular_queue *circ_queue)
{
    return (circ_queue->array)[circ_queue->front_index];
}

/*!
 * @brief Returns the size (number of elements) in the circular queue.
 * @param circ_queue Pointer to a circular queue.
 * @return An integer value representing the number of elements in the circular queue.
 */
int size(circular_queue *circ_queue)
{
    return (circ_queue->num_elements);
}

/*!
 * @brief Returns if the circular queue is empty or not.
 * @param circ_queue Pointer to a circular queue.
 * @return A boolean value representing if the circular queue is empty (1) or not empty (0).
 */
bool is_empty(circular_queue *circ_queue)
{
    return (circ_queue->num_elements) == 0;
}

/*!
 * @brief Initializes the circular queue.
 * @param circ_queue Pointer to a circular queue
 * @param num_elements Number of allowable elements in the circular queue
 * @return None
 */
void initialize_circular_queue(circular_queue *circ_queue, int queue_size)
{
    // Defines the number of allowable elements in the queue
    circ_queue->size = queue_size;
    // Set the initial front and end indices to 0
    circ_queue->front_index = 0;
    circ_queue->end_index = 0;
    circ_queue->num_elements = 0;

    //  Create an array of the specified size to hold the queue elements
    circ_queue->array = (void *)malloc(queue_size * sizeof(void *));
}

/*!
 * @brief Frees the dynamically allocated memory held by the circular queue
 * @param list Pointer to a circular queue.
 * @return None
 */
void free_circular_queue(circular_queue *queue)
{
    // Frees the memory held by each element of the array holding the queue items
    for (int i = 0; i < queue->num_elements; i++)
    {
        free(&(queue->array[i]));
    }

    // Frees the struct
    free(queue->array);
}

/*!
 * @brief Prints the relevant contents of the circular queue to the terminal.
 *        Can be uncommented if the element type remains constant.
 * @param list Pointer to a circular queue.
 * @return None
 */
// void display_circular_queue(circular_queue *queue)
// {
//     // Counter variable used to track how many elements have been traversed
//     int j = 0;
//     // Variable which indicates which index to begin traversal at
//     int i = queue->front_index;

//     printf("\nQueue contents: [ ");

//     // Displays only the elements from the front to the end index
//     while (j < queue->num_elements)
//     {
//         if (i == queue->front_index)
//             printf("->%d ", (queue->array)[i]);
//         else if (j + 1 == queue->num_elements)
//             printf("%d-> ", (queue->array)[i]);
//         else
//             printf("%d ", (queue->array)[i]);

//         i = (i + 1) % (queue->size);
//         j++;
//     }

//     printf("]\n");
// }
