#include <stdlib.h>

#include "node_doubly_c.h"

struct Node {
    char data;
    struct Node *prev;
    struct Node *next;
};

Node *newNode(char data) {
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void freeNode(Node *node) {
    free(node);
}

char getData(Node *node) {
    return node->data;
}

Node *getNext(Node *node) {
    return node->next;
}

Node *getPrev(Node *node) {
    return node->prev;
}

void setData(Node *node, char val) {
    node->data = val;
}

void setNext(Node *node, Node *ptr) {
    node->next = ptr;
}

void setPrev(Node *node, Node *ptr) {
    node->prev = ptr;
}