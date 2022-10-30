#ifndef CODES_LL_IMPLEMENTATION_H
#define CODES_LL_IMPLEMENTATION_H

#include <stdbool.h>
#include "../../linked_list/singly_node.h"

typedef struct Queue_List_S {
    Node_S *front;
    Node_S *rear;
} Queue_List_S;


Queue_List_S *newQueue_List_S();

void freeQueue_List_S(Queue_List_S *queue);

bool isEmpty_Queue_List_S(Queue_List_S *queue);

void enqueue_Queue_List_S(Queue_List_S *queue, ll element);

ll dequeue_Queue_List_S(Queue_List_S *queue);

ll getRear_Queue_List_S(Queue_List_S *queue);

ll getFront_Queue_List_S(Queue_List_S *queue);

void clear_Queue_List_S(Queue_List_S *queue);

void printQueue_List_S(Queue_List_S *queue);

#endif //CODES_LL_IMPLEMENTATION_H
