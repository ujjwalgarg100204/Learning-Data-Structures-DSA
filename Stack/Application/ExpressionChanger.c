// Implementing Stack using dynamic array

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "DanglingPointer"
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

String infixToPostFixWithBrackets(String expression);

int higherPriority(char operator1, char operator2);

int findIndexOf(const char arr[], int size, char c);

int lengthWithoutBrackets(const char *str);

int main(void) {
    int testCases;
    scanf("%d", &testCases);

    // take expression as input
    String expression = malloc(sizeof(char) * MAX_SIZE);
    while (testCases-- > 0) {
        scanf("%s", expression);

//        String postFix = infixToPostFix(expression);
        String postFix = infixToPostFixWithBrackets(expression);
        printf("%s\n", postFix);
        free(postFix);
    }
    free(expression);
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "DanglingPointer"

String infixToPostFix(String expression) {
    Stack *operator = newStack();
    int length = strlen(expression); // NOLINT(cppcoreguidelines-narrowing-conversions)
    String result = malloc(sizeof(char) * length + 1);
    int j = 0;
    for (int i = 0; i < length; ++i) {
        // if digit found put it in result
        if (isdigit(expression[i])) {
            result[j++] = expression[i];
        } else {
            // if stack's top is an operator of more or equal priority then put the top of stack in result, and push current
            // operator in stack
            if (!isEmpty(operator) && higherPriority(poll(operator), expression[i]) >= 0) {
                while (!isEmpty(operator) && higherPriority(poll(operator), expression[i]) >= 0) {
                    result[j++] = poll(operator);
                    pop(operator);
                }
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
    result[j] = '\0';

    freeStack(operator);
    return result;
}

String infixToPostFixWithBrackets(String expression) {
    Stack *stack = newStack();

    String postFix = malloc(sizeof(char) * (lengthWithoutBrackets(expression) + 1));
    int j = 0;
    for (int i = 0; expression[i] != '\0'; i++) {
        if (isdigit(expression[i])) {
            postFix[j++] = expression[i];
        } else if (isEmpty(stack) || expression[i] == '(' || poll(stack) == '(' ||
                   higherPriority(poll(stack), expression[i]) < 0) {
            // push operator to stack in case stack is empty or top of stack is '('
            push(stack, expression[i]);
        } else if (expression[i] == ')') {
            while (poll(stack) != '(') {
                postFix[j++] = poll(stack);
                pop(stack);
            }
            pop(stack); // remove '(' from stack
        } else {
            // priority of current operator is equal to less than top of stack
//            printf("Here\n");
//            printf("poll(stack) = %c\n", poll(stack));
            while (!isEmpty(stack) && higherPriority(poll(stack), expression[i]) >= 0) {
                postFix[j++] = poll(stack);
                pop(stack);
            }
            push(stack, expression[i]);
        }
    }

    while (!isEmpty(stack)) {
        postFix[j++] = poll(stack);
        pop(stack);
    }
    freeStack(stack);

    postFix[j] = '\0';

    return postFix;
}

#pragma clang diagnostic pop

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

int lengthWithoutBrackets(const char *str) {
    int length = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == '(' || str[i] == ')') {
            continue;
        }
        length++;
    }
    return length;
}


#pragma clang diagnostic pop