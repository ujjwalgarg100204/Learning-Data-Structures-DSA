#ifndef CODES_LL_IMPLEMENTATION_H
#define CODES_LL_IMPLEMENTATION_H

#include "../../linked_list/circular_singly/singly_circular_ll.h"

/*
 * Implementation of circular queue using circular singly linked list
 */
typedef struct Queue_List_SC {
    LinkedList_S *list;
} Queue_List_SC;

/*
 * Creates a circular queue which is implemented using singly circular linked list
 * Queue_List_SC -> Queue implemented using Linked List S -> Singly, C -> Circular
 * Returns a pointer to the struct Queue_List_SC
 */
Queue_List_SC *newQueue_List_SC();

/*
 * Frees the memory allocated for circular queue
 * Time Complexity: O(n)
 */
void freeQueue_List_SC(Queue_List_SC *queue);

/*
 * Returns false if queue contains elements, true if queue is empty
 * Time Complexity: O(1)
 */
bool isEmpty_Queue_List_SC(Queue_List_SC *queue);

/*
 * Enqueues element in the queue if queue has enough space to add one more element
 * otherwise no action is done on the queue
 * Time Complexity: O(1)
 */
void enqueue_Queue_List_SC(Queue_List_SC *queue, ll element);

/*
 * Dequeues element from the front of the queue if queue is not empty
 * If queue is empty, a GARBAGE VALUE is returned and no operation is done on queue
 * Time Complexity: O(1)
 */
ll dequeue_Queue_List_SC(Queue_List_SC *queue);


/*
 * Returns element at the rear of the queue
 * If queue is empty, a GARBAGE VALUE is returned
 * Time Complexity: O(n)
 * NOTE: This function can be made O(1) by maintaining a separate tail pointer of linked list
 */
ll getRear_Queue_List_SC(Queue_List_SC *queue);

/*
 * Returns element at the front of the queue
 * If queue is empty, a GARBAGE VALUE is returned
 * Time Complexity: O(1)
 */
ll getFront_Queue_List_SC(Queue_List_SC *queue);

/*
 * Empties the queue
 * Time Complexity: O(n)
 */
void clear_Queue_List_SC(Queue_List_SC *queue);

/*
 * Prints the contents of the queue on the console/terminal
 * it prints from front to rear of the queue
 * Time Complexity: O(n)
 */
void printQueue_List_SC(Queue_List_SC *queue);

#endif //CODES_LL_IMPLEMENTATION_H
