#include <stdio.h>
#include <string.h>

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

/* For String Datatype */
QueueS *newCircularQueueS(int size) {
    QueueS *queue = malloc(sizeof(QueueS));
    queue->arr = calloc(size, sizeof(char *));
    queue->size = size;
    queue->front = -1;
    queue->rear = -1;

    return queue;
}

void freeCircularQueueS(QueueS *queue) {
    // free each string in the queue
    for (int i = 0; i < queue->size; i++) {
        free(queue->arr[i]);
    }
    free(queue->arr);
    free(queue);
}

bool isEmptyS(QueueS *queue) {
    return queue->rear == -1 && queue->front == -1;
}

bool isFullS(QueueS *queue) {
    return (queue->rear + 1) % queue->size == queue->front;
}

void enqueueS(QueueS *queue, const char *val) {
    if (isFullS(queue)) {
        printf("Queue overflow!\n");
        return;
    }

    // if first enqueue operation
    if (queue->front == -1) {
        queue->front++;
    }
    queue->rear = (queue->rear + 1) % queue->size;

    queue->arr[queue->rear] = malloc(sizeof(char) * (strlen(val) + 1));
    strcpy(queue->arr[queue->rear], val);
}

/* Returns the dequeued string, so remember to free it*/
char *dequeueS(QueueS *queue) {
    if (isEmptyS(queue)) {
        printf("Queue underflow!\n");
        return NULL;
    }

    char *toReturn = queue->arr[queue->front];
    queue->arr[queue->front] = NULL;
    queue->front = (queue->front + 1) % queue->size;
    // if queue is completely empty, then set rear and front to -1
    if (queue->front == (queue->rear + 1) % queue->size) {
        queue->front = -1;
        queue->rear = -1;
    }

    return toReturn;
}

char *getRearS(QueueS *queue) {
    return queue->arr[queue->rear];
}

char *getFrontS(QueueS *queue) {
    return queue->arr[queue->rear];
}
