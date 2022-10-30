#include <stdlib.h>
#include "ll_implementation.h"

Stack_List_S *newStack_List_S() {
    Stack_List_S *stack = malloc(sizeof(Stack_List_S));
    stack->list = newSinglyLinkedList_S();
    return stack;
}

void push_List_S(Stack_List_S *stack, long long int element) {
    addFirstList_S(stack->list, element);
}

bool isEmpty_List_S(Stack_List_S *stack) {
    return isEmptyList_S(stack->list);
}

ll pop_List_S(Stack_List_S *stack) {
    return removeFirstList_S(stack->list);
}

ll getTop_List_S(Stack_List_S *stack) {
    return getFirstList_S(stack->list);
}

void freeStack_List_S(Stack_List_S *stack) {
    freeLinkedList_S(stack->list);
    free(stack);
}


