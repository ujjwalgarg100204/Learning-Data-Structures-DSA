#include <stdlib.h>
#include <stdio.h>
#include "doubly_ll.h"

/*
 * Frees all memory for all the nodes in the list and sets head of
 * list to NULL
 */
void freeAllNodesList_D(LinkedList_D *list) {
    while (list->head != NULL) {
        Node_D *next = list->head->next;
        free(list->head);
        list->head = next;
    }
}

void swap(ll *a, ll *b) {
    ll temp = *a;
    *a = *b;
    *b = temp;
}

/*
 * Adds a new node after the given node
 */
void addNodeAfterList_D(Node_D *node, ll element) {
    if (node == NULL) return;
    Node_D *new = newNode_D(element);
    new->next = node->next;
    new->prev = node;
    if (node->next != NULL) node->next->prev = new;
    node->next = new;
}

/*
 * Adds a new node before the given node
 * Does not do anything if node is passed as NULL
 */
void addNodeBeforeList_D(Node_D *node, ll element) {
    if (node == NULL) return;
    Node_D *new = newNode_D(element);
    new->prev = node->prev;
    new->next = node;
    if (node->prev != NULL) node->prev->next = new;
    node->prev = new;
}

/*
 * Deletes the given node from the doubly linked list
 */
void deleteNodeList_D(Node_D *node) {
    if (node == NULL) return;
    if (node->prev != NULL) node->prev->next = node->next;
    if (node->next != NULL) node->next->prev = node->prev;
    freeNode_D(node);
}

/*
 * Gives the node that occurs after given number, might return NULL
 * if after @param after < 0 then gives last node of the list
 */
Node_D *iterateToNodeAtList_D(Node_D *node, int after) {
    Node_D *curr;
    if (after < 0)
        for (curr = node; curr->next != NULL; curr = curr->next);
    else
        for (curr = node; curr != NULL && after != 1; curr = curr->next, after--);
    return curr;
}

/*
 * Creates a new Doubly linked list and returns a ptr to new list
 */
LinkedList_D *newLinkedList_D() {
    LinkedList_D *list = malloc(sizeof(LinkedList_D));
    list->head = NULL;
    return list;
}

/*
 * Frees the linked list and frees each node in the list
 * Time Complexity: O(n) operation
 * Space Complexity: O(1)
 */
void freeLinkedList_D(LinkedList_D *list) {
    freeAllNodesList_D(list);
    free(list);
}

bool addAtList_D(LinkedList_D *list, int index, long long int element) {
    if (index == 0) {
        addFirstList_D(list, element);
        return true;
    }
    Node_D *nodeAfter = iterateToNodeAtList_D(list->head, index);
    if (nodeAfter == NULL) return false;
    addNodeAfterList_D(nodeAfter, element);
    return true;
}

void addLastList_D(LinkedList_D *list, long long int element) {
    if (list->head == NULL) {
        addFirstList_D(list, element);
        return;
    }

    Node_D *last = iterateToNodeAtList_D(list->head, -1);
    addNodeAfterList_D(last, element);
}

bool addAllList_D(LinkedList_D *list, const long long int *arr, int lengthOfArr) {
    if (arr == NULL) return false;

    Node_D *curr = newNode_D(arr[0]);
    Node_D *tail = curr;
    for (int i = 1; i < lengthOfArr; i++) {
        addNodeAfterList_D(tail, arr[i]);
        tail = tail->next;
    }
    if (list->head == NULL) {
        list->head = curr;
        return true;
    }
    Node_D *lastNode = iterateToNodeAtList_D(list->head, -1);
    lastNode->next = curr;
    curr->prev = lastNode;
    return true;
}

void addFirstList_D(LinkedList_D *list, long long int element) {
    if (list->head == NULL)
        list->head = newNode_D(element);
    else {
        addNodeBeforeList_D(list->head, element);
        list->head = list->head->prev;
    }
}

void clearList_D(LinkedList_D *list) {
    freeAllNodesList_D(list);
}

LinkedList_D *cloneList_D(const LinkedList_D *list) {
    LinkedList_D *clone = newLinkedList_D();
    if (list->head == NULL)
        return clone;

    addFirstList_D(clone, list->head->data);
    Node_D *tail = clone->head;
    for (Node_D *curr = list->head->next; curr != NULL; curr = curr->next) {
        addNodeAfterList_D(tail, curr->data);
        tail = tail->next;
    }
    return clone;
}

bool containsList_D(const LinkedList_D *list, long long int element) {
    for (Node_D *curr = list->head; curr != NULL; curr = curr->next)
        if (curr->data == element) return true;
    return false;
}

ll getFirstList_D(const LinkedList_D *list) {
    return list->head == NULL ? -1 : list->head->data;
}

ll getLastList_D(const LinkedList_D *list) {
    return list->head == NULL ? -1 : iterateToNodeAtList_D(list->head, -1)->data;
}

ll getAtList_D(const LinkedList_D *list, int index) {
    if (list->head == NULL) return -1;
    Node_D *nodeAtIndex = iterateToNodeAtList_D(list->head, index + 1);
    return nodeAtIndex == NULL ? -1 : nodeAtIndex->data;
}

int lastIndexOfList_D(const LinkedList_D *list, long long int element) {
    int lastIndex = -1, i = 0;
    for (Node_D *curr = list->head; curr != NULL; curr = curr->next, i++)
        if (curr->data == element) lastIndex = i;
    return lastIndex;
}

ll removeFirstList_D(LinkedList_D *list) {
    if (list->head == NULL) return -1;
    else if (list->head->next == NULL) {
        ll toReturn = list->head->data;
        freeNode_D(list->head);
        list->head = NULL;
        return toReturn;
    }

    // swap data of head node and node after it, then delete next node
    ll toReturn = list->head->data;
    swap(&list->head->data, &list->head->next->data);
    deleteNodeList_D(list->head->next);
    return toReturn;
}

ll removeLastList_D(LinkedList_D *list) {
    if (list->head == NULL || list->head->next == NULL) return removeFirstList_D(list);

    Node_D *last = iterateToNodeAtList_D(list->head, -1);
    ll toReturn = last->data;
    deleteNodeList_D(last);
    return toReturn;
}

bool removeFirstOccurList_D(LinkedList_D *list, long long int element) {
    if (list->head == NULL) return false;
    else if (list->head->data == element) {
        removeFirstList_D(list);
        return true;
    }

    Node_D *curr;
    for (curr = list->head; curr != NULL; curr = curr->next)
        if (curr->data == element) break;
    if (curr == NULL) return false;
    deleteNodeList_D(curr);
    return true;
}

ll removeAtList_D(LinkedList_D *list, int index) {
    if (list->head == NULL) return -1;
    else if (index == 0) {
        ll toReturn = list->head->data;
        removeFirstList_D(list);
        return toReturn;
    }

    Node_D *toDelete = iterateToNodeAtList_D(list->head, index + 1);
    if (toDelete == NULL) {
        // invalid index
        return -1;
    }
    ll toReturn = toDelete->data;
    deleteNodeList_D(toDelete);
    return toReturn;
}

bool removeLastOccurList_D(LinkedList_D *list, long long int element) {
    if (list->head == NULL) return false;

    // find last occurrence
    Node_D *lastOccur = NULL;
    for (Node_D *curr = list->head; curr != NULL; curr = curr->next)
        if (curr->data == element) lastOccur = curr;

    if (lastOccur == list->head) removeFirstList_D(list);
    else deleteNodeList_D(lastOccur);
    return true;
}

bool setList_D(LinkedList_D *list, int index, long long int val) {
    Node_D *node = iterateToNodeAtList_D(list->head, index + 1);
    if (node == NULL) return false;
    node->data = val;
    return true;
}

ll *toArrayList_D(const LinkedList_D *list) {
    ll *arr = malloc(sizeof(ll) * sizeList_D(list)), i = 0;
    for (Node_D *curr = list->head; curr != NULL; curr = curr->next)
        arr[i++] = curr->data;
    return arr;
}

void forEachList_D(LinkedList_D *list, void (*lambda)(long long int)) {
    for (Node_D *curr = list->head; curr != NULL; curr = curr->next)
        lambda(curr->data);
}

int sizeList_D(const LinkedList_D *list) {
    int size = 0;
    for (Node_D *curr = list->head; curr != NULL; curr = curr->next)
        size++;
    return size;
}

void printList_D(const LinkedList_D *list) {
    if (list->head == NULL)
        printf("(null)\n");

    for (Node_D *curr = list->head; curr != NULL; curr = curr->next)
        printf("%lld ", curr->data);
}
