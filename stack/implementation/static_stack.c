#include "static_stack.h"

#include <stdlib.h>
#include <stdio.h>

/* Struct defined for stack
 typedef struct Stack {
    int *arr;
    int top;
    int currSize;
} Stack;
 */

/* Integer Stack */
StackI *newStackI(int size) {
    StackI *stack = malloc(sizeof(StackI));
    stack->arr = malloc(sizeof(int) * size);
    stack->top = -1;
    stack->size = size;

    return stack;
}

void freeStackI(StackI *stack) {
    free(stack->arr);
    free(stack);
}

void pushI(StackI *stack, int val) {
    if (!isFullI(stack)) {
        stack->arr[++stack->top] = val;
    } else {
        printf("Stack Overflow\n");
    }
}

bool isEmptyI(StackI *stack) {
    return stack->top == -1;
}

bool isFullI(StackI *stack) {
    return stack->top + 1 == stack->size;
}

int peekI(StackI *stack) {
    if (isEmptyI(stack)) {
        return -1;
    }
    return stack->arr[stack->top];
}

void popI(StackI *stack) {
    if (!isEmptyI(stack)) {
        stack->top--;
    } else {
        printf("Stack Empty\n");
    }
}

/* Double Stack */
StackD *newStackD(int size) {
    StackD *stack = malloc(sizeof(StackD));
    stack->arr = malloc(sizeof(int) * size);
    stack->top = -1;
    stack->size = size;

    return stack;
}

void freeStackD(StackD *stack) {
    free(stack->arr);
    free(stack);
}

void pushD(StackD *stack, double val) {
    if (!isFullD(stack)) {
        stack->arr[++stack->top] = val;
    } else {
        printf("Stack Overflow\n");
    }
}

bool isEmptyD(StackD *stack) {
    return stack->top == -1;
}

bool isFullD(StackD *stack) {
    return stack->top + 1 == stack->size;
}

int peekD(StackD *stack) {
    if (isEmptyD(stack)) {
        return -1;
    }
    return stack->arr[stack->top];
}

void popD(StackD *stack) {
    if (!isEmptyD(stack)) {
        stack->top--;
    } else {
        printf("Stack Empty\n");
    }
}

/* Character Stack */
StackC *newStackC(int size) {
    StackC *stack = malloc(sizeof(StackC));
    stack->arr = malloc(sizeof(char) * size);
    stack->top = -1;
    stack->size = size;

    return stack;
}

void freeStackC(StackC *stack) {
    free(stack->arr);
    free(stack);
}

void pushC(StackC *stack, char val) {
    if (!isFullC(stack)) {
        stack->arr[++stack->top] = val;
    } else {
        printf("Stack Overflow\n");
    }
}

bool isEmptyC(StackC *stack) {
    return stack->top == -1;
}

bool isFullC(StackC *stack) {
    return stack->top + 1 == stack->size;
}

int peekC(StackC *stack) {
    if (isEmptyC(stack)) {
        return -1;
    }
    return stack->arr[stack->top];
}

void popC(StackC *stack) {
    if (!isEmptyC(stack)) {
        stack->top--;
    } else {
        printf("Stack Empty\n");
    }
}

/* Long Integer Stack */
StackL *newStackL(int size) {
    StackL *stack = malloc(sizeof(StackL));
    stack->arr = malloc(sizeof(long) * size);
    stack->top = -1;
    stack->size = size;

    return stack;
}

void freeStackL(StackL *stack) {
    free(stack->arr);
    free(stack);
}

void pushL(StackL *stack, long val) {
    if (!isFullL(stack)) {
        stack->arr[++stack->top] = val;
    } else {
        printf("Stack Overflow\n");
    }
}

bool isEmptyL(StackL *stack) {
    return stack->top == -1;
}

bool isFullL(StackL *stack) {
    return stack->top + 1 == stack->size;
}

int peekL(StackL *stack) {
    if (isEmptyL(stack)) {
        return -1;
    }
    return stack->arr[stack->top];
}

void popL(StackL *stack) {
    if (!isEmptyL(stack)) {
        stack->top--;
    } else {
        printf("Stack Empty\n");
    }
}
