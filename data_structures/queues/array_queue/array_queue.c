/**
 ********************************************************************************
 * @file    array_queue.c
 * @author  Kai Gehry
 * @date    2025-06-07
 *
 * @brief   Defines the operations on an array based queue.
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/
#include "array_queue.h"

/************************************
 * FUNCTION DEFINITIONS
 ************************************/

/*!
 * @brief Adds an element to the end of the queue
 * @param queue Pointer to a queue
 * @param element Element to add to the queue
 * @return None
 */
void enqueue(array_queue *queue, void *element)
{

    // If there are available positions to add to and the end element's index is not equal to the end index
    if (queue->num_elements < queue->size && queue->end_index <= queue->size - 1)
    {

        /*Entered when there is no more space at the end of the queue to add an element
          but there is space at the beginning due to element removal.

          The elements are then shifted, but this is only done when truly needed to fit more
          elements. In the worst case, the enqueue operation is then O(n) rather than O(1).
        */
        if ((queue->front_index != 0) && (queue->end_index == queue->size - 1))
        {
            // Index variable to keep track current element in shift process
            int index_ref = queue->front_index;
            // Index for index reassignment
            int i;

            for (i = 0; i < queue->num_elements; i++)
            {
                (queue->array)[i] = (queue->array)[index_ref];
                index_ref = index_ref + 1;
            }

            // Reassignment of end index and front index
            queue->end_index = i;
            queue->front_index = 0;
        }

        // Add the element to the end of the queue
        (queue->array)[queue->end_index] = element;

        // Update the end index. If the end index is equal to the defined size - 1, it remains the same
        if (queue->end_index + 1 != queue->size)
        {
            queue->end_index = queue->end_index + 1;
        }

        // Increment the number of elements
        queue->num_elements = queue->num_elements + 1;
    }

    /*This can be removed if desired, but simply provides an indication that the capacity was reached and
      the element was not added.
    */
    else if (queue->num_elements == queue->size)
    {
        printf("\nCapacity reached. Queue contents unchanged.\n");
    }
}

/*!
 * @brief Removes an item from the queue and returns its value.
 * @param queue Pointer to a linked list queue.
 * @return Removes and returns the item at the head of the queue
 */
void *dequeue(array_queue *queue)
{

    // If there are elements in the queue
    if (queue->num_elements > 0)
    {
        // void pointer to store the value of the dequeued element
        void *removed_element = (queue->array)[queue->front_index];

        // Assigns the value at the position of the removed element to null
        (queue->array)[queue->front_index] = NULL;
        // Updates the front index
        queue->front_index = queue->front_index + 1;

        // Decrements the number of elements
        queue->num_elements = queue->num_elements - 1;

        return removed_element;
    }
    // If the queue is empty
    else
    {
        printf("\nQueue contains no elements.\n");
        return NULL;
    }
}

/*!
 * @brief Returns the element at the front of the queue.
 * @param queue Pointer to a queue.
 * @return A value representing the value stored by the node at the head of queue.
 */
void *first(array_queue *queue)
{
    return (queue->array)[queue->front_index];
}

/*!
 * @brief Returns the size (number of elements) in the queue.
 * @param queue Pointer to a queue.
 * @return An integer value representing the number of elements in the queue.
 */
int size(array_queue *queue)
{
    return (queue->num_elements);
}

/*!
 * @brief Returns if the queue is empty or not.
 * @param queue Pointer to a queue.
 * @return A boolean value representing if the queue is empty (1) or not empty (0).
 */
bool is_empty(array_queue *queue)
{
    return (queue->num_elements) == 0;
}

/*!
 * @brief Initializes the queue.
 * @param queue Pointer to a queue
 * @param num_elements Number of allowable elements in the queue
 * @return None
 */
void initialize_array_queue(array_queue *queue, int queue_size)
{
    // Defines the number of allowable elements in the array
    queue->size = queue_size;
    // Set the initial top and bottom indices to 0
    queue->front_index = 0;
    queue->end_index = 0;
    queue->num_elements = 0;

    //  Create an array of the specified size
    queue->array = (void *)malloc(queue_size * sizeof(void *));
}

/*!
 * @brief Prints the relevant contents of the array based queue to the terminal.
 *        Can be uncommented if the element type remains constant.
 * @param list Pointer to a queue.
 * @return None
 */
// void display_queue(array_queue *queue)
// {
//     // Counter variable used to track how many elements have been traversed
//     int j = 0;

//     printf("\n");

//     // Displays only the elements from the front to the end index
//     for (int i = queue->front_index; j < queue->num_elements; i++)
//     {
//         printf("\n%d", (queue->array)[i]);
//         j++;
//     }

//     printf("\n");
// }
