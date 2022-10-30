#ifndef CODES_STATIC_ARRAY_H
#define CODES_STATIC_ARRAY_H

#include <stdbool.h>

#define ll long long

/*
 * Since this circular queue is implemented using array, all operations are done in O(1) time complexity
 */
typedef struct Queue_Cir_StArr {
    ll *arr;
    int capacity;
    int front;
    int rear;
} Queue_Cir_StArr;

/*
 * Creates a circular queue of given capacity which is implemented using static array
 * Queue_Cir_StArr -> Circular Queue implemented using Static Array
 * Returns a pointer to the struct Queue_Cir_StArr
 */
Queue_Cir_StArr *newCircularQueue_StArr(int capacity);

/*
 * Frees the memory allocated for circular queue
 */
void freeCircularQueue_StArr(Queue_Cir_StArr *queue);

/*
 * Returns false if queue contains elements, true if queue is empty
 */
bool isEmpty_Queue_Cir_StArr(Queue_Cir_StArr *queue);

/*
 * Returns true if queue can't hold anymore elements
 */
bool isFull_Queue_Cir_StArr(Queue_Cir_StArr *queue);

/*
 * Enqueues element in the queue if queue has enough space to add one more element
 * otherwise no action is done on the queue
 */
void enqueue_Queue_Cir_StArr(Queue_Cir_StArr *queue, ll element);

/*
 * Dequeues element from the front of the queue if queue is not empty
 * If queue is empty, a GARBAGE VALUE is returned and no operation is done on queue
 */
ll dequeue_Queue_Cir_StArr(Queue_Cir_StArr *queue);

/*
 * Returns element at the rear of the queue
 * If queue is empty, a GARBAGE VALUE is returned
 */
ll getRear_Queue_Cir_StArr(Queue_Cir_StArr *queue);

/*
 * Returns element at the front of the queue
 * If queue is empty, a GARBAGE VALUE is returned
 */
ll getFront_Queue_Cir_StArr(Queue_Cir_StArr *queue);

/*
 * Empties the queue
 */
void clear_Queue_Cir_StArr(Queue_Cir_StArr *queue);

/*
 * Prints the contents of the queue on the console/terminal
 * it prints from front to rear of the queue
 * Time Complexity: O(n)
 */
void printQueue_Cir_StArr(Queue_Cir_StArr *queue);

#endif //CODES_STATIC_ARRAY_H
