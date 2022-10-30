#include "ll_implementation.h"
#include <stdlib.h>

/*
 * Creates a circular queue which is implemented using singly circular linked list
 * Queue_List_SC -> Queue implemented using Linked List S -> Singly, C -> Circular
 * Returns a pointer to the struct Queue_List_SC
 */
Queue_List_SC *newQueue_List_SC() {
    Queue_List_SC *queue = malloc(sizeof(Queue_List_SC));
    queue->list = newSinglyLinkedList_SC();
    return queue;
}

/*
 * Frees the memory allocated for circular queue
 * Time Complexity: O(n)
 */
void freeQueue_List_SC(Queue_List_SC *queue) {
    freeLinkedList_SC(queue->list);
    free(queue);
}

/*
 * Returns false if queue contains elements, true if queue is empty
 * Time Complexity: O(1)
 */
bool isEmpty_Queue_List_SC(Queue_List_SC *queue) {
    return isEmptyList_SC(queue->list);
}

/*
 * Enqueues element in the queue if queue has enough space to add one more element
 * otherwise no action is done on the queue
 * Time Complexity: O(1)
 */
void enqueue_Queue_List_SC(Queue_List_SC *queue, long long int element) {
    addLastList_SC(queue->list, element);
}

/*
 * Dequeues element from the front of the queue if queue is not empty
 * If queue is empty, a GARBAGE VALUE is returned and no operation is done on queue
 * Time Complexity: O(1)
 */
ll dequeue_Queue_List_SC(Queue_List_SC *queue) {
    return removeFirstList_SC(queue->list);
}

/*
 * Returns element at the rear of the queue
 * If queue is empty, a GARBAGE VALUE is returned
 * Time Complexity: O(n)
 * NOTE: This function can be made O(1) by maintaining a separate tail pointer of linked list
 */
ll getRear_Queue_List_SC(Queue_List_SC *queue) {
    return getLastList_SC(queue->list);
}

/*
 * Returns element at the front of the queue
 * If queue is empty, a GARBAGE VALUE is returned
 * Time Complexity: O(1)
 */
ll getFront_Queue_List_SC(Queue_List_SC *queue) {
    return getFirstList_SC(queue->list);
}

/*
 * Empties the queue
 * Time Complexity: O(n)
 */
void clear_Queue_List_SC(Queue_List_SC *queue) {
    clearList_SC(queue->list);
}

/*
 * Prints the contents of the queue on the console/terminal
 * it prints from front to rear of the queue
 * Time Complexity: O(n)
 */
void printQueue_List_SC(Queue_List_SC *queue) {
    printList_SC(queue->list);
}