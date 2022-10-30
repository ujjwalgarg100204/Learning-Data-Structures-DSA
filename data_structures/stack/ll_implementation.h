#ifndef CODES_LL_IMPLEMENTATION_H
#define CODES_LL_IMPLEMENTATION_H

#include "../linked_list/singly/singly_ll.h"

/*
 * Stack implementation using singly linked list
 */
typedef struct Stack_List_S {
    LinkedList_S *list;
} Stack_List_S;


/*
 * Creates a stack which is implemented using singly linked list
 * Stack_List_S -> Stack implemented using Singly Linked List S->Singly
 * Returns a pointer to the struct Stack_List_S
 */
Stack_List_S *newStack_List_S();

/*
 * Adds the element to the stack
 * Time Complexity: O(1)
 */
void push_Stack_List_S(Stack_List_S *stack, ll element);

/*
 * Returns true if stack is empty, false if stack has some elements in it
 * Time Complexity: O(1)
 */
bool isEmpty_Stack_List_S(Stack_List_S *stack);

/*
 * Removes the top of stack and returns its value
 * If stack is empty, then GARBAGE VALUE is returned, and no operation is
 * done on stack
 * Time Complexity: O(1)
 */
ll pop_Stack_List_S(Stack_List_S *stack);

/*
 * Returns whatever element is at the top of stack
 * If stack is empty, then GARBAGE VALUE is returned
 * Time Complexity: O(1)
 */
ll getTop_Stack_List_S(Stack_List_S *stack);

/*
 * Frees the memory for stack
 * Time Complexity: O(n)
 */
void freeStack_List_S(Stack_List_S *stack);

/*
 * Prints elements contained in stack from top to bottom
 * Time Complexity: O(n)
 */
void print_Stack_List_S(Stack_List_S *stack);

#endif //CODES_LL_IMPLEMENTATION_H
