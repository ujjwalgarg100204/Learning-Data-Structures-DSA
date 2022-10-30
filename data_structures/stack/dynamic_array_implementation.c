#include <stdlib.h>
#include "dynamic_array_implementation.h"

Stack_DyArr *newStack_DyArr() {
    Stack_DyArr *stack = malloc(sizeof(Stack_DyArr));
    stack->arr = newDynamicArray();
    stack->top = stack->arr->size - 1;
    return stack;
}

void freeStack_DyArr(Stack_DyArr *stack) {
    freeDynamicArray(stack->arr);
    free(stack);
}

void push_DyArr(Stack_DyArr *stack, long long int element) {
    addLastArr(stack->arr, element);
    stack->top++;
}

bool isEmpty_DyArr(Stack_DyArr *stack) {
    return isEmptyArr(stack->arr);
}

ll pop_DyArr(Stack_DyArr *stack) {
    return isEmpty_DyArr(stack) ? -1 : removeAtArr(stack->arr, stack->top--);
}

ll getTop_DyArr(Stack_DyArr *stack) {
    return isEmpty_DyArr(stack) ? -1 : getAtArr(stack->arr, stack->top);
}







