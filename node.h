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
void printTree(Node* root); /* Function to print the tree */


//Functions to manipulate the Nodes
Node* insertNode(Node* root, int data);
Node* searchNode(Node* root, int data);
Node* deleteNode(Node* root, int data);
Node* deleteDeepestNode(Node* root, Node* deepestNode);


#endif // FUNCTIONS_H






