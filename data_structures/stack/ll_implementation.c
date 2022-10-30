#include <stdlib.h>
#include "ll_implementation.h"

/*
 * Creates a stack which is implemented using singly linked list
 * Stack_List_S -> Stack implemented using Singly Linked List S->Singly
 * Returns a pointer to the struct Stack_List_S
 */
Stack_List_S *newStack_List_S() {
    Stack_List_S *stack = malloc(sizeof(Stack_List_S));
    stack->list = newSinglyLinkedList_S();
    return stack;
}

/*
 * Adds the element to the stack
 * Time Complexity: O(1)
 */
void push_Stack_List_S(Stack_List_S *stack, long long int element) {
    addFirstList_S(stack->list, element);
}

/*
 * Returns true if stack is empty, false if stack has some elements in it
 * Time Complexity: O(1)
 */
bool isEmpty_Stack_List_S(Stack_List_S *stack) {
    return isEmptyList_S(stack->list);
}

/*
 * Removes the top of stack and returns its value
 * If stack is empty, then GARBAGE VALUE is returned, and no operation is
 * done on stack
 * Time Complexity: O(1)
 */
ll pop_Stack_List_S(Stack_List_S *stack) {
    return removeFirstList_S(stack->list);
}

/*
 * Returns whatever element is at the top of stack
 * If stack is empty, then GARBAGE VALUE is returned
 * Time Complexity: O(1)
 */
ll getTop_Stack_List_S(Stack_List_S *stack) {
    return getFirstList_S(stack->list);
}

/*
 * Frees the memory for stack
 * Time Complexity: O(n)
 */
void freeStack_List_S(Stack_List_S *stack) {
    freeLinkedList_S(stack->list);
    free(stack);
}

/*
 * Prints elements contained in stack from top to bottom
 * Time Complexity: O(n)
 */
void print_Stack_List_S(Stack_List_S *stack) {
    printList_S(stack->list);
}


