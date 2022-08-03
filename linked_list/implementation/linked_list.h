#ifndef DSA1_LINKED_LIST_H
#define DSA1_LINKED_LIST_H

#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

// wrapper struct for Node
typedef struct LinkedList {
    Node *head;
    int size;
} LinkedList;

LinkedList *newLinkedList(int firstData);

void freeLinkedList(LinkedList *linkedList);

// O(1) add operation
void add(LinkedList *linkedList, int num);

// O(n) add operation
void addLast(LinkedList *linkedList, int num);

// returns -1 if index is invalid
int getIntAt(LinkedList *linkedList, int index);

// O(n) operation
void deleteIntAt(LinkedList *linkedList, int index);

// O(n) operation
void setIntAt(LinkedList *linkedList, int index, int value);

// O(n) operation
bool contains(LinkedList *linkedList, int value);

// O(n) operation
bool isValidIndex(LinkedList *linkedList, int index);


#endif //DSA1_LINKED_LIST_H
