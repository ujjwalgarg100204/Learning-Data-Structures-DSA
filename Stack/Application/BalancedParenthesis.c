// Implementing Stack using dynamic array

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

// implementing stack with array
typedef struct Stack {
    char *mainStack;
    int size;   // not zero indexed, but 1 indexed
} Stack;

typedef char *String;


void push(Stack *stack, char c);

// see the element to be popped next
char poll(Stack *stack);

// returns true if able to pop the element else returns false
bool pop(Stack *stack);

// initializes stack with 1 number
Stack *newStack();

void freeStack(Stack *stack);

bool hasBalancedBrackets(String expression);

bool isEmpty(Stack *stack);

int main(void) {
    // take expression as input
    String expression = malloc(sizeof(char) * MAX_SIZE);
    fgets(expression, MAX_SIZE, stdin);

    if (hasBalancedBrackets(expression)) {
        printf("The given expression has balanced brackets.");
    } else {
        printf("This given expression does not have balanced brackets.");
    }

    free(expression);
}

bool hasBalancedBrackets(String expression) {
    Stack *tokens = newStack();
    int length = strlen(expression);

    for (int i = 0; i < length; i++) {
        // if opening bracket, then push to stack
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[') {
            push(tokens, expression[i]);
        } else if (expression[i] == ')') {
            // if closing bracket
            if (poll(tokens) != '(') {
                freeStack(tokens);
                return false;
            } else {
                pop(tokens);
            }
        } else if (expression[i] == '}') {
            if (poll(tokens) != '{') {
                freeStack(tokens);
                return false;
            } else {
                pop(tokens);
            }
        } else if (expression[i] == ']') {
            if (poll(tokens) != '[') {
                freeStack(tokens);
                return false;
            } else {
                pop(tokens);
            }
        }
    }
    // if stack is not empty then brackets not balanced
    if (!isEmpty(tokens)) {
        freeStack(tokens);
        return false;
    }

    freeStack(tokens);
    return true;
}

void push(Stack *stack, char c) {
    // allocate and store the new number to stack
    stack->mainStack = realloc(stack->mainStack, (stack->size + 1) * sizeof(char));
    stack->mainStack[stack->size] = c;
    stack->size++;
}

bool pop(Stack *stack) {
    if (stack->size > 0) {
        stack->mainStack = realloc(stack->mainStack, (stack->size - 1) * sizeof(char));
        stack->size--;
        return true;
    }
    return false;
}

void freeStack(Stack *stack) {
    if (stack->mainStack) { free(stack->mainStack); }
    free(stack);
}

Stack *newStack() {
    Stack *stack = malloc(sizeof(Stack));
    stack->mainStack = malloc(sizeof(char));
    stack->size = 0;
    return stack;
}

char poll(Stack *stack) {
    if (stack->size != 0) {
        return stack->mainStack[stack->size - 1];
    }
    return -1;
}

bool isEmpty(Stack *stack) {
    return stack->size == 0;
}


