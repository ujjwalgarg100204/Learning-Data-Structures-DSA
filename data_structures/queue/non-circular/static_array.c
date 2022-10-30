#include <stdlib.h>
#include <stdio.h>
#include "static_array.h"

/*
 * Creates a non-circular queue of given capacity which is implemented using static array
 * Queue_StArr -> Queue implemented using Static Array
 * Returns a pointer to the struct Queue_StArr
 */
Queue_StArr *newQueue_StArr(int capacity) {
    Queue_StArr *queue = malloc(sizeof(Queue_StArr));
    queue->arr = malloc(sizeof(ll) * capacity);
    queue->front = -1;
    queue->rear = -1;
    queue->capacity = capacity;
    return queue;
}

/*
 * Frees the memory allocated for queue
 */
void freeQueue_St_Arr(Queue_StArr *queue) {
    free(queue->arr);
    free(queue);
}

/*
 * Returns false if queue contains elements, true if queue is empty
 */
bool isEmpty_Queue_StArr(Queue_StArr *queue) {
    return queue->front == -1 && queue->rear == -1;
}

/*
 * Returns true if queue can't hold anymore elements
 */
bool isFull_Queue_StArr(Queue_StArr *queue) {
    return queue->rear + 1 == queue->capacity;
}


/*
 * Returns element at the rear of the queue
 * If queue is empty, a GARBAGE VALUE is returned
 */
ll getRear_Queue_StArr(Queue_StArr *queue) {
    return isEmpty_Queue_StArr(queue) ? -1 : queue->arr[queue->rear];
}

/*
 * Returns element at the front of the queue
 * If queue is empty, a GARBAGE VALUE is returned
 */
ll getFront_Queue_StArr(Queue_StArr *queue) {
    return isEmpty_Queue_StArr(queue) ? -1 : queue->arr[queue->front];
}

/*
 * Empties the queue
 */
void clear_Queue_StArr(Queue_StArr *queue) {
    queue->rear = -1;
    queue->front = -1;
}

/*
 * Enqueues element in the queue if queue has enough space to add one more element
 * otherwise no action is done on the queue
 */
void enqueue_Queue_StArr(Queue_StArr *queue, long long int element) {
    if (isFull_Queue_StArr(queue)) return;
    // if first enqueue operation
    if (queue->rear == -1) queue->front = 0;

    queue->arr[++queue->rear] = element;
}

/*
 * Dequeues element from the front of the queue if queue is not empty
 * If queue is empty, a GARBAGE VALUE is returned and no operation is done on queue
 */
ll dequeue_Queue_StArr(Queue_StArr *queue) {
    if (isEmpty_Queue_StArr(queue)) return -1;
    ll toReturn = queue->arr[queue->front++];

    // if last dequeue operation then empty the queue
    if (queue->front == queue->capacity)
        clear_Queue_StArr(queue);
    return toReturn;
}

/*
 * Prints the contents of the queue on the console/terminal
 * it prints from front to rear of the queue
 * Time Complexity: O(n)
 */
void printQueue_StArr(Queue_StArr *queue) {
    if (isEmpty_Queue_StArr(queue)) {
        printf("empty queue");
        return;
    }

    for (int i = queue->front; i <= queue->rear; ++i)
        printf("%lld ", queue->arr[i]);
}





