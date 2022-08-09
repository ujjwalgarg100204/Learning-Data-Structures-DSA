#include <stdio.h>

#include "circular_static_queue.h"

QueueI *newCircularQueueI(int size) {
    QueueI *queue = malloc(sizeof(QueueI));
    queue->arr = calloc(size, sizeof(int));
    queue->size = size;
    queue->front = -1;
    queue->rear = -1;

    return queue;
}

void freeCircularQueueI(QueueI *queue) {
    free(queue->arr);
    free(queue);
}

bool isEmptyI(QueueI *queue) {
    return queue->rear == -1 && queue->front == -1;
}

bool isFullI(QueueI *queue) {
    return (queue->rear + 1) % queue->size == queue->front;
}

void enqueueI(QueueI *queue, int val) {
    if (isFullI(queue)) {
        printf("Queue overflow!\n");
        return;
    }

    // if first enqueue operation
    if (queue->front == -1) {
        queue->front++;
    }
    queue->rear = (queue->rear + 1) % queue->size;
    queue->arr[queue->rear] = val;
}

int dequeueI(QueueI *queue) {
    if (isEmptyI(queue)) {
        printf("Queue underflow!\n");
        return -1;
    }

    int toReturn = queue->arr[queue->front];
    queue->front = (queue->front + 1) % queue->size;
    // if queue is completely empty, then set rear and front to -1
    if (queue->front == (queue->rear + 1) % queue->size) {
        queue->front = -1;
        queue->rear = -1;
    }

    return toReturn;
}

int getRearI(QueueI *queue) {
    return queue->arr[queue->rear];
}

int getFrontI(QueueI *queue) {
    return queue->arr[queue->rear];
}
