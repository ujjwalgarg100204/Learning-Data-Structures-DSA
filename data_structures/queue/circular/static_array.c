#include <stdlib.h>
#include <stdio.h>
#include "static_array.h"

/*
 * Creates a circular queue of given capacity which is implemented using static array
 * Queue_Cir_StArr -> Circular Queue implemented using Static Array
 * Returns a pointer to the struct Queue_Cir_StArr
 */
Queue_Cir_StArr *newCircularQueue_StArr(int capacity) {
    Queue_Cir_StArr *queue = malloc(sizeof(Queue_Cir_StArr));
    queue->arr = malloc(sizeof(ll) * capacity);
    queue->capacity = capacity;
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

/*
 * Frees the memory allocated for circular queue
 */
void freeCircularQueue_StArr(Queue_Cir_StArr *queue) {
    free(queue->arr);
    free(queue);
}

/*
 * Returns false if queue contains elements, true if queue is empty
 */
bool isEmpty_Queue_Cir_StArr(Queue_Cir_StArr *queue) {
    return queue->rear == -1 && queue->front == -1;
}

/*
 * Returns true if queue can't hold anymore elements
 */
bool isFull_Queue_Cir_StArr(Queue_Cir_StArr *queue) {
    return (queue->rear + 1) % queue->capacity == queue->front;
}

/*
 * Enqueues element in the queue if queue has enough space to add one more element
 * otherwise no action is done on the queue
 */
void enqueue_Queue_Cir_StArr(Queue_Cir_StArr *queue, long long int element) {
    if (isFull_Queue_Cir_StArr(queue)) return;

    // if first enqueue operation
    if (queue->front == -1) queue->front = 0;

    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->arr[queue->rear] = element;
}

/*
 * Dequeues element from the front of the queue if queue is not empty
 * If queue is empty, a GARBAGE VALUE is returned and no operation is done on queue
 */
ll dequeue_Queue_Cir_StArr(Queue_Cir_StArr *queue) {
    if (isEmpty_Queue_Cir_StArr(queue)) return -1;

    ll toReturn = queue->arr[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;

    // if queue is completely empty, then set rear and frong to -1
    if (queue->front == (queue->rear + 1) % queue->capacity) {
        queue->front = -1;
        queue->rear = -1;
    }

    return toReturn;
}

/*
 * Returns element at the rear of the queue
 * If queue is empty, a GARBAGE VALUE is returned
 */
ll getRear_Queue_Cir_StArr(Queue_Cir_StArr *queue) {
    return queue->arr[queue->rear];
}

/*
 * Returns element at the front of the queue
 * If queue is empty, a GARBAGE VALUE is returned
 */
ll getFront_Queue_Cir_StArr(Queue_Cir_StArr *queue) {
    return queue->arr[queue->rear];
}

/*
 * Prints the contents of the queue on the console/terminal
 * it prints from front to rear of the queue
 */
void printQueue_Cir_StArr(Queue_Cir_StArr *queue) {
    if (isEmpty_Queue_Cir_StArr(queue)) {
        printf("empty queue");
        return;
    }

    // print from the front to rear
    int i = queue->front;
    do {
        printf("%lld ", queue->arr[i]);
        i = (i + 1) % queue->capacity;
    } while (i != queue->front);
}

/*
 * Empties the queue
 */
void clear_Queue_Cir_StArr(Queue_Cir_StArr *queue) {
    queue->front = -1;
    queue->rear = -1;
}
