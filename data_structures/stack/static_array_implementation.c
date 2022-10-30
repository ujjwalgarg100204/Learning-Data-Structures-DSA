#include "static_array_implementation.h"
#include <stdlib.h>

Stack_StArr *newStack_StArr(int capacity) {
    Stack_StArr *stack = malloc(sizeof(Stack_StArr));
    stack->arr = malloc(sizeof(ll) * capacity);
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

bool isFull_StArr(Stack_StArr *stack) {
    return stack->top + 1 == stack->capacity;
}

bool push_StArr(Stack_StArr *stack, long long int element) {
    if (isFull_StArr(stack))
        return false;
    stack->arr[++stack->top] = element;
    return true;
}

bool isEmpty_StArr(Stack_StArr *stack) {
    return stack->top == -1;
}

ll pop_StArr(Stack_StArr *stack) {
    if (isEmpty_StArr(stack)) return -1;
    return stack->arr[stack->top--];
}

void freeStack_StArr(Stack_StArr *stack) {
    free(stack->arr);
    free(stack);
}

ll getTop_StArr(Stack_StArr *stack) {
    return isEmpty_StArr(stack) ? -1 : stack->arr[stack->top];
}
