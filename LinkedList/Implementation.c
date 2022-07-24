#include <stdio.h>
#include <stdlib.h>
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

// O(n) add opeartion
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


int main(void) {
    LinkedList *linkedList = newLinkedList(0);
    add(linkedList, 1);
    addLast(linkedList, 2);
    printf("Int at %d: %d\n", 1, getIntAt(linkedList, 1));
    deleteIntAt(linkedList, 2);
    setIntAt(linkedList, 1, 1000);
    contains(linkedList, 0) ? printf("List contains 0\n") : printf("List doesn't contain 0\n");
    isValidIndex(linkedList, 3) ? printf("3 is valid index\n") : printf("3 is invalid index");

    freeLinkedList(linkedList);
    return 0;
}

LinkedList *newLinkedList(int firstData) {
    LinkedList *linkedList = malloc(sizeof(LinkedList));
    linkedList->head = malloc(sizeof(Node));
    linkedList->head->data = firstData;
    linkedList->head->next = NULL;
    linkedList->size = 1;
    return linkedList;
}

void freeLinkedList(LinkedList *linkedList) {
    // iterate through the entire linked list freeing each node
    while (linkedList->head) {
        Node *nextToHead = linkedList->head->next;
        free(linkedList->head);
        linkedList->head = nextToHead;
    }
    free(linkedList);
}

void add(LinkedList *linkedList, int num) {
    Node *newNode = malloc(sizeof(Node));
    newNode->data = num;

    // save the value of head of LL
    newNode->next = linkedList->head;

    // direct head of list to new node
    linkedList->head = newNode;
    linkedList->size++;
}

void addLast(LinkedList *linkedList, int num) {
    Node *newNode = malloc(sizeof(Node));
    newNode->data = num;
    newNode->next = NULL;

    // put the node at the end of list
    Node *current = linkedList->head;
    while (current->next) {
        current = current->next;
    }
    // current holds the second last node
    current->next = newNode;
    linkedList->size++;
}

int getIntAt(LinkedList *linkedList, int index) {
    if (!(index >= 0 && index < linkedList->size)) {
        return -1;
    }
    Node *current = linkedList->head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }

    return current->data;
}

void deleteIntAt(LinkedList *linkedList, int index) {
    if (!(index >= 0 && index < linkedList->size))
        return;
    // FIXME: might not work for last index
    // traverse to index one less than whatever index is given
    Node *current = linkedList->head;
    while (index - 1) {
        current = current->next;
        index--;
    }

    // save a reference to node which is next to the one that is to be deleted
    Node *next = current->next->next;
    free(current->next);
    current->next = next;
    linkedList->size--;
}

void setIntAt(LinkedList *linkedList, int index, int value) {
    if (!(index >= 0 && index < linkedList->size)) {
        return;
    }

    Node *current = linkedList->head;
    while (index != 0) {
        current = current->next;
        index--;
    }

    current->data = value;
}

bool contains(LinkedList *linkedList, int value) {
    Node *current = linkedList->head;
    while (current) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }

    return false;
}

bool isValidIndex(LinkedList *linkedList, int index) {
    int size = 0;
    for (Node *current = linkedList->head; current; current = current->next) {
        size++;
    }
    return index < size;
}
