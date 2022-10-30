#include "ll_implementation.h"
#include <stdlib.h>
#include <stdio.h>

/*
 * Creates a non-circular queue which is implemented using singly linked list
 * Queue_List_S -> Queue implemented using Linked List S -> Singly
 * Returns a pointer to the struct Queue_List_S
 */
Queue_List_S *newQueue_List_S() {
    Queue_List_S *queue = malloc(sizeof(Queue_List_S));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

/*
 * Frees the memory allocated for queue
 * Time Complexity: O(n)
 */
void freeQueue_List_S(Queue_List_S *queue) {
    clear_Queue_List_S(queue);
    free(queue);
}

/*
 * Returns false if queue contains elements, true if queue is empty
 * Time Complexity: O(1)
 */
bool isEmpty_Queue_List_S(Queue_List_S *queue) {
    return queue->front == NULL && queue->rear == NULL;
}

/*
 * Enqueues element in the queue if queue has enough space to add one more element
 * otherwise no action is done on the queue
 * Time Complexity: O(1)
 */
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

/*
 * Dequeues element from the front of the queue if queue is not empty
 * If queue is empty, a GARBAGE VALUE is returned and no operation is done on queue
 * Time Complexity: O(1)
 */
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

/*
 * Returns element at the rear of the queue
 * If queue is empty, a GARBAGE VALUE is returned
 * Time Complexity: O(1)
 */
ll getRear_Queue_List_S(Queue_List_S *queue) {
    return isEmpty_Queue_List_S(queue) ? -1 : queue->rear->data;
}

/*
 * Returns element at the front of the queue
 * If queue is empty, a GARBAGE VALUE is returned
 * Time Complexity: O(1)
 */
ll getFront_Queue_List_S(Queue_List_S *queue) {
    return isEmpty_Queue_List_S(queue) ? -1 : queue->front->data;
}

/*
 * Empties the queue
 * Time Complexity: O(n)
 */
void clear_Queue_List_S(Queue_List_S *queue) {
    while (queue->front != NULL) {
        Node_S *next = queue->front->next;
        freeNode_S(queue->front);
        queue->front = next;
    }
}

/*
 * Prints the contents of the queue on the console/terminal
 * it prints from front to rear of the queue
 * Time Complexity: O(n)
 */
void printQueue_List_S(Queue_List_S *queue) {
    if (isEmpty_Queue_List_S(queue)) {
        printf("empty queue");
        return;
    }

    for (Node_S *curr = queue->front; curr != NULL; curr = curr->next)
        printf("%lld ", curr->data);
}


