#include <stdlib.h>
#include <stdio.h>

#include "dynamic_array.h"


/*
 * Struct for dynamic array

typedef struct DynamicArrayI {
    int *arr;
    int size;
} DynamicArrayI;
*/


/* Returns true if index exists in the dynamic array */
bool isValidIndexI(DynamicArrayI *dynamicArr, int index);

/* Returns ptr to Dynamic Array */
DynamicArrayI *newDynamicArrayI() {
    DynamicArrayI *dynamicArray = malloc(sizeof(DynamicArrayI));
    dynamicArray->arr = NULL;
    dynamicArray->size = 0;
    return dynamicArray;
}

/* Frees the dynamically allocated array */
void freeDynamicArrayI(DynamicArrayI *dynamicArr) {
    free(dynamicArr->arr);
    free(dynamicArr);
}

/* inserts a specific element at a specific position index in array */
void addAtIndexI(DynamicArrayI *dynamicArr, int index, int val) {
    if (!isValidIndexI(dynamicArr, index)) {
        return;
    }

    // allocate memory for new element and increment size by 1
    dynamicArr->arr = realloc(dynamicArr->arr, sizeof(int) * (++dynamicArr->size));

    // shift the elements after the specified by 1 position
    for (int i = dynamicArr->size - 1; i != index; --i) {
        dynamicArr->arr[i] = dynamicArr->arr[i - 1];
    }

    // add the element
    dynamicArr->arr[index] = val;
}

/* inserts the element at the end of array */
void addAtLastI(DynamicArrayI *dynamicArr, int val) {
    // allocate the memory for new element
    dynamicArr->arr = realloc(dynamicArr->arr, sizeof(int) * (++dynamicArr->size));

    // set the element
    dynamicArr->arr[dynamicArr->size - 1] = val;
}

/* Returns true if this array contains the specified element */
bool containsI(DynamicArrayI *dynamicArr, int val) {
    // loop through the whole array in search of the array, if found return true
    for (int i = 0; i < dynamicArr->size; ++i) {
        if (dynamicArr->arr[i] == val) {
            return true;
        }
    }

    return false;
}

/* 	Returns the element at the specified position in this array */
int getI(DynamicArrayI *dynamicArr, int index) {
    if (!isValidIndexI(dynamicArr, index)) {
        return -1;
    }

    return dynamicArr->arr[index];
}

/*	Returns true if this array contains no elements */
bool isEmptyI(DynamicArrayI *dynamicArr) {
    return dynamicArr->size == 0;
}

/* Removes the element at the specified position in this array */
void removeIndexI(DynamicArrayI *dynamicArr, int index) {
    if (!isValidIndexI(dynamicArr, index)) {
        return;
    }
    // shift the array from the index to index before
    for (int i = index; i < dynamicArr->size - 1; i++) {
        dynamicArr->arr[i] = dynamicArr->arr[i + 1];
    }

    // deallocate mem for that element
    dynamicArr->arr = realloc(dynamicArr->arr, sizeof(int) * (--dynamicArr->size));
}

/* 	Replaces the element at the specified position in this array with the specified element */
void setI(DynamicArrayI *dynamicArr, int index, int val) {
    if (!isValidIndexI(dynamicArr, index)) {
        return;
    }

    dynamicArr->arr[index] = val;
}

bool isValidIndexI(DynamicArrayI *dynamicArr, int index) {
    printf("Invalid index");


    return index >= 0 && index < dynamicArr->size;
}
