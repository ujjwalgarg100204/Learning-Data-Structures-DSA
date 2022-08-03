#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Stack {
    int *arr;
    int size;
    int top;
} Stack;

Stack *newStack(int size);

void freeStack(Stack *stack);

int poll(Stack *stack);

void push(Stack *stack, int val);

void pop(Stack *stack);

bool isEmpty(Stack *stack);

bool isFull(Stack *stack);


void printStack(Stack *stack);

int main(void) {
    printf("Size of Stack:");
    int size;
    scanf("%d", &size);

    Stack *stack = newStack(size);

    char choice;
    do {
        printf("Stack operations\n"
               "1. push\n"
               "2. pop\n"
               "3. Top of Stack\n"
               "0. Exit\n"
               "Choice:");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                printf("Number:");
                int num;
                scanf("%d", &num);
                if (!isFull(stack)) {
                    push(stack, num);
                    printf("Pushed %d to stack\n", num);
                } else {
                    printf("Stack overflow\n");
                }
                break;
            case '2':
                if (!isEmpty(stack)) {
                    printf("%d popped\n", poll(stack));
                    pop(stack);
                } else {
                    printf("Stack Empty\n");
                }
                break;
            case '3':
                if (!isEmpty(stack)) {
                    printf("Top of stack %d\n", poll(stack));
                } else {
                    printf("Stack Empty\n");
                }
                break;
            default:
                break;
        }
        printStack(stack);
    } while (choice != '0');

    freeStack(stack);
    return 0;
}

void printStack(Stack *stack) {
    printf("\nStack:\t");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d\t", stack->arr[i]);
    }
    printf("\n");
}


Stack *newStack(int size) {
    Stack *stack = malloc(sizeof(Stack));
    stack->arr = malloc(sizeof(int) * size);
    stack->size = size;
    stack->top = -1;
}

void freeStack(Stack *stack) {
    free(stack->arr);
    free(stack);
}

int poll(Stack *stack) {
    return stack->arr[stack->top];
}

void push(Stack *stack, int val) {
    if (stack->top + 1 == stack->size) {
        printf("Stack overflow, can't add more element");
    } else {
        stack->arr[++stack->top] = val;
    }
}

void pop(Stack *stack) {
    if (stack->top == -1) {
        printf("Stack empty, can't pop");
    } else {
        stack->top--;
    }
}

bool isEmpty(Stack *stack) {
    return stack->top == -1;
}

bool isFull(Stack *stack) {
    return stack->top + 1 == stack->size;
}

