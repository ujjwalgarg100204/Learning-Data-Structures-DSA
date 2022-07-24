// Implementing Stack using dynamic array

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// implementing stack with array
typedef struct Stack {
    int *mainStack;
    int size;   // not zero indexed, but 1 indexed
} Stack;

// traverse the stack and print all the while emptying the stack
void printAndEmptyStack(Stack *stack);

void add(Stack *stack, int num);

// see the element to be popped next
int poll(Stack *stack);

// returns true if able to pop the element else returns false
bool pop(Stack *stack);

// initializes stack with 1 number
Stack *newStack(int firstElement);

void freeStack(Stack *stack);

int main(void) {
    Stack *stack = newStack(1);
    add(stack, 2);
    add(stack, 3);
    add(stack, 4);
    add(stack, 5);
    add(stack, 6);

    printAndEmptyStack(stack);

    freeStack(stack);
}

void add(Stack *stack, int num) {
    // allocate and store the new number to stack
    stack->mainStack = realloc(stack->mainStack, (stack->size + 1) * sizeof(int));
    stack->mainStack[stack->size] = num;
    stack->size++;
}

bool pop(Stack *stack) {
    if (stack->size > 0) {
        stack->mainStack = realloc(stack->mainStack, (stack->size - 1) * sizeof(int));
        stack->size--;
        return true;
    }
    return false;
}

void freeStack(Stack *stack) {
    if (stack->mainStack) { free(stack->mainStack); }
    free(stack);
}

Stack *newStack(int firstElement) {
    Stack *stack = malloc(sizeof(Stack));
    stack->mainStack = malloc(sizeof(int));
    stack->mainStack[0] = firstElement;
    stack->size = 1;
    return stack;
}

void printAndEmptyStack(Stack *stack) {
    while (stack->size) {
        printf("%d ", poll(stack));
        if (!pop(stack)) { printf("\nError occurred.\n"); }
    }
    printf("\n");
    stack->mainStack = NULL;
}

int poll(Stack *stack) {
    if (stack->size != 0) {
        return stack->mainStack[stack->size - 1];
    }
    // although it can be a number in a stack I don't know what else
    // to return, maybe a custom struct that has error attribute
    // and answer
    return -1;
}


