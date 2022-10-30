#include "doubly_ll_implementation.h"
#include <stdlib.h>

Queue_List_DC *newQueue_List_DC() {
    Queue_List_DC *queue = malloc(sizeof(Queue_List_DC));
    queue->list = newLinkedList_DC();
    return queue;
}

void freeQueue_List_DC(Queue_List_DC *queue) {
    freeLinkedList_DC(queue->list);
}

bool isEmpty_Queue_List_DC(Queue_List_DC *queue) {
    return isEmptyList_DC(queue->list);
}

void enqueue_Queue_List_DC(Queue_List_DC *queue, long long int element) {
    addLastList_DC(queue->list, element);
}

ll dequeue_Queue_List_DC(Queue_List_DC *queue) {
    return removeFirstList_DC(queue->list);
}

ll getRear_Queue_List_DC(Queue_List_DC *queue) {
    return getLastList_DC(queue->list);
}

ll getFront_Queue_List_DC(Queue_List_DC *queue) {
    return getFirstList_DC(queue->list);
}

void clear_Queue_List_DC(Queue_List_DC *queue) {
    clearList_DC(queue->list);
}

void printQueue_List_DC(Queue_List_DC *queue) {
    printList_DC(queue->list);
}
