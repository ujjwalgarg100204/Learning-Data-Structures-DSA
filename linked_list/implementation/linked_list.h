#ifndef DSA1_LINKED_LIST_H
#define DSA1_LINKED_LIST_H

#include <stdbool.h>

typedef struct NodeI {
    int data;
    struct NodeI *next;
} NodeI;

// wrapper struct for NodeI
typedef struct LinkedListI {
    NodeI *head;
    int length;
} LinkedListI;

LinkedListI *newLinkedListI(void);

void freeLinkedListI(LinkedListI *linkedList);

// O(1) add operation
void addFirstI(LinkedListI *linkedList, int num);

// O(n) add operation
void addLastI(LinkedListI *linkedList, int num);

// returns -1 if index is invalid
int getI(LinkedListI *linkedList, int index);

// O(1) operation
void deleteFirstI(LinkedListI *linkedList);

// O(n) operation
void deleteAtI(LinkedListI *linkedList, int index);

// O(n) operation
void setAtI(LinkedListI *linkedList, int index, int value);

// O(n) operation
bool containsI(LinkedListI *linkedList, int value);

// O(n) operation
bool isValidIndexI(LinkedListI *linkedList, int index);

bool isListEmptyI(LinkedListI *linkedList);


/* For String datatype */
typedef struct NodeS {
    char *data;
    struct NodeS *next;
} NodeS;

typedef struct LinkedListS {
    NodeS *head;
    int length;
} LinkedListS;

LinkedListS *newLinkedListS(void);

void freeLinkedListS(LinkedListS *linkedList);

// O(1) add operation
void addFirstS(LinkedListS *linkedList, char *str);

// O(n) add operation
void addLastS(LinkedListS *linkedList, char *str);

// returns -1 if index is invalid
char *getS(LinkedListS *linkedList, int index);

// O(1) operation
void deleteFirstS(LinkedListS *linkedList);

// O(n) operation
void deleteAtS(LinkedListS *linkedList, int index);

void deleteFirstOccur(LinkedListS *linkedList, const char *str);

// O(n) operation
void setAtS(LinkedListS *linkedList, int index, char *str);

// O(n) operation
bool containsS(LinkedListS *linkedList, char *str);

// O(n) operation
bool isValidIndexS(LinkedListS *linkedList, int index);

bool isListEmptyS(LinkedListS *linkedList);


#endif //DSA1_LINKED_LIST_H
