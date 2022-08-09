#ifndef DATA_STRUCTURES_AND_ALGORITHM_DYNAMIC_ARRAY_H
#define DATA_STRUCTURES_AND_ALGORITHM_DYNAMIC_ARRAY_H

#include <stdbool.h>

typedef struct DynamicArrayI {
    int *arr;
    int size;
} DynamicArrayI;

/* Returns ptr to Dynamic Array */
DynamicArrayI *newDynamicArrayI();

/* Frees the dynamically allocated array */
void freeDynamicArrayI(DynamicArrayI *dynamicArr);

/* inserts a specific element at a specific position index in array */
void addAtIndexI(DynamicArrayI *dynamicArr, int index, int val);

/* inserts the element at the end of array */
void addAtLastI(DynamicArrayI *dynamicArr, int val);

/* Returns true if this array contains the specified element */
bool containsI(DynamicArrayI *dynamicArr, int val);

/* 	Returns the element at the specified position in this array */
int getI(DynamicArrayI *dynamicArr, int index);

/*	Returns true if this array contains no elements */
bool isEmptyI(DynamicArrayI *dynamicArr);

/* Removes the element at the specified position in this array */
void removeIndexI(DynamicArrayI *dynamicArr, int index);

/* 	Replaces the element at the specified position in this array with the specified element */
void setI(DynamicArrayI *dynamicArr, int index, int val);


#endif //DATA_STRUCTURES_AND_ALGORITHM_DYNAMIC_ARRAY_H
