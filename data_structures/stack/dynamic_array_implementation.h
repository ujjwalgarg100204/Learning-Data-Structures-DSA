#ifndef CODES_DYNAMIC_ARRAY_IMPLEMENTATION_H
#define CODES_DYNAMIC_ARRAY_IMPLEMENTATION_H

#include "../dynamic_array/array.h"

typedef struct Stack_DyArr {
    DynamicArray *arr;
    int top;
} Stack_DyArr;

Stack_DyArr *newStack_DyArr();

void push_DyArr(Stack_DyArr *stack, long long int element);

bool isEmpty_DyArr(Stack_DyArr *stack);

ll pop_DyArr(Stack_DyArr *stack);

ll getTop_DyArr(Stack_DyArr *stack);

void freeStack_DyArr(Stack_DyArr *stack);

#endif //CODES_DYNAMIC_ARRAY_IMPLEMENTATION_H
