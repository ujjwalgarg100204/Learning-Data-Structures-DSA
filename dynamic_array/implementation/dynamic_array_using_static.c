#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "dynamic_array_using_static.h"

/*
 * Struct for dynamic array

typedef struct DynamicArrayI {
    int *arr;
    int currSize;
    int maxSize;
} DynamicArrayI;
*/

/* Returns true if index exists in the dynamic array */
bool isValidIndexI(DynamicArrayI *dynamicArr, int index);

/* Returns ptr to Dynamic Array */
DynamicArrayI *newDynamicArrayUsingStaticArrI(int maxSize) {
    DynamicArrayI *dynamicArray = malloc(sizeof(DynamicArrayI));
    dynamicArray->arr = calloc(maxSize, sizeof(int));
    dynamicArray->currSize = 0;
    dynamicArray->maxSize = maxSize;

    return dynamicArray;
}

/* Frees the dynamically allocated array */
void freeDynamicArrayI(DynamicArrayI *dynamicArr) {
    free(dynamicArr->arr);
    free(dynamicArr);
}

/* inserts a specific element at a specific position index in array */
void addAtIndexI(DynamicArrayI *dynamicArr, int index, int val) {
    if (!isValidIndexI(dynamicArr, index) || isFullI(dynamicArr)) {
        return;
    }

    // increase currSize to accommodate new element
    dynamicArr->currSize++;

    // shift the elements after the specified by 1 position
    for (int i = dynamicArr->currSize - 1; i != index; --i) {
        dynamicArr->arr[i] = dynamicArr->arr[i - 1];
    }

    // add the element
    dynamicArr->arr[index] = val;
}

/* inserts the element at the end of array */
void addAtLastI(DynamicArrayI *dynamicArr, int val) {
    if (isFullI(dynamicArr)) {
        return;
    }
    // increase currSize to accommodate new element
    dynamicArr->currSize++;

    // set the element
    dynamicArr->arr[dynamicArr->currSize - 1] = val;
}

/* Returns true if this array contains the specified element */
bool containsI(DynamicArrayI *dynamicArr, int val) {
    // loop through the whole array in search of the array, if found return true
    for (int i = 0; i < dynamicArr->currSize; ++i) {
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
    return dynamicArr->currSize == 0;
}

/* Removes the element at the specified position in this array */
void removeIndexI(DynamicArrayI *dynamicArr, int index) {
    if (!isValidIndexI(dynamicArr, index)) {
        return;
    }
    // shift the array from the index to index before
    for (int i = index; i < dynamicArr->currSize - 1; i++) {
        dynamicArr->arr[i] = dynamicArr->arr[i + 1];
    }

    // decrease curr size of the array to accommodate for the deleted element
    dynamicArr->currSize--;
}

/* 	Replaces the element at the specified position in this array with the specified element */
void setI(DynamicArrayI *dynamicArr, int index, int val) {
    if (!isValidIndexI(dynamicArr, index)) {
        return;
    }

    dynamicArr->arr[index] = val;
}

/*	Returns true if this array can not hold anymore element */
bool isFullI(DynamicArrayI *dynamicArr) {
    bool cond = dynamicArr->currSize == dynamicArr->maxSize;
    if (cond) {
        printf("Array is full");
    }
    return cond;
}

bool isValidIndexI(DynamicArrayI *dynamicArr, int index) {
    bool cond = index >= 0 && index < dynamicArr->currSize;
    if (!cond) {
        printf("Invalid index\n");
    }

    return cond;
}

