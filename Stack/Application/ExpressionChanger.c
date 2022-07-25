// Implementing Stack using dynamic array

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

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

bool isEmpty(Stack *stack);

String infixToPostFix(String expression);

int higherPriority(char operator1, char operator2);

int findIndexOf(const char arr[], int size, char c);

int main(void) {
    int testCases;
    scanf("%d", &testCases);

    // take expression as input
    String expression = malloc(sizeof(char) * MAX_SIZE);
    while (testCases-- > 0) {
        scanf("%s", expression);

        String postFix = infixToPostFix(expression);
        printf("%s\n", postFix);
        free(postFix);
    }
    free(expression);
}

String infixToPostFix(String expression) {
    Stack *operator = newStack();
    int length = strlen(expression);
    String result = malloc(sizeof(char) * length);
    int j = 0;
    for (int i = 0; i < length; ++i) {
        // if digit found put it in result
        if (isdigit(expression[i])) {
            result[j++] = expression[i];
        } else {
            // if stack's top is an operator of more or equal priority then put the top of stack in result, and push current
            // operator in stack
            if (!isEmpty(operator) && higherPriority(poll(operator), expression[i]) >= 0) {
                result[j++] = poll(operator);
                pop(operator);
                push(operator, expression[i]);
            } else {
                push(operator, expression[i]);
            }
        }
    }

    while (!isEmpty(operator)) {
        result[j++] = poll(operator);
        pop(operator);
    }
//    result[j] = '\0';

    freeStack(operator);
    return result;
}

int higherPriority(char operator1, char operator2) {
    char priorityOfOperator[] = {'-', '+', '*', '/', '^'};
    // special case
    if ((operator1 == '+' && operator2 == '-') || (operator1 == '*' && operator2 == '/') ||
        (operator1 == '-' && operator2 == '+') || (operator1 == '/' && operator2 == '*')) {
        return 0;
    }

    int indexOperator1 = findIndexOf(priorityOfOperator, 5, operator1);
    int indexOperator2 = findIndexOf(priorityOfOperator, 5, operator2);

    if (indexOperator1 > indexOperator2) return 1;
    else if (indexOperator1 == indexOperator2) return 0;
    else return -1;
}

int findIndexOf(const char arr[], int size, char c) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == c)
            return i;
    }
    return -1;
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


