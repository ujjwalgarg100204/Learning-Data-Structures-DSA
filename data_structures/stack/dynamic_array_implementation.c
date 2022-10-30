#include <stdlib.h>
#include <stdio.h>
#include "dynamic_array_implementation.h"

/*
 * Creates a stack which is implemented using dynamic array
 * Stack_StArr -> Stack implemented using Dynamic Array
 * Returns a pointer to the struct Stack_DyArr
 */
Stack_DyArr *newStack_DyArr() {
    Stack_DyArr *stack = malloc(sizeof(Stack_DyArr));
    stack->arr = newDynamicArray();
    stack->top = stack->arr->size - 1;
    return stack;
}

/*
 * Frees the memory for stack
 */
void freeStack_DyArr(Stack_DyArr *stack) {
    freeDynamicArray(stack->arr);
    free(stack);
}

/*
 * Adds the element to the stack
 */
void push_Stack_DyArr(Stack_DyArr *stack, long long int element) {
    addLastArr(stack->arr, element);
    stack->top++;
}

/*
 * Returns true if stack is empty, false if stack has some elements in it
 */
bool isEmpty_Stack_DyArr(Stack_DyArr *stack) {
    return isEmptyArr(stack->arr);
}

/*
 * Removes the top of stack and returns its value
 * If stack is empty, then GARBAGE VALUE is returned, and no operation is
 * done on stack
 */
ll pop_Stack_DyArr(Stack_DyArr *stack) {
    return isEmpty_Stack_DyArr(stack) ? -1 : removeAtArr(stack->arr, stack->top--);
}

/*
 * Returns whatever element is at the top of stack
 * If stack is empty, then GARBAGE VALUE is returned
 */
ll getTop_Stack_DyArr(Stack_DyArr *stack) {
    return isEmpty_Stack_DyArr(stack) ? -1 : getAtArr(stack->arr, stack->top);
}

/*
 * Prints elements contained in stack from top to bottom
 * Time Complexity: O(n)
 */
void print_Stack_DyArr(Stack_DyArr *stack) {
    if (isEmptyArr(stack->arr)) {
        printf("empty stack");
        return;
    }
    for (int i = stack->top; i >= 0; i--)
        printf("%lld ", getAtArr(stack->arr, i));
}







