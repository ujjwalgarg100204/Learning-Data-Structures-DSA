#ifndef CODES_DOUBLY_LL_IMPLEMENTATION_H
#define CODES_DOUBLY_LL_IMPLEMENTATION_H

#include "../../linked_list/circular_doubly/doubly_circular_ll.h"

typedef struct Queue_List_DC {
    LinkedList_D *list;
} Queue_List_DC;

Queue_List_DC *newQueue_List_DC();

void freeQueue_List_DC(Queue_List_DC *queue);

bool isEmpty_Queue_List_DC(Queue_List_DC *queue);

void enqueue_Queue_List_DC(Queue_List_DC *queue, ll element);

ll dequeue_Queue_List_DC(Queue_List_DC *queue);

ll getRear_Queue_List_DC(Queue_List_DC *queue);

ll getFront_Queue_List_DC(Queue_List_DC *queue);

void clear_Queue_List_DC(Queue_List_DC *queue);

void printQueue_List_DC(Queue_List_DC *queue);

#endif //CODES_DOUBLY_LL_IMPLEMENTATION_H
