#include <stdlib.h>

#include "node_singly_d.h"

struct Node {
    double data;
    struct Node *next;
};

/*
 * Creates and returns a ptr to the newly created node with passed data
 */
Node *newNode(double data) {
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

/*
 * Frees the dynamically allocated node, and renders it unusable
 */
void freeNode(Node *node) {
    free(node);
}

/* getters and setters of each node */
double getData(Node *node) {
    return node->data;
}

Node *getNext(Node *node) {
    return node->next;
}

void setData(Node *node, double val) {
    node->data = val;
}

void setNext(Node *node, Node *ptr) {
    node->next = ptr;
}

