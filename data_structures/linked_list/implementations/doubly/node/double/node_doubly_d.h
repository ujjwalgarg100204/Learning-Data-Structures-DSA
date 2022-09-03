#ifndef LEARNING_DATA_STRUCTURES_DSA_NODE_DOUBLY_D_H
#define LEARNING_DATA_STRUCTURES_DSA_NODE_DOUBLY_D_H

/* struct for each data node */
typedef struct Node Node;


/*
 * Creates and returns a ptr to the newly created node with passed data
 */
Node *newNode(double data);

/*
 * Frees the dynamically allocated node, and renders it unusable
 */
void freeNode(Node *node);

/* getters and setters of each node */
double getData(Node *node);

Node *getNext(Node *node);

Node *getPrev(Node *node);

void setData(Node *node, double val);

void setNext(Node *node, Node *ptr);

void setPrev(Node *node, Node *ptr);

#endif //LEARNING_DATA_STRUCTURES_DSA_NODE_DOUBLY_D_H
