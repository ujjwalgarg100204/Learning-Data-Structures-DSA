#ifndef CODES_STATIC_ARRAY_IMPLEMENTATION_H
#define CODES_STATIC_ARRAY_IMPLEMENTATION_H

#include <stdbool.h>

#define ll long long

/*
 * Stack implementation using static array
 */
typedef struct Stack_StArr {
    ll *arr;
    int top;
    int capacity;
} Stack_StArr;

/*
 * Creates a stack which is implemented using static array
 * Stack_StArr -> Stack implemented using Static Array
 * Returns a pointer to the struct Stack_StArr
 */
Stack_StArr *newStack_StArr(int capacity);

/*
 * Returns true is stack is completely full and can't hold anymore elements
 */
bool isFull_Stack_StArr(Stack_StArr *stack);

/*
 * Adds the element to the stack
 */
bool push_Stack_StArr(Stack_StArr *stack, long long int element);

/*
 * Returns true if stack is empty, false if stack has some elements in it
 */
bool isEmpty_Stack_StArr(Stack_StArr *stack);

/*
 * Returns whatever element is at the top of stack
 * If stack is empty, then GARBAGE VALUE is returned
 */
ll getTop_Stack_StArr(Stack_StArr *stack);

/*
 * Removes the top of stack and returns its value
 * If stack is empty, then GARBAGE VALUE is returned, and no operation is
 * done on stack
 */
ll pop_Stack_StArr(Stack_StArr *stack);

/*
 * Frees the memory for stack
 */
void freeStack_StArr(Stack_StArr *stack);

/*
 * Prints elements contained in stack from top to bottom
 * Time Complexity: O(n)
 */
void print_Stack_StArr(Stack_StArr *stack);

#endif //CODES_STATIC_ARRAY_IMPLEMENTATION_H
