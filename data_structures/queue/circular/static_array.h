#ifndef CODES_STATIC_ARRAY_H
#define CODES_STATIC_ARRAY_H

#include <stdbool.h>

#define ll long long

typedef struct Queue_Cir_StArr {
    ll *arr;
    int capacity;
    int front;
    int rear;
} Queue_Cir_StArr;


Queue_Cir_StArr *newCircularQueue_StArr(int capacity);

void freeCircularQueue_StArr(Queue_Cir_StArr *queue);

bool isEmpty_Queue_Cir_StArr(Queue_Cir_StArr *queue);

bool isFull_Queue_Cir_StArr(Queue_Cir_StArr *queue);

void enqueue_Queue_Cir_StArr(Queue_Cir_StArr *queue, ll element);

ll dequeue_Queue_Cir_StArr(Queue_Cir_StArr *queue);

ll getRear_Queue_Cir_StArr(Queue_Cir_StArr *queue);

ll getFront_Queue_Cir_StArr(Queue_Cir_StArr *queue);

void printQueue_Cir_StArr(Queue_Cir_StArr *queue);

#endif //CODES_STATIC_ARRAY_H
