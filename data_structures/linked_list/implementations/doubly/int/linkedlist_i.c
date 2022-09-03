#include <stdlib.h>
#include <stdio.h>
#include "linkedlist_i.h"
#include "../node/int/node_doubly_i.h"

struct LinkedList {
    Node *head;
};

/*
 * Inserts a new node before the specified given node
 * Will NOT work if node is NULL
 */
void insertBefore(Node *node, int data);

/*
 * Inserts a new node after the specified given node
 * Will NOT work if node is null
 */
void insertAfter(Node *node, int data);


/*
 * Removes the given node from the list
 * Will not work if given node is the head of the list
 */
void deleteNode(Node *node);

/*
 * Removes a node after the provided node
 * Will NOT work if node provided has next as NULL
 */
void deleteAt(Node *node);


/*
 * Frees all memory for all the nodes in the list and sets head of
 * list to NULL
 */
void freeAllNodes(LinkedList *list);


LinkedList *newLinkedList() {
    LinkedList *list = malloc(sizeof(LinkedList));
    list->head = NULL;

    return list;
}

void freeLinkedList(LinkedList *list) {
    freeAllNodes(list);
    free(list);
}

void freeAllNodes(LinkedList *list) {
    while (list->head != NULL) {
        Node *next = getNext(list->head);
        freeNode(list->head);
        list->head = next;
    }
}

bool addAt(LinkedList *list, int index, int element) {
    if (index == 0) {
        addFirst(list, element);
        return true;
    } else if (list->head == NULL) {
        // don't do anything to the uninitialized list
        return false;
    }

    // iterate to the node one before node
    Node *curr = list->head;
    while (index != 0 && curr != NULL) {
        curr = getNext(curr);
        index--;
    }
    if (curr == NULL) {
        // invalid index found
        return false;
    }

    // attach the node in the list
    insertBefore(curr, element);
    return true;
}

void addLast(LinkedList *list, int element) {
    // if list is initialized addLast and addFirst do the same work
    if (list->head == NULL) {
        addFirst(list, element);
        return;
    }

    Node *curr;
    for (curr = list->head; getNext(curr) != NULL; curr = getNext(curr));
    insertAfter(curr, element);
}

bool addAll(LinkedList *list, const int *arr, int lengthOfArr) {
    // if arr is null
    if (arr == NULL) {
        return false;
    }

    // make new doubly liked list from the arr
    Node *head = newNode(arr[lengthOfArr - 1]);
    for (int i = lengthOfArr - 2; i >= 0; i--) {
        Node *node = newNode(arr[i]);
        setNext(node, head);
        setPrev(head, node);
        head = node;
    }

    if (list->head == NULL) {
        list->head = head;
    }

    // iterate to the last of the list
    Node *end = list->head;
    while (getNext(end) != NULL) { end = getNext(end); }

    setNext(end, head);
    setPrev(head, end);
    return true;
}

void addFirst(LinkedList *list, int element) {
    Node *node = newNode(element);
    // initialize the list
    if (list->head == NULL) {
        list->head = node;
        return;
    }

    setNext(node, list->head);
    setPrev(list->head, node);
    list->head = node;
}

void clear(LinkedList *list) {
    freeAllNodes(list);
}

LinkedList *clone(const LinkedList *list) {
    if (list->head == NULL) { return NULL; }

    Node *head = newNode(getData(list->head));

    // iterate over the newly created head with curr ptr, and given list with listHead ptr and keeping adding data
    // given list runs out at the end of the newly created list
    for (Node *listHead = getNext(list->head), *curr = head; listHead != NULL; listHead = getNext(listHead)) {
        Node *new = newNode(getData(listHead));
        setPrev(new, curr);
        setNext(curr, new);
        curr = new;
    }

    LinkedList *cloned = newLinkedList();
    cloned->head = head;
    return cloned;
}

bool contains(const LinkedList *list, int element) {
    if (list->head == NULL) { return false; }

    for (Node *curr = list->head; curr != NULL; curr = getNext(curr)) {
        if (getData(curr) == element) { return true; }
    }
    return false;
}

int getFirst(const LinkedList *list) {
    if (list->head == NULL) { return -1; }
    return getData(list->head);
}

int getAt(const LinkedList *list, int index) {
    if (list->head == NULL) { return -1; }

    Node *curr = list->head;
    while (index != 0 && curr != NULL) {
        curr = getNext(curr);
        index--;
    }

    if (curr == NULL) {
        return -1;
    }

    return getData(curr);
}

int lastIndexOf(const LinkedList *list, int element) {
    int lastIndex = -1, i = 0;
    for (Node *curr = list->head; curr != NULL; curr = getNext(curr)) {
        if (getData(curr) == element) {
            lastIndex = i;
        }
        i++;
    }
    return lastIndex;
}

int getLast(const LinkedList *list) {
    if (list->head == NULL) { return -1; }

    Node *end = list->head;
    while (getNext(end) != NULL) { end = getNext(end); }

    return getData(end);
}

int removeFirst(LinkedList *list) {
    if (list->head == NULL) { return -1; }
    else if (getNext(list->head) == NULL) {
        // if only 1 node present in list
        int toReturn = getData(list->head);
        freeNode(list->head);
        list->head = NULL;
        return toReturn;
    }

    int toReturn = getData(list->head);
    setData(list->head, getData(getNext(list->head)));
    deleteNode(getNext(list->head));
    return toReturn;
}

int removeLast(LinkedList *list) {
    if (list->head == NULL) { return -1; }

    Node *end = list->head;
    while (getNext(end) != NULL) { end = getNext(end); }

    int rearData = getData(end);
    deleteNode(end);
    return rearData;
}

bool removeFirstOccur(LinkedList *list, int element) {
    if (list->head == NULL) { return false; }
    else if (getData(list->head) == element) {
        // found first match at the beginning of the list
        removeFirst(list);
        return false;
    }

    // if match is found in the list, delete that node from the list
    for (Node *curr = getNext(list->head); curr != NULL; curr = getNext(curr)) {
        if (getData(curr) == element) {
            deleteNode(curr);
            return true;
        }
    }
    return false;
}

int removeAt(LinkedList *list, int index) {
    if (list->head == NULL) { return -1; }

    Node *curr = list->head;
    while (index != 0 && curr != NULL) {
        curr = getNext(curr);
        index--;
    }

    if (curr == NULL) { return -1; }
    int toReturn = getData(curr);
    deleteNode(curr);
    return toReturn;
}

bool removeLastOccur(LinkedList *list, int element) {
    if (list->head == NULL) { return -1; }

    Node *iterator = list->head, *lastOccur = NULL;
    while (iterator != NULL) {
        if (getData(iterator) == element) { lastOccur = iterator; }
        iterator = getNext(iterator);
    }

    // last occurrence is head of the list, delete is specially
    if (lastOccur == list->head) { removeFirst(list); }
    else { deleteNode(lastOccur); }

    return true;
}

bool set(LinkedList *list, int index, int val) {
    if (list->head == NULL) { return false; }

    Node *curr = list->head;
    while (index != 0 && curr != NULL) {
        curr = getNext(curr);
        index--;
    }
    // invalid index
    if (curr == NULL) { return false; }

    setData(curr, val);
    return true;

}

int *toArray(const LinkedList *list) {
    if (list->head == NULL) { return NULL; }

    int length = size(list), i = 0;
    int *arr = malloc(sizeof(int) * length);
    for (Node *curr = list->head; curr != NULL; curr = getNext(curr)) {
        arr[i++] = getData(curr);
    }
    return arr;
}

void forEach(LinkedList *list, void (*lambda)(int)) {
    if (list->head == NULL) { return; }

    for (Node *curr = list->head; curr != NULL; curr = getNext(curr)) {
        lambda(getData(curr));
    }
}

int size(const LinkedList *list) {
    int len = 0;
    for (Node *curr = list->head; curr != NULL; curr = getNext(curr)) { len++; }
    return len;
}

void printList(const LinkedList *list) {
    if (list->head == NULL) {
        printf("(null)\n");
        return;
    }
    for (Node *curr = list->head; curr != NULL; curr = getNext(curr)) { printf("%d ", getData(curr)); }
    printf("\n");
}

void insertBefore(Node *node, int data) {
    if (node == NULL) { return; }

    // make node point to right pointers
    Node *new = newNode(data);
    setNext(new, node);
    setPrev(new, getPrev(node));

    // set the adjacent pointers right
    setPrev(node, new);
    setNext(getPrev(node), new);
}

void insertAfter(Node *node, int data) {
    if (node == NULL) { return; }

    // make node to right ptr
    Node *new = newNode(data);
    setPrev(new, node);
    setNext(new, getNext(node));

    // make the adjacent to right ptr
    if (getNext(node) != NULL) {
        // last node detected
        setPrev(getNext(node), new);
    }
    setNext(node, new);
}