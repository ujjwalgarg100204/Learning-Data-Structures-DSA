#include <malloc.h>
#include <stdio.h>
#include "singly_ll.h"

/*
 * Inserts a new node with passed data after given node
 * Will NOT work if node is NULL
 */
Node_S *insertAfterList_S(Node_S *node, ll data);

/*
 * Removes a node after the provided node
 * Will NOT work if node provided has next as NULL
 */
void removeNextList_S(Node_S *node);


/*
 * Frees all memory for all the nodes in the list and sets head of
 * list to NULL
 */
void freeAllNodesList_S(LinkedList_S *list);

/*
 * Creates a new linked list and returns a ptr to new list
 */
LinkedList_S *newSinglyLinkedList_S() {
    LinkedList_S *list = malloc(sizeof(LinkedList_S));
    list->head = NULL;
    return list;
}

/*
 * Frees the linked list and frees each node in the list
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
void freeLinkedList_S(LinkedList_S *list) {
    freeAllNodesList_S(list);
    free(list);
}


/*
 * Adds element at the specified index
 * Returns true if addition of new element is successful else false
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
bool addAtList_S(LinkedList_S *list, int index, long long int element) {
    if (index == 0) {
        addFirstList_S(list, element);
        return true;
    } else if (list->head == NULL) {
        // don't do anything to the uninitialized list
        return false;
    }

    // iterate to the node before node required
    Node_S *curr = list->head;
    while (index != 1 && curr != NULL) {
        curr = curr->next;
        index--;
    }

    if (curr == NULL) {
        // invalid index found
        return false;
    }

    // attach the node in the list
    insertAfterList_S(curr, element);
    return true;
}

/*
 * Adds element at the last of the list
 * Can be used to initialize the list
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
void addLastList_S(LinkedList_S *list, long long int element) {
    // if list is initialized addLast and addFirst do the same work
    if (list->head == NULL) {
        addFirstList_S(list, element);
        return;
    }

    // iterate towards the last of the list, and add the new node
    Node_S *curr;
    for (curr = list->head; curr->next != NULL; curr = curr->next);
    insertAfterList_S(curr, element);
}

/*
 * Adds all the elements of the array to the linked list, in the same order as they
 * occur
 * Returns true if addition is successful else false
 * Time Complexity: O(m+n)
 * Space Complexity: O(1)
 */
bool addAllList_S(LinkedList_S *list, const long long int *arr, int lengthOfArr) {
    if (arr == NULL) {
        // return if array provided is empty
        return false;
    }

    // create a new linked list by starting from the last of the array and add each
    // element of the array at the head of the new list
    Node_S *head = newNode_S(arr[lengthOfArr - 1]);
    for (int i = lengthOfArr - 2; i >= 0; i--) {
        Node_S *new = newNode_S(arr[i]);
        new->next = head;
        head = new; // make the new node as new head
    }

    if (list->head == NULL) list->head = head;
    else {
        Node_S *curr = list->head;
        while (curr->next != NULL) curr = curr->next;
        curr->next = head;
    }
    return true;
}

/*
 * Adds element at the first position of the list
 * Can be used to initialize the list
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
void addFirstList_S(LinkedList_S *list, long long int element) {
    Node_S *node = newNode_S(element);
    node->next = list->head;
    list->head = node;
}

/*
 * Empties the list
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
void clearList_S(LinkedList_S *list) {
    freeAllNodesList_S(list);
}

/*
 * Creates a copy of the list passed and returns the new copy of list
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
LinkedList_S *cloneList_S(const LinkedList_S *list) {
    if (list->head == NULL) {
        return NULL;
    }

    LinkedList_S *cloned = newSinglyLinkedList_S();
    // initialize the cloned list with given list's head
    cloned->head = newNode_S(list->head->data);

    Node_S *cloneTail = cloned->head;
    for (Node_S *curr = list->head->next; curr != NULL; curr = curr->next) {
        insertAfterList_S(cloneTail, curr->data);
        cloneTail = cloneTail->next;
    }
    return cloned;
}

/*
 * Returns true if element is present in list else false
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
bool containsList_S(const LinkedList_S *list, long long int element) {
    for (Node_S *curr = list->head; curr != NULL; curr = curr->next)
        if (element == curr->data) return true;
    return false;
}

/*
 * Returns element present at first position
 * NOTE: If list is uninitialized, GARBAGE VALUE is returned
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
ll getFirstList_S(const LinkedList_S *list) {
    return list->head != NULL ? list->head->data : -1;
}

/*
 * Returns last element present at last position of the list
 * NOTE: If list is uninitialized, GARBAGE VALUE is returned
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
ll getLastList_S(const LinkedList_S *list) {
    if (list->head == NULL) return -1;
    Node_S *tail;
    for (tail = list->head; tail->next != NULL; tail = tail->next);
    return tail->data;
}

/*
 * Returns element present at the specified index
 * NOTE: If list is uninitialized or index passed is invalid, GARBAGE VALUE is returned
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
ll getAtList_S(const LinkedList_S *list, int index) {
    if (list->head == NULL) return -1;

    // iterate to index of list
    Node_S *curr;
    for (curr = list->head; curr != NULL && index != 0; curr = curr->next, index--);

    // if invalid index return -1
    return curr == NULL ? -1 : curr->data;
}

/*
 * Returns the last index at which specified element is present
 * -1 is returned if element is not present in the list or if the list is
 * uninitialized
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int lastIndexOfList_S(const LinkedList_S *list, long long int element) {
    int lastIndex = -1, i = 0;
    for (Node_S *curr = list->head; curr != NULL; curr = curr->next, i++)
        if (curr->data == element) lastIndex = i;
    return lastIndex;
}

/*
 * Removes the last element from the list and returns the element
 * NOTE: A GARBAGE VALUE is returned if list is  uninitialized
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
ll removeFirstList_S(LinkedList_S *list) {
    if (list->head == NULL) {
        // don't  do anything if list is empty
        return -1;
    }

    // save data of the head that is to be returned
    ll headData = list->head->data;
    // set the next to head as new head
    Node_S *next = list->head->next;
    freeNode_S(list->head);
    list->head = next;

    return headData;
}

/*
 * Removes the last element from the list and returns the element
 * NOTE: A GARBAGE VALUE is returned if list is  uninitialized
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
ll removeLastList_S(LinkedList_S *list) {
    if (list->head == NULL) return -1;
    else if (list->head->next == NULL) {
        ll last = list->head->data;
        freeNode_S(list->head);
        list->head = NULL;
        return last;
    }

    // iterate to the last of the list
    Node_S *end;
    for (end = list->head; end->next->next != NULL; end = end->next);
    ll last = end->next->data;
    removeNextList_S(end);
    return last;
}

/*
 * Removes first occurrence of the element in list, and returns true if successful
 * if the element is not present in the list, then returns false
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
bool removeFirstOccurList_S(LinkedList_S *list, long long int element) {
    if (list->head == NULL) return false;
    else if (list->head->data == element) {
        removeFirstList_S(list);
        return true;
    }

    Node_S *beforeToBeRemoved = list->head;
    while (beforeToBeRemoved->next != NULL && beforeToBeRemoved->next->data != element)
        beforeToBeRemoved = beforeToBeRemoved->next;

    // couldn't find the element
    if (beforeToBeRemoved->next == NULL) return false;
    removeNextList_S(beforeToBeRemoved);
    return true;
}

/*
 * Remove element at the given index and returns the element
 * If index is invalid garbage value is returned
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
ll removeAtList_S(LinkedList_S *list, int index) {
    if (list->head == NULL) return -1;
    else if (index == 0) return removeFirstList_S(list);

    // iterate 1 element before the index
    Node_S *beforeIndex = list->head;
    while (index != 1 && beforeIndex != NULL) {
        beforeIndex = beforeIndex->next;
        index--;
    }

    // if index is invalid return GARBAGE VALUE
    if (beforeIndex == NULL || beforeIndex->next == NULL) return -1;

    ll element = beforeIndex->next->data;
    removeNextList_S(beforeIndex);
    return element;
}

/*
 * Removes the last Occurrence of the element in list, and returns the element
 * If the element is not present in the list, then a GARBAGE VALUE other than the element
 * is returned
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
ll removeLastOccurList_S(LinkedList_S *list, long long int element) {
    if (list->head == NULL) return -1;

    Node_S *beforeLastOccur = NULL;
    for (Node_S *curr = list->head; curr->next != NULL; curr = curr->next)
        if (curr->next->data == element) beforeLastOccur = curr;

    // if last occurrence of the element is at head only
    if (beforeLastOccur == NULL && list->head->data == element) return removeFirstList_S(list);
    else if (beforeLastOccur == NULL) {
        // element not present in the list
        return -1;
    }

    removeNextList_S(beforeLastOccur);
    return element;
}

/*
 * Sets element at given index, to provided value
 * Returns true if operation of setting is successful else false
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
bool setList_S(LinkedList_S *list, int index, long long int val) {
    if (list->head == NULL) return false;

    Node_S *curr;
    for (curr = list->head; index != 0 && curr != NULL; curr = curr->next, index--);

    if (curr == NULL) return false;
    curr->data = val;
    return true;
}

/*
 * Converts the Linked List to array and returns ptr to it
 * If list is uninitialized NULL is returned
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
ll *toArrayList_S(const LinkedList_S *list) {
    if (list->head == NULL) return NULL;

    int length = sizeList_S(list), i = 0;
    ll *arr = malloc(sizeof(ll) * length);
    for (Node_S *curr = list->head; curr != NULL; curr = curr->next)
        arr[i++] = curr->data;

    return arr;
}

/*
 * Calls the passed function for each element in the list
 * Time Complexity: O(n * O(lambda function))
 * Space Complexity: O(1)
 */
void forEachList_S(LinkedList_S *list, void (*lambda)(long long int)) {
    if (list->head == NULL) return;

    for (Node_S *curr = list->head; curr != NULL; curr = curr->next)
        lambda(curr->data);
}

/*
 * Returns size of the linked list
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int sizeList_S(const LinkedList_S *list) {
    if (list->head == NULL) return 0;
    int length = 0;
    for (Node_S *curr = list->head; curr != NULL; curr = curr->next)
        length++;
    return length;
}

void printList_S(const LinkedList_S *list) {
    if (list == NULL) {
        printf("(null)\n");
        return;
    }
    for (Node_S *curr = list->head; curr != NULL; curr = curr->next)
        printf("%lld ", curr->data);
    printf("\n");
}

Node_S *insertAfterList_S(Node_S *node, ll data) {
    Node_S *new = newNode_S(data);
    new->next = node->next;
    node->next = new;
    return node;
}

void removeNextList_S(Node_S *node) {
    Node_S *toBeDeleted = node->next;
    Node_S *next = toBeDeleted->next;
    freeNode_S(toBeDeleted);
    node->next = next;
}

void freeAllNodesList_S(LinkedList_S *list) {
    while (list->head != NULL) {
        Node_S *next = list->head->next;
        freeNode_S(list->head);
        list->head = next;
    }
}






