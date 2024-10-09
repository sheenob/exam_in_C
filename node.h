#ifndef NODE_H
#define NODE_H


//Structure for a node in a binary tree
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

#endif // NODE_H