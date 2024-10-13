#ifndef FUNCTIONS_H
#define FUNCTIONS_H


//Structure for a node in a binary tree
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data); /* Function to create a new node */
void freeNode(Node* node); /* Function to free a node */


//Functions to manipulate the Nodes
Node* insertNode(Node* root, int data);


#endif // FUNCTIONS_H






