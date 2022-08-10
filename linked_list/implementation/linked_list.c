#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "linked_list.h"

LinkedListI *newLinkedListI(void) {
    LinkedListI *linkedList = malloc(sizeof(LinkedListI));
    linkedList->head = NULL;    // initialise the head pointer to NULL, will be initialised by add
    linkedList->length = 0;
    return linkedList;
}

void freeLinkedListI(LinkedListI *linkedList) {
    // iterate through the entire linked list freeing each node
    while (linkedList->head) {
        NodeI *nextToHead = linkedList->head->next;
        free(linkedList->head);
        linkedList->head = nextToHead;
    }
    free(linkedList);
}

void addFirstI(LinkedListI *linkedList, int num) {
    NodeI *newNode = malloc(sizeof(NodeI));
    newNode->data = num;

    // save the value of head of LL
    newNode->next = linkedList->head;

    // direct head of list to new node
    linkedList->head = newNode;
    linkedList->length++;
}

void addLastI(LinkedListI *linkedList, int num) {
    NodeI *newNode = malloc(sizeof(NodeI));
    newNode->data = num;
    newNode->next = NULL;   // since it is last node

    // put the node at the end of list
    NodeI *current = linkedList->head;
    while (current->next) {
        current = current->next;
    }
    // current holds the second last node
    current->next = newNode;
    linkedList->length++;
}

/*
 * index should be coherent with zero-indexing
 */
int getI(LinkedListI *linkedList, int index) {
    if (!isValidIndexI(linkedList, index)) {
        printf("Invalid Index");
        return -1;
    }

    NodeI *current = linkedList->head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }

    return current->data;
}

void deleteAtI(LinkedListI *linkedList, int index) {
    if (!isValidIndexI(linkedList, index)) {
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
    NodeI *current = linkedList->head;
    while (index - 1 > 0) {
        current = current->next;
        index--;
    }

    // save a reference to node which is next to the one that is to be deleted
    NodeI *next = current->next->next;
    free(current->next);
    current->next = next;
    linkedList->length--;
}

void setAtI(LinkedListI *linkedList, int index, int value) {
    if (!isValidIndexI(linkedList, index)) {
        return;
    }

    NodeI *current = linkedList->head;
    while (index != 0) {
        current = current->next;
        index--;
    }

    current->data = value;
}

bool containsI(LinkedListI *linkedList, int value) {
    NodeI *current = linkedList->head;
    // iterate through entire list and see if the value is present
    while (current) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }

    return false;
}

bool isValidIndexI(LinkedListI *linkedList, int index) {
    // if index is negative or list is empty then index not valid
    if (index < 0 || isListEmptyI(linkedList)) { return false; }

    for (NodeI *current = linkedList->head; current; current = current->next) {
        index--;
    }

    return index < 0;
}

bool isListEmptyI(LinkedListI *linkedList) {
    return linkedList->head == NULL;
}

void deleteFirstI(LinkedListI *linkedList) {
    if (isListEmptyI(linkedList)) {
        printf("List is empty\n");
        return;
    }

    NodeI *nextToHead = linkedList->head->next;
    free(linkedList->head);
    linkedList->head = nextToHead;
}


/* For String Data type*/
/*
 * Struct declarations for string
typedef struct NodeS {
    char *data;
    struct NodeS *next;
} NodeS;

typedef struct LinkedListS {
    NodeS *head;
    int length;
} LinkedListS;
*/
void freeNodeS(NodeS *node);

LinkedListS *newLinkedListS(void) {
    LinkedListS *linkedList = malloc(sizeof(LinkedListS));
    linkedList->head = NULL;    // initialise the head pointer to NULL, will be initialised by add
    linkedList->length = 0;
    return linkedList;
}

void freeLinkedListS(LinkedListS *linkedList) {
    // iterate through the entire linked list freeing each node
    while (linkedList->head) {
        NodeS *nextToHead = linkedList->head->next;
        freeNodeS(linkedList->head);
        linkedList->head = nextToHead;
    }
    free(linkedList);
}

void addFirstS(LinkedListS *linkedList, char *str) {
    NodeS *newNode = malloc(sizeof(NodeS));
    newNode->data = malloc(sizeof(char) * (strlen(str) + 1));
    strcpy(newNode->data, str);

    // save the value of head of LL
    newNode->next = linkedList->head;

    // direct head of list to new node
    linkedList->head = newNode;
    linkedList->length++;
}

void addLastS(LinkedListS *linkedList, char *str) {

    if (linkedList->head) {
        NodeS *newNode = malloc(sizeof(NodeS));
        newNode->data = malloc(sizeof(char) * (strlen(str) + 1));
        strcpy(newNode->data, str);
        newNode->next = NULL;   // since it is last node

        // put the node at the end of list
        NodeS *current = linkedList->head;
        while (current->next) {
            current = current->next;
        }

        // current holds the second last node
        current->next = newNode;
        linkedList->length++;
    } else {
        addFirstS(linkedList, str);
    }
}

/* index should be coherent with zero-indexing */
char *getS(LinkedListS *linkedList, int index) {
    if (!isValidIndexS(linkedList, index)) {
        printf("Invalid Index");
        return NULL;
    }

    NodeS *current = linkedList->head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }

    char *toReturn = malloc(sizeof(char) * (strlen(current->data) + 1));
    strcpy(toReturn, current->data);
    return toReturn;
}

void deleteAtS(LinkedListS *linkedList, int index) {
    if (!isValidIndexS(linkedList, index)) {
        printf("Invalid Index\n");
        return;
    }

    // only one element in the list
    if (linkedList->head->next == NULL) {
        freeNodeS(linkedList->head);
        linkedList->head = NULL;
        return;
    }

    // traverse to index one less than whatever index is given
    if (index != 0) {
        NodeS *current = linkedList->head;
        while (index - 1 > 0) {
            current = current->next;
            index--;
        }

        // save a reference to node which is next to the one that is to be deleted
        NodeS *next = current->next->next;
        freeNodeS(current->next);
        current->next = next;
        linkedList->length--;
    } else {
        deleteFirstS(linkedList);
    }
}

void setAtS(LinkedListS *linkedList, int index, char *str) {
    if (!isValidIndexS(linkedList, index)) {
        return;
    }

    NodeS *current = linkedList->head;
    while (index != 0) {
        current = current->next;
        index--;
    }

    free(current->data);    // free the memory for original string
    current->data = malloc(sizeof(char) * (strlen(str) + 1));
    strcpy(current->data, str);
}

bool containsS(LinkedListS *linkedList, char *str) {
    NodeS *current = linkedList->head;
    // iterate through entire list and see if the value is present
    while (current) {
        if (strcmp(current->data, str) == 0) {
            return true;
        }
        current = current->next;
    }

    return false;
}

bool isValidIndexS(LinkedListS *linkedList, int index) {
    // if index is negative or list is empty then index not valid
    if (index < 0 || isListEmptyS(linkedList)) { return false; }

    for (NodeS *current = linkedList->head; current; current = current->next) {
        index--;
    }

    return index < 0;
}

bool isListEmptyS(LinkedListS *linkedList) {
    return linkedList->head == NULL;
}

void deleteFirstS(LinkedListS *linkedList) {
    if (isListEmptyS(linkedList)) {
        printf("List is empty\n");
        return;
    }

    NodeS *nextToHead = linkedList->head->next;
    freeNodeS(linkedList->head);
    linkedList->head = nextToHead;
    linkedList->length--;
}

void deleteFirstOccur(LinkedListS *linkedList, const char *str) {
    if (isListEmptyS(linkedList)) {
        return;
    }

    // check for first element
    if (strcmp(linkedList->head->data, str) == 0) {
        NodeS *next = linkedList->head->next;
        freeNodeS(linkedList->head);
        linkedList->head = next;
        linkedList->length--;
        return;
    }


    NodeS *current = linkedList->head;
    while (current->next && strcmp(current->next->data, str) != 0) {
        current = current->next;
    }
    // found the match at current->next
    if (current->next) {
        NodeS *nextToDeletedNode = current->next->next;
        freeNodeS(current->next);
        current->next = nextToDeletedNode;
        linkedList->length--;
    }
}


void freeNodeS(NodeS *node) {
    free(node->data);
    free(node);
}
