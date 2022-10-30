#include <stdlib.h>
#include <stdio.h>
#include "static_array.h"

Queue_Cir_StArr *newCircularQueue_StArr(int capacity) {
    Queue_Cir_StArr *queue = malloc(sizeof(Queue_Cir_StArr));
    queue->arr = malloc(sizeof(ll) * capacity);
    queue->capacity = capacity;
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

void freeCircularQueue_StArr(Queue_Cir_StArr *queue) {
    free(queue->arr);
    free(queue);
}

bool isEmpty_Queue_Cir_StArr(Queue_Cir_StArr *queue) {
    return queue->rear == -1 && queue->front == -1;
}

bool isFull_Queue_Cir_StArr(Queue_Cir_StArr *queue) {
    return (queue->rear + 1) % queue->capacity == queue->front;
}

void enqueue_Queue_Cir_StArr(Queue_Cir_StArr *queue, long long int element) {
    if (isFull_Queue_Cir_StArr(queue)) return;

    // if first enqueue operation
    if (queue->front == -1) queue->front = 0;

    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->arr[queue->rear] = element;
}

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

ll getRear_Queue_Cir_StArr(Queue_Cir_StArr *queue) {
    return queue->arr[queue->rear];
}

ll getFront_Queue_Cir_StArr(Queue_Cir_StArr *queue) {
    return queue->arr[queue->rear];
}

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

