#include "ll_implementation.h"
#include <stdlib.h>
#include <stdio.h>

Queue_List_S *newQueue_List_S() {
    Queue_List_S *queue = malloc(sizeof(Queue_List_S));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

void freeQueue_List_S(Queue_List_S *queue) {
    clear_Queue_List_S(queue);
    free(queue);
}

bool isEmpty_Queue_List_S(Queue_List_S *queue) {
    return queue->front == NULL && queue->rear == NULL;
}

void enqueue_Queue_List_S(Queue_List_S *queue, long long int element) {
    Node_S *new = newNode_S(element);

    // if first enqueue operation
    if (isEmpty_Queue_List_S(queue)) {
        queue->front = new;
        queue->rear = new;
        return;
    }

    queue->rear->next = new;
    queue->rear = new;
}

ll dequeue_Queue_List_S(Queue_List_S *queue) {
    // check for empty queue
    if (isEmpty_Queue_List_S(queue)) return -1;

    ll toReturn = queue->front->data;

    Node_S *next = queue->front->next;
    free(queue->front);
    queue->front = next;

    // if last dequeue operation
    if (queue->front == NULL) queue->rear = NULL;

    return toReturn;
}

ll getRear_Queue_List_S(Queue_List_S *queue) {
    return isEmpty_Queue_List_S(queue) ? -1 : queue->rear->data;
}

ll getFront_Queue_List_S(Queue_List_S *queue) {
    return isEmpty_Queue_List_S(queue) ? -1 : queue->front->data;
}

void clear_Queue_List_S(Queue_List_S *queue) {
    while (queue->front != NULL) {
        Node_S *next = queue->front->next;
        freeNode_S(queue->front);
        queue->front = next;
    }
}

void printQueue_List_S(Queue_List_S *queue) {
    if (isEmpty_Queue_List_S(queue)) {
        printf("empty queue");
        return;
    }

    for (Node_S *curr = queue->front; curr != NULL; curr = curr->next)
        printf("%lld ", curr->data);
}


