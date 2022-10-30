#include <stdlib.h>
#include <stdio.h>
#include "doubly_circular_ll.h"

/* Helper Functions */

/*
 * Frees all memory for all the nodes in the list and sets head of
 * list to NULL
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
void freeAllNodesList_DC(LinkedList_D *list) {
    if (list->head == NULL) return;

    Node_D *curr = list->head;
    do {
        Node_D *next = curr->next;
        freeNode_D(curr);
        curr = next;
    } while (curr != list->head);
}

/*
 * Swaps values of two long integers
 */
void swap(ll *a, ll *b) {
    ll temp = *a;
    *a = *b;
    *b = temp;
}

/*
 * Adds a new node after the given node
 * Does not do anything if node is passed as NULL
 */
void addNodeAfterList_DC(Node_D *node, ll element) {
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
void addNodeBeforeList_DC(Node_D *node, ll element) {
    if (node == NULL) return;

    Node_D *new = newNode_D(element);
    new->prev = node->prev;
    new->next = node;
    node->prev->next = new; // cuz in circular dll, no pointer is NULL
    node->prev = new;
}

/*
 * Deletes the given node from the doubly linked list
 * Does not do anything if node is passed as NULL
 */
void deleteNodeList_DC(Node_D *node) {
    if (node == NULL) return;
    node->prev->next = node->next;
    node->next->prev = node->prev;
    freeNode_D(node);
}

/*
 * Gives the node that occurs after given number, might return NULL
 * if after @param after < 0 then gives last node of the list
 */
Node_D *iterateToNodeAtList_DC(Node_D *node, int after) {
    Node_D *curr = node;
    for (int i = 0; i < after; i++) curr = curr->next;
    return curr;
}


/* Main functions offered by Doubly Circular Linked List*/

/*
 * Creates a new Doubly Circular linked list and returns a ptr to new list
 */
LinkedList_D *newLinkedList_DC() {
    LinkedList_D *list = malloc(sizeof(LinkedList_D));
    list->head = NULL;
    return list;
}

/*
 * Frees the linked list and frees each node in the list
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
void freeLinkedList_DC(LinkedList_D *list) {
    freeAllNodesList_DC(list);
    free(list);
}

/*
 * Adds element at the specified index
 * Returns true if addition of new element is successful else false
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
bool addAtList_DC(LinkedList_D *list, int index, ll element) {
    if (index == 0) {
        addFirstList_DC(list, element);
        return true;
    }

    // iterate to req node
    Node_D *nodeAfter = list->head;
    do {
        nodeAfter = nodeAfter->next;
        index--;
    } while (nodeAfter != list->head && index != 0);
    if (nodeAfter == list->head) {
        // invalid index found
        return false;
    }
    addNodeAfterList_DC(nodeAfter, element);
    return true;
}

/*
 * Adds element at the last of the list
 * Can be used to initialize the list
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
void addLastList_DC(LinkedList_D *list, long long int element) {
    if (list->head == NULL) {
        addFirstList_DC(list, element);
        return;
    }
    addNodeBeforeList_DC(list->head, element);
}

/*
 * Adds all the elements of the array to the linked list, in the same order as they
 * occur
 * Returns true if addition is successful else false
 * Time Complexity: O(m+n)
 * Space Complexity: O(1)
 */
bool addAllList_DC(LinkedList_D *list, const long long int *arr, int lengthOfArr) {
    if (arr == NULL) return false;

    Node_D *head = newNode_D(arr[0]);
    Node_D *tail = head;
    for (int i = 1; i < lengthOfArr; i++) {
        addNodeAfterList_DC(tail, arr[i]);
        tail = tail->next;
    }
    tail->next = head;
    head->prev = tail;

    if (list->head == NULL) {
        list->head = head;
    } else {
        Node_D *last = list->head->prev;
        last->next = head;
        head->prev = last;
        tail->next = list->head;
        list->head->prev = tail;
    }
    return true;
}

/*
 * Adds element at the first position of the list
 * Can be used to initialize the list
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
void addFirstList_DC(LinkedList_D *list, long long int element) {
    if (list->head == NULL) {
        // empty list
        list->head = newNode_D(element);
        list->head->next = list->head;
        list->head->prev = list->head;
        return;
    }

    addNodeAfterList_DC(list->head, element);
    swap(&list->head->data, &list->head->next->data);
}

/*
 * Empties the list
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
void clearList_DC(LinkedList_D *list) {
    freeAllNodesList_DC(list);
    list->head = NULL;
}

/*
 * Creates a copy of the list passed and returns the new copy of list
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
LinkedList_D *cloneList_DC(const LinkedList_D *list) {
    if (list->head == NULL) return NULL;

    LinkedList_D *clone = newLinkedList_DC();
    clone->head = newNode_D(list->head->data);
    Node_D *tail = clone->head;

    Node_D *listHead = list->head;
    do {
        listHead = listHead->next;
        addNodeAfterList_DC(tail, listHead->data);
        tail = tail->next;
    } while (listHead != list->head);
    tail->next = clone->head;
    clone->head->prev = tail;
    return clone;
}

/*
 * Returns true if element is present in list else false
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
bool containsList_DC(const LinkedList_D *list, long long int element) {
    Node_D *curr = list->head;
    do {
        if (curr->data == element) return true;
        curr = curr->next;
    } while (curr != list->head);
    return false;
}

/*
 * Returns element present at first position
 * NOTE: If list is uninitialized, GARBAGE VALUE is returned
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
ll getFirstList_DC(const LinkedList_D *list) {
    if (list->head == NULL) return -1;
    return list->head->data;
}

/*
 * Returns last element present at last position of the list
 * NOTE: If list is uninitialized, GARBAGE VALUE is returned
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
ll getLastList_DC(const LinkedList_D *list) {
    if (list->head == NULL) return -1;
    return list->head->prev->data;
}

/*
 * Returns element present at the specified index
 * NOTE: If list is uninitialized or index passed is invalid, GARBAGE VALUE is returned
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
ll getAtList_DC(const LinkedList_D *list, int index) {
    if (index == 0) return getFirstList_DC(list);
    else if (list->head == NULL) return -1;

    Node_D *curr = list->head;
    do {
        curr = curr->next;
        index--;
    } while (curr != list->head && index != 0);
    return curr != list->head ? curr->data : -1;
}

/*
 * Returns the last index at which specified element is present
 * -1 is returned if element is not present in the list or if the list is
 * uninitialized
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int lastIndexOfList_DC(const LinkedList_D *list, long long int element) {
    if (list->head == NULL) {
        return -1;
    }

    int lastIndex = -1;
    int i = 0;
    Node_D *curr = list->head;
    do {
        if (curr->data == element) lastIndex = i;
        curr = curr->next;
        i++;
    } while (curr != list->head);

    return lastIndex;
}

/*
 * Removes the first element from the list and returns the element
 * NOTE: A GARBAGE VALUE is returned if list is uninitialized
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
ll removeFirstList_DC(LinkedList_D *list) {
    if (list->head == NULL) return -1;
    else if (list->head == list->head->next) {
        // only 1 node in linked list
        ll toReturn = list->head->data;
        freeNode_D(list->head);
        list->head = NULL;
        return toReturn;
    }
    ll toReturn = list->head->data;
    swap(&list->head->data, &list->head->next->data);
    deleteNodeList_DC(list->head->next);
    return toReturn;
}

/*
 * Removes the last element from the list and returns the element
 * NOTE: A GARBAGE VALUE is returned if list is  uninitialized
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
ll removeLastList_DC(LinkedList_D *list) {
    if (list->head == NULL) return -1;
    else if (list->head == list->head->next) return removeFirstList_DC(list);

    ll toReturn = list->head->prev->data;
    deleteNodeList_DC(list->head->prev);
    return toReturn;
}

/*
 * Removes first occurrence of the element in list, and returns true if successful
 * if the element is not present in the list, then returns false
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
bool removeFirstOccurList_DC(LinkedList_D *list, long long int element) {
    if (list->head == NULL) return -1;
    else if (list->head->data == element) {
        removeFirstList_DC(list);
        return true;
    }

    Node_D *curr = list->head;
    do {
        if (curr->data == element) break;
        curr = curr->next;
    } while (curr != list->head);

    if (curr == list->head) return false;   // element not found
    deleteNodeList_DC(curr);
    return true;
}

/*
 * Remove element at the given index and returns the element
 * If index is invalid garbage value is returned
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
ll removeAtList_DC(LinkedList_D *list, int index) {
    if (list->head == NULL) return -1;
    else if (index == 0) return removeFirstList_DC(list);

    Node_D *curr = list->head;
    do {
        curr = curr->next;
        index--;
    } while (curr != list->head && index != 0);

    if (curr == list->head) return -1;
    ll toReturn = curr->data;
    deleteNodeList_DC(curr);
    return toReturn;
}

/*
 * Removes the last Occurrence of the element in list, and returns the element
 * If the element is not present in the list, then a GARBAGE VALUE other than the element
 * is returned
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
bool removeLastOccurList_DC(LinkedList_D *list, long long int element) {
    if (list->head == NULL) return false;

    // find last occurrence
    Node_D *lastOccur = NULL, *curr = list->head;
    do {
        if (curr->data == element)
            lastOccur = curr;
        curr = curr->next;
    } while (curr != list->head);

    if (lastOccur == NULL) return false;
    else if (lastOccur == list->head) removeFirstList_DC(list);
    else deleteNodeList_DC(lastOccur);
    return true;
}

/*
 * Sets element at given index, to provided value
 * Returns true if operation of setting is successful else false
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
bool setList_DC(LinkedList_D *list, int index, long long int val) {
    if (list->head == NULL) return false;

    // go to the index
    Node_D *curr = list->head;
    do {
        curr = curr->next;
        index--;
    } while (curr != list->head && index != 0);

    if (curr == list->head) return false;   // invalid index
    curr->data = val;
    return true;
}

/*
 * Converts the Linked List to array and returns ptr to it
 * If list is uninitialized NULL is returned
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
ll *toArrayList_DC(const LinkedList_D *list) {
    if (list->head == NULL) return NULL;

    ll *arr = malloc(sizeof(ll) * sizeList_DC(list));
    int i = 0;
    Node_D *curr = list->head;
    do {
        arr[i++] = curr->data;
        curr = curr->next;
    } while (curr != list->head);
    return arr;
}

/*
 * Calls the passed function for each element in the list
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
void forEachList_DC(LinkedList_D *list, void (*lambda)(long long int)) {
    if (list == NULL) return;
    Node_D *curr = list->head;
    do {
        lambda(curr->data);
        curr = curr->next;
    } while (curr != list->head);
}

/*
 * Returns size of the linked list
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int sizeList_DC(const LinkedList_D *list) {
    int length = 0;
    Node_D *curr = list->head;
    do {
        length++;
        curr = curr->next;
    } while (curr != list->head);

    return length;
}

/*
 * Prints the list in same line separated by space
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
void printList_DC(const LinkedList_D *list) {
    if (list->head == NULL) {
        printf("(null)");
        return;
    }

    Node_D *curr = list->head;
    do {
        printf("%lld ", curr->data);
        curr = curr->next;
    } while (curr != list->head);
}

/*
 * Returns true if list is empty ,ie, head is NULL or not
 * Time Complexity: O(1)
 */
bool isEmptyList_DC(LinkedList_D *list) {
    return list->head == NULL;
}

