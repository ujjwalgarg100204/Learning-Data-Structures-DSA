#ifndef CODES_LL_IMPLEMENTATION_H
#define CODES_LL_IMPLEMENTATION_H

#include "../../linked_list/circular_singly/singly_circular_ll.h"

typedef struct Queue_List_SC {
    LinkedList_S *list;
    Node_S *rear;
} Queue_List_SC;

Queue_List_SC *newQueue_List_SC();

void freeQueue_List_SC(Queue_List_SC *queue);

bool isEmpty_Queue_List_SC(Queue_List_SC *queue);

void enqueue_Queue_List_SC(Queue_List_SC *queue, ll element);

ll dequeue_Queue_List_SC(Queue_List_SC *queue);

ll getRear_Queue_List_SC(Queue_List_SC *queue);

ll getFront_Queue_List_SC(Queue_List_SC *queue);

void clear_Queue_List_SC(Queue_List_SC *queue);

void printQueue_List_SC(Queue_List_SC *queue);

#endif //CODES_LL_IMPLEMENTATION_H
