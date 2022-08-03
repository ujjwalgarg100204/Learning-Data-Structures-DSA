#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 100
#define DOUBLE "double"
#define CHAR "char"

typedef char *String;

typedef struct StackChar {
    char *arr;
    int top;
} StackChar;

typedef struct StackDouble {
    double *arr;
    int top;
} StackDouble;

StackChar *newStackChar();

bool isEmptyC(StackChar *stack);

bool isFullC(StackChar *stack);

void pushC(StackChar *stack, char val);

void popC(StackChar *stack);

char peekC(StackChar *stack);

void freeStackChar(StackChar *stack);


StackChar *newStackDouble();

bool isEmptyD(StackDouble *stack);

bool isFullD(StackDouble *stack);

void pushD(StackDouble *stack, double val);

void popD(StackDouble *stack);

char peekD(StackDouble *stack);

void freeStackDouble(StackDouble *stack);

bool hasBalancedBrackets(String exp);

String infixToPostFix(String infix);

String infixToPreFix(String infix);

double evaluatePostFix(String postFix);

double evaluatePreFix(String preFix);
