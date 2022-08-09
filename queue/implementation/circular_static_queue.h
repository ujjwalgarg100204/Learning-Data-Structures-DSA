#ifndef DATA_STRUCTURES_AND_ALGORITHM_CIRCULAR_STATIC_QUEUE_H
#define DATA_STRUCTURES_AND_ALGORITHM_CIRCULAR_STATIC_QUEUE_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct QueueI {
    int *arr;
    int size;
    int front;
    int rear;
} QueueI;

QueueI *newCircularQueueI(int size);

void freeCircularQueueI(QueueI *queue);

bool isEmptyI(QueueI *queue);

bool isFullI(QueueI *queue);

void enqueueI(QueueI *queue, int val);

int dequeueI(QueueI *queue);

int getRearI(QueueI *queue);

int getFrontI(QueueI *queue);

#endif //DATA_STRUCTURES_AND_ALGORITHM_CIRCULAR_STATIC_QUEUE_H
