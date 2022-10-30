#ifndef CODES_STATIC_ARRAY_IMPLEMENTATION_H
#define CODES_STATIC_ARRAY_IMPLEMENTATION_H

#include <stdbool.h>

#define ll long long

typedef struct Stack_StArr {
    ll *arr;
    int top;
    int capacity;
} Stack_StArr;

Stack_StArr *newStack_StArr(int capacity);

bool isFull_StArr(Stack_StArr *stack);

bool push_StArr(Stack_StArr *stack, long long int element);

bool isEmpty_StArr(Stack_StArr *stack);

ll getTop_StArr(Stack_StArr *stack);

ll pop_StArr(Stack_StArr *stack);

void freeStack_StArr(Stack_StArr *stack);

#endif //CODES_STATIC_ARRAY_IMPLEMENTATION_H
