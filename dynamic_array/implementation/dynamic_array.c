#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "dynamic_array.h"

/*
 * Struct for dynamic array

typedef struct DynamicArrayI {
    int *arr;
    int length;
} DynamicArrayI;
*/


/* Returns true if index exists in the dynamic array */
bool isValidIndexI(DynamicArrayI *dynamicArr, int index);

bool isValidIndexS(DynamicArrayS *dynamicArr, int index);


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

    // allocate memory for new element and increment length by 1
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

/* Returns true if this array containsI the specified element */
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

/*	Returns true if this array containsI no elements */
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
    bool cond = index >= 0 && index < dynamicArr->size;
    if (!cond)
        printf("Invalid index\n");


    return cond;
}


/*
 * Struct for String Dynamic Array
typedef struct DynamicArrayS {
    char **arr;
    int length;
} DynamicArrayS;
*/

/* Returns ptr to Dynamic Array */
DynamicArrayS *newDynamicArrayS() {
    DynamicArrayS *dynamicArray = malloc(sizeof(DynamicArrayS));
    dynamicArray->arr = NULL;
    dynamicArray->size = 0;
    return dynamicArray;
}

/* Frees the dynamically allocated array */
void freeDynamicArrayS(DynamicArrayS *dynamicArr) {
    // free memory for each individual string
    for (int i = 0; i < dynamicArr->size; i++) {
        free(dynamicArr->arr[i]);
    }
    free(dynamicArr->arr);
    free(dynamicArr);
}

/* inserts a specific element at a specific position index in array */
void addAtIndexS(DynamicArrayS *dynamicArr, int index, char *val) {
    if (!isValidIndexS(dynamicArr, index)) {
        return;
    }

    // allocate memory for new element and increment length by 1
    dynamicArr->arr = realloc(dynamicArr->arr, sizeof(char *) * (++dynamicArr->size));

    // shift the elements after the specified by 1 position
    for (int i = dynamicArr->size - 1; i != index; --i) {
        dynamicArr->arr[i] = dynamicArr->arr[i - 1];
    }

    // add the element
    dynamicArr->arr[index] = malloc(sizeof(char) * (strlen(val) + 1));
    strcpy(dynamicArr->arr[index], val);
}


/* inserts the element at the end of array */
void addAtLastS(DynamicArrayS *dynamicArr, char *val) {
    // allocate the memory for new element
    dynamicArr->arr = realloc(dynamicArr->arr, sizeof(char *) * (++dynamicArr->size));

    // set the element
    dynamicArr->arr[dynamicArr->size - 1] = malloc(sizeof(char) * (strlen(val) + 1));
    strcpy(dynamicArr->arr[dynamicArr->size - 1], val);
}

/* Returns true if this array containsI the specified element */
bool containsS(DynamicArrayS *dynamicArr, char *val) {
    // loop through the whole array in search of the array, if found return true
    for (int i = 0; i < dynamicArr->size; ++i) {
        if (strcmp(dynamicArr->arr[i], val) == 0) {
            return true;
        }
    }

    return false;
}

/* 	Returns the element at the specified position in this array */
char *getS(DynamicArrayS *dynamicArr, int index) {
    if (!isValidIndexS(dynamicArr, index)) {
        return NULL;
    }

    return dynamicArr->arr[index];
}

/*	Returns true if this array containsI no elements */
bool isEmptyS(DynamicArrayS *dynamicArr) {
    return dynamicArr->size == 0;
}

/* Removes the element at the specified position in this array */
void removeIndexS(DynamicArrayS *dynamicArr, int index) {
    if (!isValidIndexS(dynamicArr, index)) {
        return;
    }
    // free the memory of the index
    free(dynamicArr->arr[index]);
    // shift the array from the index to index before
    for (int i = index; i < dynamicArr->size - 1; i++) {
        dynamicArr->arr[i] = dynamicArr->arr[i + 1];
    }

    // deallocate mem for that element
    dynamicArr->arr = realloc(dynamicArr->arr, sizeof(char *) * (--dynamicArr->size));
}

/* 	Replaces the element at the specified position in this array with the specified element */
void setS(DynamicArrayS *dynamicArr, int index, char *val) {
    if (!isValidIndexS(dynamicArr, index)) {
        return;
    }

    // first free the memory and set it equal to val
    free(dynamicArr->arr[index]);
    dynamicArr->arr[index] = malloc(sizeof(char) * (strlen(val) + 1));
    strcpy(dynamicArr->arr[index], val);
}


bool isValidIndexS(DynamicArrayS *dynamicArr, int index) {
    bool cond = index >= 0 && index < dynamicArr->size;
    if (!cond)
        printf("Invalid index\n");

    return cond;
}
