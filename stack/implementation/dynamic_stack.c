#include <stdlib.h>
#include <stdio.h>
#include "dynamic_stack.h"

/* Struct for stack
typedef struct Stack {
    int *arr;
    int top;
    int length;
} Stack;
*/

/* Character Stack */
StackC *newStackC() {
    StackC *stack = malloc(sizeof(StackC));
    stack->arr = NULL;
    stack->top = -1;
    stack->size = 0;

    return stack;
}

/*
 * Returns true if stack is empty, false if not
 */
bool isEmptyC(StackC *stack) {
    return stack->top == -1;
}

/*
 * Pushes argument val to the stack
 */
void pushC(StackC *stack, char val) {
    // allocate memory for new member, while copying old values
    stack->arr = realloc(stack->arr, sizeof(char) * (++stack->size));
    stack->arr[++stack->top] = val;
}

/*
 * If stack is not empty, deletes the last added element
 * If stack is empty, it does not do anything
 */
void popC(StackC *stack) {
    // won't generate any error if stack is empty
    if (isEmptyC(stack)) {
        printf("Stack Empty\n");
        return;
    }

    stack->arr = realloc(stack->arr, sizeof(char) * (--stack->size));
    stack->top--;
}

/*
 * Returns top of the stack, if stack is not empty
 * returns -1 if stack is empty
 */
char peekC(StackC *stack) {
    if (isEmptyC(stack)) {
        printf("Stack Empty\n");
        return -1;
    }

    return stack->arr[stack->top];
}

/*
 * Frees stack memory
 */
void freeStackC(StackC *stack) {
    free(stack->arr);
    free(stack);
}


/* Double Stack */
StackD *newStackD() {
    StackD *stack = malloc(sizeof(StackD));
    stack->arr = NULL;
    stack->top = -1;
    stack->size = 0;

    return stack;
}

/*
 * Returns true if stack is empty, false if not
 */
bool isEmptyD(StackD *stack) {
    return stack->top == -1;
}

/*
 * Pushes argument val to the stack
 */
void pushD(StackD *stack, double val) {
    // allocate memory for new member, while copying old values
    stack->arr = realloc(stack->arr, sizeof(double) * (++stack->size));
    stack->arr[++stack->top] = val;
}

/*
 * If stack is not empty, deletes the last added element
 * If stack is empty, it does not do anything
 */
void popD(StackD *stack) {
    // won't generate any error if stack is empty
    if (isEmptyD(stack)) {
        printf("Stack Empty\n");
        return;
    }

    stack->arr = realloc(stack->arr, sizeof(double) * (--stack->size));
    stack->top--;
}

/*
 * Returns top of the stack, if stack is not empty
 * returns -1 if stack is empty
 */
double peekD(StackD *stack) {
    if (isEmptyD(stack)) {
        printf("Stack Empty\n");
        return -1;
    }

    return stack->arr[stack->top];
}

/*
 * Frees stack memory
 */
void freeStackD(StackD *stack) {
    free(stack->arr);
    free(stack);
}


/* Integer Stack */
StackI *newStackI() {
    StackI *stack = malloc(sizeof(StackI));
    stack->arr = NULL;
    stack->top = -1;
    stack->size = 0;

    return stack;
}

/*
 * Returns true if stack is empty, false if not
 */
bool isEmptyI(StackI *stack) {
    return stack->top == -1;
}

/*
 * Pushes argument val to the stack
 */
void pushI(StackI *stack, int val) {
    // allocate memory for new member, while copying old values
    stack->arr = realloc(stack->arr, sizeof(int) * (++stack->size));
    stack->arr[++stack->top] = val;
}

/*
 * If stack is not empty, deletes the last added element
 * If stack is empty, it does not do anything
 */
void popI(StackI *stack) {
    // won't generate any error if stack is empty
    if (isEmptyI(stack)) {
        printf("Stack Empty\n");
        return;
    }

    stack->arr = realloc(stack->arr, sizeof(int) * (--stack->size));
    stack->top--;
}

/*
 * Returns top of the stack, if stack is not empty
 * returns -1 if stack is empty
 */
int peekI(StackI *stack) {
    if (isEmptyI(stack)) {
        printf("Stack Empty\n");
        return -1;
    }

    return stack->arr[stack->top];
}

/*
 * Frees stack memory
 */
void freeStackI(StackI *stack) {
    free(stack->arr);
    free(stack);
}


/* Long Stack */
StackL *newStackL() {
    StackL *stack = malloc(sizeof(StackL));
    stack->arr = NULL;
    stack->top = -1;
    stack->size = 0;

    return stack;
}

/*
 * Returns true if stack is empty, false if not
 */
bool isEmptyL(StackL *stack) {
    return stack->top == -1;
}

/*
 * Pushes argument val to the stack
 */
void pushL(StackL *stack, long val) {
    // allocate memory for new member, while copying old values
    stack->arr = realloc(stack->arr, sizeof(long) * (++stack->size));
    stack->arr[++stack->top] = val;
}

/*
 * If stack is not empty, deletes the last added element
 * If stack is empty, it does not do anything
 */
void popL(StackL *stack) {
    // won't generate any error if stack is empty
    if (isEmptyL(stack)) {
        printf("Stack Empty\n");
        return;
    }

    stack->arr = realloc(stack->arr, sizeof(long) * (--stack->size));
    stack->top--;
}

/*
 * Returns top of the stack, if stack is not empty
 * returns -1 if stack is empty
 */
long peekL(StackL *stack) {
    if (isEmptyL(stack)) {
        printf("Stack Empty\n");
        return -1;
    }

    return stack->arr[stack->top];
}

/*
 * Frees stack memory
 */
void freeStackL(StackL *stack) {
    free(stack->arr);
    free(stack);
}
