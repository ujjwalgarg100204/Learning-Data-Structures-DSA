
#ifndef DATA_STRUCTURES_AND_ALGORITHM_LINKED_STACK_H
#define DATA_STRUCTURES_AND_ALGORITHM_LINKED_STACK_H

#include "../../linked_list/implementation/linked_list.h"
#include <stdbool.h>

typedef struct Stack {
    LinkedList *list;
} Stack;

Stack *newStack();

bool isEmpty(Stack *stack);

void push(Stack *stack, int val);

void pop(Stack *stack);

int peek(Stack *stack);

void freeStack(Stack *stack);


#endif //DATA_STRUCTURES_AND_ALGORITHM_LINKED_STACK_H
