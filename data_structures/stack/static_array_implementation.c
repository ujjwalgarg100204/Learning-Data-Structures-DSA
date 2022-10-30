#include "static_array_implementation.h"
#include <stdlib.h>
#include <stdio.h>

/*
 * Creates a stack which is implemented using static array
 * Stack_StArr -> Stack implemented using Static Array
 * Returns a pointer to the struct Stack_StArr
 */
Stack_StArr *newStack_StArr(int capacity) {
    Stack_StArr *stack = malloc(sizeof(Stack_StArr));
    stack->arr = malloc(sizeof(ll) * capacity);
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

/*
 * Returns true is stack is completely full and can't hold anymore elements
 */
bool isFull_Stack_StArr(Stack_StArr *stack) {
    return stack->top + 1 == stack->capacity;
}

/*
 * Adds the element to the stack
 */
bool push_Stack_StArr(Stack_StArr *stack, long long int element) {
    if (isFull_Stack_StArr(stack))
        return false;
    stack->arr[++stack->top] = element;
    return true;
}

/*
 * Returns true if stack is empty, false if stack has some elements in it
 */
bool isEmpty_Stack_StArr(Stack_StArr *stack) {
    return stack->top == -1;
}

/*
 * Removes the top of stack and returns its value
 * If stack is empty, then GARBAGE VALUE is returned, and no operation is
 * done on stack
 */
ll pop_Stack_StArr(Stack_StArr *stack) {
    if (isEmpty_Stack_StArr(stack)) return -1;
    return stack->arr[stack->top--];
}

/*
 * Frees the memory for stack
 */
void freeStack_StArr(Stack_StArr *stack) {
    free(stack->arr);
    free(stack);
}

/*
 * Returns whatever element is at the top of stack
 * If stack is empty, then GARBAGE VALUE is returned
 */
ll getTop_Stack_StArr(Stack_StArr *stack) {
    return isEmpty_Stack_StArr(stack) ? -1 : stack->arr[stack->top];
}

/*
 * Prints elements contained in stack from top to bottom
 * Time Complexity: O(n)
 */
void print_Stack_StArr(Stack_StArr *stack) {
    if (isEmpty_Stack_StArr(stack)) {
        printf("empty stack");
        return;
    }

    for (int i = stack->top; i >= 0; --i)
        printf("%lld ", stack->arr[i]);
}
