#ifndef CODES_STATIC_ARRAY_H
#define CODES_STATIC_ARRAY_H

#include <stdbool.h>

#define ll long long

typedef struct Queue_StArr {
    ll *arr;
    int front;
    int rear;
    int capacity;
} Queue_StArr;

Queue_StArr *newQueue_StArr(int capacity);

void freeQueue_St_Arr(Queue_StArr *queue);

bool isEmpty_Queue_StArr(Queue_StArr *queue);

bool isFull_Queue_StArr(Queue_StArr *queue);

/*
 * Inserts the specified element into the queue at the front of the queue
 */
void enqueue_Queue_StArr(Queue_StArr *queue, ll element);

/*
 * Used to retrieve and removes the head of the queue, or returns GARBAGE VALUE
 * if queue is empty
 */
ll dequeue_Queue_StArr(Queue_StArr *queue);

ll getRear_Queue_StArr(Queue_StArr *queue);

ll getFront_Queue_StArr(Queue_StArr *queue);

void clear_Queue_StArr(Queue_StArr *queue);

void printQueue_StArr(Queue_StArr *queue);

#endif //CODES_STATIC_ARRAY_H
