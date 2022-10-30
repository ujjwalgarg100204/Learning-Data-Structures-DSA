#ifndef CODES_LL_IMPLEMENTATION_H
#define CODES_LL_IMPLEMENTATION_H

#include <stdbool.h>
#include "../../linked_list/singly_node.h"

typedef struct Queue_List_S {
    Node_S *front;
    Node_S *rear;
} Queue_List_S;


/*
 * Creates a non-circular queue which is implemented using singly linked list
 * Queue_List_S -> Queue implemented using Linked List S -> Singly
 * Returns a pointer to the struct Queue_List_S
 */
Queue_List_S *newQueue_List_S();

/*
 * Frees the memory allocated for queue
 * Time Complexity: O(n)
 */
void freeQueue_List_S(Queue_List_S *queue);

/*
 * Returns false if queue contains elements, true if queue is empty
 * Time Complexity: O(1)
 */
bool isEmpty_Queue_List_S(Queue_List_S *queue);

/*
 * Enqueues element in the queue if queue has enough space to add one more element
 * otherwise no action is done on the queue
 * Time Complexity: O(1)
 */
void enqueue_Queue_List_S(Queue_List_S *queue, ll element);

/*
 * Dequeues element from the front of the queue if queue is not empty
 * If queue is empty, a GARBAGE VALUE is returned and no operation is done on queue
 * Time Complexity: O(1)
 */
ll dequeue_Queue_List_S(Queue_List_S *queue);

/*
 * Returns element at the rear of the queue
 * If queue is empty, a GARBAGE VALUE is returned
 * Time Complexity: O(1)
 */
ll getRear_Queue_List_S(Queue_List_S *queue);

/*
 * Returns element at the front of the queue
 * If queue is empty, a GARBAGE VALUE is returned
 * Time Complexity: O(1)
 */
ll getFront_Queue_List_S(Queue_List_S *queue);

/*
 * Empties the queue
 * Time Complexity: O(n)
 */
void clear_Queue_List_S(Queue_List_S *queue);

/*
 * Prints the contents of the queue on the console/terminal
 * it prints from front to rear of the queue
 * Time Complexity: O(n)
 */
void printQueue_List_S(Queue_List_S *queue);

#endif //CODES_LL_IMPLEMENTATION_H
