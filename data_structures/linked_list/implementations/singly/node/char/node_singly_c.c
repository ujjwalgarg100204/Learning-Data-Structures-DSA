#include <stdlib.h>

#include "node_singly_c.h"

struct Node {
    char data;
    struct Node *next;
};

/*
 * Creates and returns a ptr to the newly created node with passed data
 */
Node *newNode(char data) {
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
char getData(Node *node) {
    return node->data;
}

Node *getNext(Node *node) {
    return node->next;
}

void setData(Node *node, char val) {
    node->data = val;
}

void setNext(Node *node, Node *ptr) {
    node->next = ptr;
}

