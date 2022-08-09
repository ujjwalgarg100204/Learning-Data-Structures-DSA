#ifndef DSA1_STATIC_STACK_H
#define DSA1_STATIC_STACK_H

#include <stdbool.h>

// Integer Stack
typedef struct StackI {
    int *arr;
    int top;
    int size;
} StackI;

/* Integer Stack */
StackI *newStackI(int size);

bool isEmptyI(StackI *stack);

bool isFullI(StackI *stack);

void pushI(StackI *stack, int val);

int peekI(StackI *stack);

void popI(StackI *stack);

void freeStackI(StackI *stack);


/* Double Stack */
typedef struct StackD {
    double *arr;
    int top;
    int size;
} StackD;

StackD *newStackD(int size);

bool isEmptyD(StackD *stack);

bool isFullD(StackD *stack);

void pushD(StackD *stack, double val);

int peekD(StackD *stack);

void popD(StackD *stack);

void freeStackD(StackD *stack);


/* Character Stack */
typedef struct StackC {
    char *arr;
    int top;
    int size;
} StackC;

StackC *newStackC(int size);

bool isEmptyC(StackC *stack);

bool isFullC(StackC *stack);

void pushC(StackC *stack, char val);

int peekC(StackC *stack);

void popC(StackC *stack);

void freeStackC(StackC *stack);


/* Long Stack */
typedef struct StackL {
    long *arr;
    int top;
    int size;
} StackL;

StackL *newStackL(int size);

bool isEmptyL(StackL *stack);

bool isFullL(StackL *stack);

void pushL(StackL *stack, long val);

int peekL(StackL *stack);

void popL(StackL *stack);

void freeStackL(StackL *stack);

#endif //DSA1_STATIC_STACK_H
