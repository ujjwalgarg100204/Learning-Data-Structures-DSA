#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "linked_list.h"

LinkedList *newLinkedList(void) {
    LinkedList *linkedList = malloc(sizeof(LinkedList));
    linkedList->head = NULL;    // initialise the head pointer to NULL, will be initialised by add
    linkedList->currSize = 0;
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

void addFirst(LinkedList *linkedList, int num) {
    Node *newNode = malloc(sizeof(Node));
    newNode->data = num;

    // save the value of head of LL
    newNode->next = linkedList->head;

    // direct head of list to new node
    linkedList->head = newNode;
    linkedList->currSize++;
}

void addLast(LinkedList *linkedList, int num) {
    Node *newNode = malloc(sizeof(Node));
    newNode->data = num;
    newNode->next = NULL;   // since it is last node

    // put the node at the end of list
    Node *current = linkedList->head;
    while (current->next) {
        current = current->next;
    }
    // current holds the second last node
    current->next = newNode;
    linkedList->currSize++;
}

/*
 * index should be coherent with zero-indexing
 */
int getIntAt(LinkedList *linkedList, int index) {
    if (!isValidIndex(linkedList, index)) {
        printf("Invalid Index");
        return -1;
    }

    Node *current = linkedList->head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }

    return current->data;
}

void deleteIntAt(LinkedList *linkedList, int index) {
    if (!isValidIndex(linkedList, index)) {
        printf("Invalid Index\n");
        return;
    }

    // only one element in the list
    if (linkedList->head->next == NULL) {
        free(linkedList->head);
        linkedList->head = NULL;
        return;
    }

    // traverse to index one less than whatever index is given
    Node *current = linkedList->head;
    while (index - 1 > 0) {
        current = current->next;
        index--;
    }

    // save a reference to node which is next to the one that is to be deleted
    Node *next = current->next->next;
    free(current->next);
    current->next = next;
    linkedList->currSize--;
}

void setIntAt(LinkedList *linkedList, int index, int value) {
    if (!isValidIndex(linkedList, index)) {
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
    // iterate through entire list and see if the value is present
    while (current) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }

    return false;
}

bool isValidIndex(LinkedList *linkedList, int index) {
    // if index is negative or list is empty then index not valid
    if (index < 0 || isListEmpty(linkedList)) { return false; }

    for (Node *current = linkedList->head; current; current = current->next) {
        index--;
    }

    return index < 0;
}

bool isListEmpty(LinkedList *linkedList) {
    return linkedList->head == NULL;
}

void deleteFirst(LinkedList *linkedList) {
    if (isListEmpty(linkedList)) {
        printf("List is empty\n");
        return;
    }

    Node *nextToHead = linkedList->head->next;
    free(linkedList->head);
    linkedList->head = nextToHead;
}
