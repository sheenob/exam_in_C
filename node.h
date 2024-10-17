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
void displayTree(Node* root); /* Function to print the tree */


//Functions to manipulate the Nodes
Node* INSERT(Node* root, int data);
Node* SEARCH(Node* root, int data);
Node* DELETE(Node* root, int data);
Node* SWAP(Node* root, int data1, int data2);
void TRAVERSAL(Node* root);


#endif // FUNCTIONS_H






