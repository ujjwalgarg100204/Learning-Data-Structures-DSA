#ifndef CODES_SINGLY_NODE_H
#define CODES_SINGLY_NODE_H

#define ll long long

typedef struct Node_S {
    ll data;
    struct Node_S *next;
} Node_S;

Node_S *newNode_S(ll data);

void freeNode_S(Node_S *node);

#endif //CODES_SINGLY_NODE_H
