#include "ll_implementation.h"
#include <stdlib.h>

Queue_List_SC *newQueue_List_SC() {
    Queue_List_SC *queue = malloc(sizeof(Queue_List_SC));
    queue->list = newSinglyLinkedList_SC();
    return queue;
}

void freeQueue_List_SC(Queue_List_SC *queue) {
    freeLinkedList_SC(queue->list);
    free(queue);
}

bool isEmpty_Queue_List_SC(Queue_List_SC *queue) {
    return isEmptyList_SC(queue->list);
}

void enqueue_Queue_List_SC(Queue_List_SC *queue, long long int element) {
    addLastList_SC(queue->list, element);
}

ll dequeue_Queue_List_SC(Queue_List_SC *queue) {
    return removeFirstList_SC(queue->list);
}

/*
 * This function can be made O(1) by maintaining a separate tail pointer of linked list
 */
ll getRear_Queue_List_SC(Queue_List_SC *queue) {
    return getLastList_SC(queue->list);
}

ll getFront_Queue_List_SC(Queue_List_SC *queue) {
    return getFirstList_SC(queue->list);
}

void clear_Queue_List_SC(Queue_List_SC *queue) {
    clearList_SC(queue->list);
}

void printQueue_List_SC(Queue_List_SC *queue) {
    printList_SC(queue->list);
}