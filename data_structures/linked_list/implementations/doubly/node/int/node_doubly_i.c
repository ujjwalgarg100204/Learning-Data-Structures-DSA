#include <stdlib.h>

#include "node_doubly_i.h"

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

Node *newNode(int data) {
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void freeNode(Node *node) {
    free(node);
}

int getData(Node *node) {
    return node->data;
}

Node *getNext(Node *node) {
    return node->next;
}

Node *getPrev(Node *node) {
    return node->prev;
}

void setData(Node *node, int val) {
    node->data = val;
}

void setNext(Node *node, Node *ptr) {
    node->next = ptr;
}

void setPrev(Node *node, Node *ptr) {
    node->prev = ptr;
}