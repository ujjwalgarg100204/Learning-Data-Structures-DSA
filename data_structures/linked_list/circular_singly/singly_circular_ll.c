#include <stdlib.h>
#include <stdio.h>
#include "singly_circular_ll.h"

/* Helper Functions */

/*
 * Swaps values of two long integers
 */
void swap(long long int *a, long long int *b) {
    ll temp = *a;
    *a = *b;
    *b = temp;
}

/*
 * Adds a new node after the given node
 * Does not do anything if node is passed as NULL
 */
void insertAfter(Node_S *node, ll data) {
    if (node == NULL) return;
    Node_S *new = newNode_S(data);
    new->next = node->next;
    node->next = new;
}

/*
 * Deletes the given node from the doubly linked list
 */
void deleteAfter(Node_S *node) {
    if (node == NULL || node->next == NULL) return;
    Node_S *toBeDeleted = node->next;
    node->next = toBeDeleted->next;
    freeNode_S(toBeDeleted);
}

/*
 * Frees all memory for all the nodes in the list and sets head of
 * list to NULL
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
void freeAllNodesList_SC(LinkedList_S *list) {
    Node_S *curr = list->head;
    do {
        Node_S *next = curr->next;
        freeNode_S(curr);
        curr = next;
    } while (curr != list->head);
    list->head = NULL;
}

/* Main Functions of Singly Circular Linked List */

/*
 * Creates a new Singly Circular linked list and returns a ptr to new list
 */
LinkedList_S *newSinglyLinkedList_SC() {
    LinkedList_S *list = malloc(sizeof(LinkedList_S));
    list->head = NULL;
    return list;
}

/*
 * Frees the linked list and frees each node in the list
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
void freeLinkedList_SC(LinkedList_S *list) {
    freeAllNodesList_SC(list);
    free(list);
}

/*
 * Adds element at the specified index
 * Returns true if addition of new element is successful else false
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
bool addAtList_SC(LinkedList_S *list, int index, long long int element) {
    if (list->head == NULL && index != 0) return false;
    else if (index == 0) {
        addFirstList_SC(list, element);
        return true;
    } else if (index == 1) {
        insertAfter(list->head, element);
        return true;
    }

    // iterate to right position
    Node_S *curr = list->head;
    do {
        curr = curr->next;
        index--;
    } while (curr != list->head && index != 1);

    if (curr == list->head) {
        // wrong index provided
        return false;
    }
    insertAfter(curr, element);
    return true;
}

/*
 * Adds element at the last of the list
 * Can be used to initialize the list
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
void addLastList_SC(LinkedList_S *list, long long int element) {
    if (list->head == NULL) {
        addFirstList_SC(list, element);
        return;
    } else if (list->head == list->head->next) {
        insertAfter(list->head, element);
        return;
    }

    addFirstList_SC(list, element);
    list->head = list->head->next;
}

/*
 * Adds all the elements of the array to the linked list, in the same order as they
 * occur
 * Returns true if addition is successful else false
 * Time Complexity: O(m+n)
 * Space Complexity: O(1)
 */
bool addAllList_SC(LinkedList_S *list, const long long int *arr, int lengthOfArr) {
    if (arr == NULL) return false;

    // make a linked list
    Node_S *head = newNode_S(arr[0]);
    Node_S *tail = head;
    for (int i = 1; i < lengthOfArr; i++) {
        insertAfter(tail, arr[i]);
        tail = tail->next;
    }
    tail->next = list->head;    // satisfy the circular ll property

    // if list is empty
    if (list->head == NULL) {
        tail->next = head;
        list->head = head;
        return true;
    }
    // iterate to last of list
    Node_S *curr;
    for (curr = list->head; curr->next != list->head; curr = curr->next);

    // add the newly ll to main ll
    curr->next = head;
    return true;
}

/*
 * Adds element at the first position of the list
 * Can be used to initialize the list
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
void addFirstList_SC(LinkedList_S *list, long long int element) {
    if (list->head == NULL) {
        Node_S *new = newNode_S(element);
        new->next = new;
        list->head = new;
        return;
    }

    insertAfter(list->head, element);
    swap(&list->head->data, &list->head->next->data);
}

/*
 * Empties the list
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
void clearList_SC(LinkedList_S *list) {
    freeAllNodesList_SC(list);
    list->head = NULL;
}

/*
 * Creates a copy of the list passed and returns the new copy of list
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
LinkedList_S *cloneList_SC(const LinkedList_S *list) {
    LinkedList_S *clone = newSinglyLinkedList_SC();
    clone->head = newNode_S(list->head->data);
    Node_S *tail = clone->head;

    for (Node_S *listHead = list->head->next; listHead != list->head; listHead = listHead->next) {
        insertAfter(tail, listHead->data);
        tail = tail->next;
    }
    tail->next = clone->head;
    return clone;
}

/*
 * Returns true if element is present in list else false
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
bool containsList_SC(const LinkedList_S *list, long long int element) {
    Node_S *curr = list->head;
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
ll getFirstList_SC(const LinkedList_S *list) {
    if (list->head == NULL) return -1;
    return list->head->data;
}

/*
 * Returns last element present at last position of the list
 * NOTE: If list is uninitialized, GARBAGE VALUE is returned
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
ll getLastList_SC(const LinkedList_S *list) {
    if (list->head == NULL) return -1;
    Node_S *curr;
    for (curr = list->head; curr->next != list->head; curr = curr->next);
    return curr->data;
}

/*
 * Returns element present at the specified index
 * NOTE: If list is uninitialized or index passed is invalid, GARBAGE VALUE is returned
 * Time Complexity: O(index)
 * Space Complexity: O(1)
 */
ll getAtList_SC(const LinkedList_S *list, int index) {
    if (list->head == NULL) return -1;
    Node_S *curr = list->head;
    do {
        curr = curr->next;
        index--;
    } while (curr != list->head && index != 0);

    // invalid index
    if (curr == list->head) return -1;

    return curr->data;
}

/*
 * Returns the last index at which specified element is present
 * -1 is returned if element is not present in the list or if the list is
 * uninitialized
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int lastIndexOfList_SC(const LinkedList_S *list, long long int element) {
    int lastIndex = -1, i = 0;
    Node_S *curr = list->head;
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
ll removeFirstList_SC(LinkedList_S *list) {
    if (list->head == NULL) return -1;
    else if (list->head == list->head->next) {
        ll toReturn = list->head->data;
        freeNode_S(list->head);
        list->head = NULL;
        return toReturn;
    }
    ll toReturn = list->head->data;
    swap(&list->head->data, &list->head->next->data);
    deleteAfter(list->head);
    return toReturn;
}

/*
 * Removes the last element from the list and returns the element
 * NOTE: A GARBAGE VALUE is returned if list is  uninitialized
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
ll removeLastList_SC(LinkedList_S *list) {
    if (list->head == NULL) return -1;
    else if (list->head == list->head->next)
        return removeFirstList_SC(list);
    else if (list->head->next->next == list->head) {
        ll toReturn = list->head->next->data;
        deleteAfter(list->head);
        return toReturn;
    }

    Node_S *curr;
    for (curr = list->head; curr->next->next == list->head; curr = curr->next);
    ll toReturn = curr->next->data;
    deleteAfter(curr);
    curr->next = list->head;
    return toReturn;
}

/*
 * Removes first occurrence of the element in list, and returns true if successful
 * if the element is not present in the list, then returns false
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
bool removeFirstOccurList_SC(LinkedList_S *list, long long int element) {
    if (list->head == NULL) return false;
    else if (list->head->data == element) {
        // check if firstOccurrence occurs at head of list
        removeFirstList_SC(list);
        return true;
    }

    // find first occurrence of element in ll
    Node_S *curr;
    for (curr = list->head; curr->next != list->head; curr = curr->next)
        if (curr->next->data == element)
            break;
    // no occurrence found
    if (curr->next == list->head) return false;

    deleteAfter(curr);
    return true;
}

/*
 * Remove element at the given index and returns the element
 * If index is invalid garbage value is returned
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
ll removeAtList_SC(LinkedList_S *list, int index) {
    if (list->head == NULL)return -1;
    else if (index == 0) {
        ll toReturn = list->head->data;
        removeFirstList_SC(list);
        return toReturn;
    }

    // iterate to right position
    Node_S *curr = list->head;
    for (int i = 0; i < index && curr->next != list->head; ++i)
        curr = curr->next;

    ll toReturn = curr->next->data;
    deleteAfter(curr);
    return toReturn;
}

/*
 * Removes the last Occurrence of the element in list, and returns the element
 * If the element is not present in the list, then a GARBAGE VALUE other than the element
 * is returned
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
ll removeLastOccurList_SC(LinkedList_S *list, long long int element) {
    if (list->head == NULL) return false;

    // find last occurrence of element in ll
    Node_S *lastOccur = NULL;
    Node_S *curr = list->head;
    do {
        if (curr->next->data == element)
            lastOccur = curr;
        curr = curr->next;
    } while (curr->next != list->head);

    // no occurrence found
    if (lastOccur == NULL) {
        if (list->head->data == element) {
            removeFirstList_SC(list);
            return true;
        } else return false;
    } else
        deleteAfter(lastOccur);

    return element;
}

/*
 * Sets element at given index, to provided value
 * Returns true if operation of setting is successful else false
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
bool setList_SC(LinkedList_S *list, int index, long long int val) {
    if (list->head == NULL) return false;
    else if (index == 0) {
        list->head->data = val;
        return true;
    }
    Node_S *curr = list->head;
    int i = 0;
    do {
        curr = curr->next;
        i++;
    } while (curr != list->head && i != index);

    if (curr == list->head) {
        // wrong index provided
        return false;
    }
    curr->data = val;
    return true;
}

/*
 * Converts the Linked List to array and returns ptr to it
 * If list is uninitialized NULL is returned
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
ll *toArrayList_SC(const LinkedList_S *list) {
    if (list->head == NULL) return NULL;
    ll *arr = malloc(sizeof(ll) * sizeList_SC(list));

    int i = 0;
    Node_S *curr = list->head;
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
void forEachList_SC(LinkedList_S *list, void (*lambda)(long long int)) {
    Node_S *curr = list->head;
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
int sizeList_SC(const LinkedList_S *list) {
    if (list->head == NULL) return 0;
    int len = 0;
    Node_S *curr = list->head;
    do {
        len++;
        curr = curr->next;
    } while (curr != list->head);
    return len;
}

/*
 * Prints the list in same line separated by space
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
void printList_SC(const LinkedList_S *list) {
    if (list->head == NULL) {
        printf("(null)");
        return;
    }
    Node_S *curr = list->head;
    do {
        printf("%lld ", curr->data);
        curr = curr->next;
    } while (curr != list->head);
}

/*
 * Returns true if list is empty ,ie, head is NULL or not
 * Time Complexity: O(1)
 */
bool isEmptyList_SC(LinkedList_S *list) {
    return list->head == NULL;
}
