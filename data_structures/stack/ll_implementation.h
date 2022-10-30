#ifndef CODES_LL_IMPLEMENTATION_H
#define CODES_LL_IMPLEMENTATION_H

#include "../linked_list/singly/singly_ll.h"

typedef struct Stack_List_S {
    LinkedList_S *list;
} Stack_List_S;

Stack_List_S *newStack_List_S();

void push_Stack_List_S(Stack_List_S *stack, ll element);

bool isEmpty_Stack_List_S(Stack_List_S *stack);

ll pop_Stack_List_S(Stack_List_S *stack);

ll getTop_Stack_List_S(Stack_List_S *stack);

void freeStack_List_S(Stack_List_S *stack);

#endif //CODES_LL_IMPLEMENTATION_H
