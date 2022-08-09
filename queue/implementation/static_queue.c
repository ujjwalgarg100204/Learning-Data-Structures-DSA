#include <stdlib.h>
#include <stdio.h>

#include "static_queue.h"


QueueI *newQueueI(int size) {
    QueueI *queue = malloc(sizeof(QueueI));
    queue->arr = calloc(size, sizeof(int));
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;

    return queue;
}

void enqueueI(QueueI *queue, int val) {
    // check for full
    if (isFullI(queue)) {
        printf("Queue is full\n");
        return;
    }

    // got the first enqueue operation
    if (queue->front == -1) {
        queue->arr[++queue->rear] = val;
        ++queue->front;
    } else {
        queue->arr[++queue->rear] = val;
    }
}

bool isFullI(QueueI *queue) {
    return queue->rear + 1 == queue->size;
}

void freeQueueI(QueueI *queue) {
    free(queue->arr);
    free(queue);
}

bool isEmpty(QueueI *queue) {
    return queue->front == -1;
}

int dequeueI(QueueI *queue) {
    if (isEmpty(queue)) {
        printf("Queue is Empty\n");
        return -1;
    }
    // equivalent to deleting the element from the front
    int toReturn = queue->arr[queue->front];
    queue->front++;

    // if front and rear becomes the same then restart the queue
    if (queue->front > queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    }
    return toReturn;
}

int peekI(QueueI *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }

    return queue->arr[queue->front];
}

int getRearI(QueueI *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->arr[queue->rear];
}

int getFrontI(QueueI *queue) {
    return peekI(queue);
}
