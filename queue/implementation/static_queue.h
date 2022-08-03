#ifndef DATA_STRUCTURES_AND_ALGORITHM_STATIC_QUEUE_H
#define DATA_STRUCTURES_AND_ALGORITHM_STATIC_QUEUE_H

#include <stdbool.h>

typedef struct QueueI {
    int *arr;
    int front;
    int rear;
    int size;
} QueueI;

/*
 * Creates a static queue using array of given size
 */
QueueI *newQueueI(int size);

/*
 * Returns true if queue is empty, false if not
 */
bool isEmpty(QueueI *queue);

/*
 * Returns true if queue is full, false if not
 */
bool isFullI(QueueI *queue);

/*
 * Appends data to queue if space is available, otherwise does nothing
 */
void enqueueI(QueueI *queue, int val);

/*
 * Simply moves pointer of front one point ahead if it is not empty.
 * If queue is empty, it does nothing
 */
void dequeueI(QueueI *queue);

/*
 * gives the value what is going to be removed on next dequeue operation
 */
int peekI(QueueI *queue);

int getRearI(QueueI *queue);

int getFrontI(QueueI *queue);

void freeQueueI(QueueI *queue);

#endif //DATA_STRUCTURES_AND_ALGORITHM_STATIC_QUEUE_H
