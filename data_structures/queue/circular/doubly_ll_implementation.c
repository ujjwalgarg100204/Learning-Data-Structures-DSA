#include "doubly_ll_implementation.h"
#include <stdlib.h>

/*
 * Creates a circular queue which is implemented using doubly circular linked list
 * Queue_List_DC -> Queue implemented using Linked List D -> Doubly, C -> Circular
 * Returns a pointer to the struct Queue_List_DC
 */
Queue_List_DC *newQueue_List_DC() {
    Queue_List_DC *queue = malloc(sizeof(Queue_List_DC));
    queue->list = newLinkedList_DC();
    return queue;
}

/*
 * Frees the memory allocated for circular queue
 * Time Complexity: O(n)
 */
void freeQueue_List_DC(Queue_List_DC *queue) {
    freeLinkedList_DC(queue->list);
}

/*
 * Returns false if queue contains elements, true if queue is empty
 * Time Complexity: O(1)
 */
bool isEmpty_Queue_List_DC(Queue_List_DC *queue) {
    return isEmptyList_DC(queue->list);
}

/*
 * Enqueues element in the queue if queue has enough space to add one more element
 * otherwise no action is done on the queue
 * Time Complexity: O(1)
 */
void enqueue_Queue_List_DC(Queue_List_DC *queue, long long int element) {
    addLastList_DC(queue->list, element);
}

/*
 * Dequeues element from the front of the queue if queue is not empty
 * If queue is empty, a GARBAGE VALUE is returned and no operation is done on queue
 * Time Complexity: O(1)
 */
ll dequeue_Queue_List_DC(Queue_List_DC *queue) {
    return removeFirstList_DC(queue->list);
}

/*
 * Returns element at the rear of the queue
 * If queue is empty, a GARBAGE VALUE is returned
 * Time Complexity: O(1)
 */
ll getRear_Queue_List_DC(Queue_List_DC *queue) {
    return getLastList_DC(queue->list);
}

/*
 * Returns element at the front of the queue
 * If queue is empty, a GARBAGE VALUE is returned
 * Time Complexity: O(1)
 */
ll getFront_Queue_List_DC(Queue_List_DC *queue) {
    return getFirstList_DC(queue->list);
}

/*
 * Empties the queue
 * Time Complexity: O(n)
 */
void clear_Queue_List_DC(Queue_List_DC *queue) {
    clearList_DC(queue->list);
}

/*
 * Prints the contents of the queue on the console/terminal
 * it prints from front to rear of the queue
 * Time Complexity: O(n)
 */
void printQueue_List_DC(Queue_List_DC *queue) {
    printList_DC(queue->list);
}
