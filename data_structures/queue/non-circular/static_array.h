#ifndef CODES_STATIC_ARRAY_H
#define CODES_STATIC_ARRAY_H

#include <stdbool.h>

#define ll long long

/*
 * non-circular queue implemented using static array
 * Since this implementation is done using array, all operations on queue, take O(1) time complexity
 */
typedef struct Queue_StArr {
    ll *arr;
    int front;
    int rear;
    int capacity;
} Queue_StArr;

/*
 * Creates a non-circular queue of given capacity which is implemented using static array
 * Queue_StArr -> Queue implemented using Static Array
 * Returns a pointer to the struct Queue_StArr
 */
Queue_StArr *newQueue_StArr(int capacity);

/*
 * Frees the memory allocated for queue
 */
void freeQueue_St_Arr(Queue_StArr *queue);

/*
 * Returns false if queue contains elements, true if queue is empty
 */
bool isEmpty_Queue_StArr(Queue_StArr *queue);

/*
 * Returns true if queue can't hold anymore elements
 */
bool isFull_Queue_StArr(Queue_StArr *queue);

/*
 * Enqueues element in the queue if queue has enough space to add one more element
 * otherwise no action is done on the queue
 */
void enqueue_Queue_StArr(Queue_StArr *queue, ll element);

/*
 * Dequeues element from the front of the queue if queue is not empty
 * If queue is empty, a GARBAGE VALUE is returned and no operation is done on queue
 */
ll dequeue_Queue_StArr(Queue_StArr *queue);

/*
 * Returns element at the rear of the queue
 * If queue is empty, a GARBAGE VALUE is returned
 */
ll getRear_Queue_StArr(Queue_StArr *queue);

/*
 * Returns element at the front of the queue
 * If queue is empty, a GARBAGE VALUE is returned
 */
ll getFront_Queue_StArr(Queue_StArr *queue);

/*
 * Empties the queue
 */
void clear_Queue_StArr(Queue_StArr *queue);

/*
 * Prints the contents of the queue on the console/terminal
 * it prints from front to rear of the queue
 * Time Complexity: O(n)
 */
void printQueue_StArr(Queue_StArr *queue);

#endif //CODES_STATIC_ARRAY_H
