#ifndef LEARNING_DATA_STRUCTURES_DSA_LINKEDLIST_D_H
#define LEARNING_DATA_STRUCTURES_DSA_LINKEDLIST_D_H

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
 * Adds element at the specified index
 * Returns true if addition of new element is successful else false
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
bool addAt(LinkedList *list, int index, double element);

/*
 * Adds element at the last of the list
 * Can be used to initialize the list
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
void addLast(LinkedList *list, double element);

/*
 * Adds all the elements of the array to the linked list, in the same order as they
 * occur
 * Returns true if addition is successful else false
 * Time Complexity: O(m+n)
 * Space Complexity: O(1)
 */
bool addAll(LinkedList *list, const double *arr, int lengthOfArr);

/*
 * Adds element at the first position of the list
 * Can be used to initialize the list
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
void addFirst(LinkedList *list, double element);

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
bool contains(const LinkedList *list, double element);

/*
 * Returns element present at first position
 * NOTE: If list is uninitialized, GARBAGE VALUE is returned
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
double getFirst(const LinkedList *list);

/*
 * Returns last element present at last position of the list
 * NOTE: If list is uninitialized, GARBAGE VALUE is returned
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
double getLast(const LinkedList *list);

/*
 * Returns element present at the specified index
 * NOTE: If list is uninitialized or index passed is invalid, GARBAGE VALUE is returned
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
double getAt(const LinkedList *list, int index);

/*
 * Returns the last index at which specified element is present
 * -1 is returned if element is not present in the list or if the list is
 * uninitialized
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int lastIndexOf(const LinkedList *list, double element);

/*
 * Removes the first element from the list and returns the element
 * NOTE: A GARBAGE VALUE is returned if list is uninitialized
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
double removeFirst(LinkedList *list);

/*
 * Removes the last element from the list and returns the element
 * NOTE: A GARBAGE VALUE is returned if list is  uninitialized
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
double removeLast(LinkedList *list);

/*
 * Removes first occurrence of the element in list, and returns true if successful
 * if the element is not present in the list, then returns false
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
bool removeFirstOccur(LinkedList *list, double element);

/*
 * Remove element at the given index and returns the element
 * If index is invalid garbage value is returned
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
double removeAt(LinkedList *list, int index);

/*
 * Removes the last Occurrence of the element in list, and returns the element
 * If the element is not present in the list, then a GARBAGE VALUE other than the element
 * is returned
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
double removeLastOccur(LinkedList *list, double element);

/*
 * Sets element at given index, to provided value
 * Returns true if operation of setting is successful else false
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
bool set(LinkedList *list, int index, double val);

/*
 * Converts the Linked List to array and returns ptr to it
 * If list is uninitialized NULL is returned
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
double *toArray(const LinkedList *list);

/*
 * Calls the passed function for each element in the list
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
void forEach(LinkedList *list, void (*lambda)(double));

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


#endif //LEARNING_DATA_STRUCTURES_DSA_LINKEDLIST_D_H
