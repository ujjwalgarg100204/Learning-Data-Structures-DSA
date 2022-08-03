#ifndef DSA_DYNAMIC_STACK_H
#define DSA_DYNAMIC_STACK_H

#include <stdbool.h>

// Character Stack
typedef struct StackC {
    char *arr;
    int top;
    int size;
} StackC;

StackC *newStackC();

bool isEmptyC(StackC *stack);

void pushC(StackC *stack, char val);

void popC(StackC *stack);

char peekC(StackC *stack);

void freeStackC(StackC *stack);


// Integer Stack
typedef struct StackI {
    int *arr;
    int top;
    int size;
} StackI;

StackI *newStackI();

bool isEmptyI(StackI *stack);

void pushI(StackI *stack, int val);

void popI(StackI *stack);

int peekI(StackI *stack);

void freeStackI(StackI *stack);


// Double Stack
typedef struct StackD {
    double *arr;
    int top;
    int size;
} StackD;

StackD *newStackD();

bool isEmptyD(StackD *stack);

void pushD(StackD *stack, double val);

void popD(StackD *stack);

double peekD(StackD *stack);

void freeStackD(StackD *stack);


// Long Stack
typedef struct StackL {
    long *arr;
    int top;
    int size;
} StackL;

StackL *newStackL();

bool isEmptyL(StackL *stack);

void pushL(StackL *stack, long val);

void popL(StackL *stack);

long peekL(StackL *stack);

void freeStackL(StackL *stack);

#endif //DSA_DYNAMIC_STACK_H
