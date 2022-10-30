#ifndef CODES_DYNAMIC_ARRAY_IMPLEMENTATION_H
#define CODES_DYNAMIC_ARRAY_IMPLEMENTATION_H

#include "../dynamic_array/array.h"

/*
 * Stack implementation using dynamic array
 */
typedef struct Stack_DyArr {
    DynamicArray *arr;
    int top;
} Stack_DyArr;

/*
 * Creates a stack which is implemented using dynamic array
 * Stack_StArr -> Stack implemented using Dynamic Array
 * Returns a pointer to the struct Stack_DyArr
 */
Stack_DyArr *newStack_DyArr();

/*
 * Adds the element to the stack
 */
void push_Stack_DyArr(Stack_DyArr *stack, long long int element);

/*
 * Returns true if stack is empty, false if stack has some elements in it
 */
bool isEmpty_Stack_DyArr(Stack_DyArr *stack);

/*
 * Removes the top of stack and returns its value
 * If stack is empty, then GARBAGE VALUE is returned, and no operation is
 * done on stack
 */
ll pop_Stack_DyArr(Stack_DyArr *stack);

/*
 * Returns whatever element is at the top of stack
 * If stack is empty, then GARBAGE VALUE is returned
 */
ll getTop_Stack_DyArr(Stack_DyArr *stack);

/*
 * Frees the memory for stack
 */
void freeStack_DyArr(Stack_DyArr *stack);

/*
 * Prints elements contained in stack from top to bottom
 * Time Complexity: O(n)
 */
void print_Stack_DyArr(Stack_DyArr *stack);

#endif //CODES_DYNAMIC_ARRAY_IMPLEMENTATION_H
