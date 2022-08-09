#include <stdio.h>
#include <stdlib.h>

#include "linked_stack.h"


Stack *newStack() {
    Stack *stack = malloc(sizeof(Stack));
    stack->list = newLinkedList();
    return stack;
}

bool isEmpty(Stack *stack) {
    return isListEmpty(stack->list);
}

void push(Stack *stack, int val) {
    addFirst(stack->list, val);
}

void pop(Stack *stack) {
    deleteFirst(stack->list);
}

int peek(Stack *stack) {
    return getIntAt(stack->list, 0);
}

void freeStack(Stack *stack) {
    freeLinkedList(stack->list);
    free(stack);
}

