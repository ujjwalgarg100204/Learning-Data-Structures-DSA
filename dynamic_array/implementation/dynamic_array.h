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

/* Returns true if this array containsI the specified element */
bool containsI(DynamicArrayI *dynamicArr, int val);

/* 	Returns the element at the specified position in this array */
int getI(DynamicArrayI *dynamicArr, int index);

/*	Returns true if this array containsI no elements */
bool isEmptyI(DynamicArrayI *dynamicArr);

/* Removes the element at the specified position in this array */
void removeIndexI(DynamicArrayI *dynamicArr, int index);

/* 	Replaces the element at the specified position in this array with the specified element */
void setI(DynamicArrayI *dynamicArr, int index, int val);

typedef struct DynamicArrayS {
    char **arr;
    int size;
} DynamicArrayS;

/* Returns ptr to Dynamic Array */
DynamicArrayS *newDynamicArrayS();

/* Frees the dynamically allocated array */
void freeDynamicArrayS(DynamicArrayS *dynamicArr);

/* inserts a specific element at a specific position index in array */
void addAtIndexS(DynamicArrayS *dynamicArr, int index, char *val);

/* inserts the element at the end of array */
void addAtLastS(DynamicArrayS *dynamicArr, char *val);

/* Returns true if this array containsI the specified element */
bool containsS(DynamicArrayS *dynamicArr, char *val);

/* 	Returns the element at the specified position in this array */
char *getS(DynamicArrayS *dynamicArr, int index);

/*	Returns true if this array containsI no elements */
bool isEmptyS(DynamicArrayS *dynamicArr);

/* Removes the element at the specified position in this array */
void removeIndexS(DynamicArrayS *dynamicArr, int index);

/* 	Replaces the element at the specified position in this array with the specified element */
void setS(DynamicArrayS *dynamicArr, int index, char *val);

#endif //DATA_STRUCTURES_AND_ALGORITHM_DYNAMIC_ARRAY_H
