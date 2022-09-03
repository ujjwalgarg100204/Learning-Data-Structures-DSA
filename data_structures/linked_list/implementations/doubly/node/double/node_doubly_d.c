#include <stdlib.h>

#include "node_doubly_d.h"

struct Node {
    double data;
    struct Node *prev;
    struct Node *next;
};

Node *newNode(double data) {
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void freeNode(Node *node) {
    free(node);
}

double getData(Node *node) {
    return node->data;
}

Node *getNext(Node *node) {
    return node->next;
}

Node *getPrev(Node *node) {
    return node->prev;
}

void setData(Node *node, double val) {
    node->data = val;
}

void setNext(Node *node, Node *ptr) {
    node->next = ptr;
}

void setPrev(Node *node, Node *ptr) {
    node->prev = ptr;
}