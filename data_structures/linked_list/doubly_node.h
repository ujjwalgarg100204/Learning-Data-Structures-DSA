#ifndef CODES_DOUBLY_NODE_H
#define CODES_DOUBLY_NODE_H

#define ll long long

typedef struct Node_D {
    ll data;
    struct Node_D *next;
    struct Node_D *prev;
} Node_D;

Node_D *newNode_D(ll data);

void freeNode_D(Node_D *node);

#endif //CODES_DOUBLY_NODE_H
