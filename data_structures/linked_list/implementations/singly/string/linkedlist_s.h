#ifndef LEARNING_DATA_STRUCTURES_DSA_LINKEDLIST_S_H
#define LEARNING_DATA_STRUCTURES_DSA_LINKEDLIST_S_H

#include <stdbool.h>

typedef struct LinkedList LinkedList;


/*
 * Creates a new linked list and returns a ptr to new list
 */
LinkedList *newLinkedList();

/*
 * Frees the linked list and frees each node in the list
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
void freeLinkedList(LinkedList *list);

/*
 * Adds element string at the specified index
 * New memory is allocated for passed string
 * Returns true if addition of new element is successful else false
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
bool addAt(LinkedList *list, int index, const char *element);

/*
 * Adds element at the last of the list
 * New memory is allocated for passed string
 * Can be used to initialize the list
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
void addLast(LinkedList *list, const char *element);

/*
 * Adds all the elements of the array to the linked list, in the same order as they occur
 * New memory is allocated for each string in the array
 * Returns true if addition is successful else false
 * Time Complexity: O(m+n)
 * Space Complexity: O(1)
 */
bool addAll(LinkedList *list, const char **arr, int lengthOfArr);

/*
 * Adds element at the first position of the list
 * New memory is allocated for passed string
 * Can be used to initialize the list
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
void addFirst(LinkedList *list, const char *element);

/*
 * Empties the list
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
void clear(LinkedList *list);

/*
 * Creates a copy of the list passed and returns the new copy of list
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
LinkedList *clone(const LinkedList *list);

/*
 * Returns true if element is present in list else false
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
bool contains(const LinkedList *list, const char *element);

/*
 * Returns a constant ptr to the string present at first position
 * NOTE: If list is uninitialized, GARBAGE VALUE is returned
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
const char *getFirst(const LinkedList *list);

/*
 * Returns constant ptr to the string present at last position of the list
 * NOTE: If list is uninitialized, GARBAGE VALUE is returned
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
const char *getLast(const LinkedList *list);

/*
 * Returns a constant ptr to the string present at the specified index
 * NOTE: If list is uninitialized or index passed is invalid, GARBAGE VALUE is returned
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
const char *getAt(const LinkedList *list, int index);

/*
 * Returns the last index at which specified element is present
 * -1 is returned if element is not present in the list or if the list is
 * uninitialized
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int lastIndexOf(const LinkedList *list, const char *element);

/*
 * Removes the first element from the list and returns the ptr to the string
 * which needs to be deallocated by user
 * NOTE: A GARBAGE VALUE is returned if list is uninitialized
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
const char *removeFirst(LinkedList *list);

/*
 * Removes the last element from the list and returns the ptr to the string
 * which needs to be deallocated by user
 * NOTE: A GARBAGE VALUE is returned if list is  uninitialized
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
const char *removeLast(LinkedList *list);

/*
 * Removes first occurrence of the element in list, and returns true if successful
 * if the element is not present in the list, then returns false
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
bool removeFirstOccur(LinkedList *list, const char *element);

/*
 * Remove element at the given index and returns the ptr to the string
 * which needs to be deallocated by user
 * If index is invalid garbage value is returned
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
const char *removeAt(LinkedList *list, int index);

/*
 * Removes the last Occurrence of the element in list, and returns the ptr to the string
 * which needs to be deallocated by user
 * If the element is not present in the list, then a GARBAGE VALUE other than the element
 * is returned
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
const char *removeLastOccur(LinkedList *list, const char *element);

/*
 * Sets element at given index, to provided string by allocating new memory for it
 * Returns true if operation of setting is successful else false
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
bool set(LinkedList *list, int index, const char *val);

/*
 * Converts the Linked List to array and returns ptr to it
 * If list is uninitialized NULL is returned
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
char **toArray(const LinkedList *list);

/*
 * Calls the passed function for each element in the list
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
void forEach(LinkedList *list, void (*lambda)(const char *));

/*
 * Returns size of the linked list
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int size(const LinkedList *list);

/*
 * Prints the list in same line separated by space
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
void printList(const LinkedList *list);

#endif //LEARNING_DATA_STRUCTURES_DSA_LINKEDLIST_S_H
