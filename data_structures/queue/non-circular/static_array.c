#include <stdlib.h>
#include <stdio.h>
#include "static_array.h"

Queue_StArr *newQueue_StArr(int capacity) {
    Queue_StArr *queue = malloc(sizeof(Queue_StArr));
    queue->arr = malloc(sizeof(ll) * capacity);
    queue->front = -1;
    queue->rear = -1;
    queue->capacity = capacity;
    return queue;
}

void freeQueue_St_Arr(Queue_StArr *queue) {
    free(queue->arr);
    free(queue);
}

bool isEmpty_Queue_StArr(Queue_StArr *queue) {
    return queue->front == -1 && queue->rear == -1;
}

bool isFull_Queue_StArr(Queue_StArr *queue) {
    return queue->rear + 1 == queue->capacity;
}


ll getRear_Queue_StArr(Queue_StArr *queue) {
    return isEmpty_Queue_StArr(queue) ? -1 : queue->arr[queue->rear];
}

ll getFront_Queue_StArr(Queue_StArr *queue) {
    return isEmpty_Queue_StArr(queue) ? -1 : queue->arr[queue->front];
}

void clear_Queue_StArr(Queue_StArr *queue) {
    queue->rear = -1;
    queue->front = -1;
}

void enqueue_Queue_StArr(Queue_StArr *queue, long long int element) {
    if (isFull_Queue_StArr(queue)) return;
    // if first enqueue operation
    if (queue->rear == -1) queue->front = 0;

    queue->arr[++queue->rear] = element;
}

ll dequeue_Queue_StArr(Queue_StArr *queue) {
    if (isEmpty_Queue_StArr(queue)) return -1;
    ll toReturn = queue->arr[queue->front++];

    // if last dequeue operation then empty the queue
    if (queue->front == queue->capacity)
        clear_Queue_StArr(queue);
    return toReturn;
}

void printQueue_StArr(Queue_StArr *queue) {
    if (isEmpty_Queue_StArr(queue)) {
        printf("empty queue");
        return;
    }

    for (int i = queue->front; i <= queue->rear; ++i)
        printf("%lld ", queue->arr[i]);
}





