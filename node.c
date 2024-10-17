#include "node.h"
#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

//Function to display the tree
void displayTree(Node* root) {
    if (root == NULL) {
        return;
    }

    Queue* q = createQueue();
    addToQueue(q, root);

    while (!isEmpty(q)) {
        Node* temp = removeFromQueue(q);
        printf("\n");
        printf("%d ", temp->data);

        if (temp->left != NULL) {
            addToQueue(q, temp->left);
        }

        if (temp->right != NULL) {
            addToQueue(q, temp->right);
        }
    }
    printf("\n");

    freeQueue(q);
}

//Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (!newNode) {
        printf("Memorry error\n");
        return NULL;
    }
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
};

void freeNode(Node* node) {
    if (node != NULL) {
        freeNode(node->left);
        freeNode(node->right);
        free(node);
    }
}


//Function to insert a node into the binary tree
Node* INSERT(Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return root;
    }

    //Create a queue to store the nodes of the binary tree
    Queue* q = createQueue();
    addToQueue(q, root);

    while (!isEmpty(q)) {
        Node* temp = removeFromQueue(q);

        if (temp->left != NULL) {
            addToQueue(q, temp->left);
        } else {
            temp->left = createNode(data);
            freeQueue(q); // Libération de la mémoire de la queue
            return root;
        }

        if (temp->right != NULL) {
            addToQueue(q, temp->right);
        } else {
            temp->right = createNode(data);
            freeQueue(q); // Libération de la mémoire de la queue
            return root;
        }
    }

    freeQueue(q); // Libération de la mémoire de la queue
    return root;
}


//Function to search for a node in the binary tree
Node* SEARCH(Node* root, int data) {
    if (root == NULL) {
        return NULL;
    }

    Queue* q = createQueue();
    addToQueue(q, root);

    while (!isEmpty(q)) {
        Node* temp = removeFromQueue(q);
        if (temp->data == data) {
            freeQueue(q);
            return temp;
        }

        if (temp->left != NULL) {
            addToQueue(q, temp->left);
        }

        if (temp->right != NULL) {
            addToQueue(q, temp->right);
        }
    }
    

    freeQueue(q);
    return NULL;
}

//Function to delete a node from the binary tree
Node* DELETE(Node* root, int data) {
    if (root == NULL) {
        return NULL;
    }

    if (root->left == NULL && root->right == NULL) {
        if (root->data == data) {
            free(root);
            return NULL;
        } else {
            return root;
        }
    }

    Queue* q = createQueue();
    addToQueue(q, root);

    Node* temp = NULL; //temporary variable to traverse the tree
    Node* keyNode = NULL; //store the node that matches the key
    Node* lastNode = NULL; //store the last node encountered during the level-order traversal of the tree
    Node* parentOfLastNode = NULL; //store the parent of the last node

    while (!isEmpty(q)) {
        temp = removeFromQueue(q);

        if (temp->data == data) {
            keyNode = temp;
        }

        if (temp->left != NULL) {
            addToQueue(q, temp->left);
            parentOfLastNode = temp;
            lastNode = temp->left;
        }

        if (temp->right != NULL) {
            addToQueue(q, temp->right);
            parentOfLastNode = temp;
            lastNode = temp->right;
        }
    }

    /*handles the deletion of a node by replacing the node to be deleted with 
    the deepest node in the tree and then removing the deepest node*/
    if (keyNode != NULL) {
        keyNode->data = lastNode->data;
        if (parentOfLastNode->left == lastNode) {
            parentOfLastNode->left = NULL;
        } else {
            parentOfLastNode->right = NULL;
        }
        free(lastNode);
    }

    freeQueue(q);
    return root;
}


//Function to swap two nodes in a binary tree
Node* SWAP(Node* root, int data1, int data2) {
    Node* node1 = SEARCH(root, data1);
    Node* node2 = SEARCH(root, data2);

    if (node1 == NULL || node2 == NULL) {
        return root;
    }

    int temp = node1->data;
    node1->data = node2->data;
    node2->data = temp;

    return root;
}

// function to perform inorder traversal in a binary tree
void TRAVERSAL(Node* root)
{
    if (root == NULL) {
        return;
    }

    TRAVERSAL(root->left);
    printf("%d ", root->data);
    TRAVERSAL(root->right);
}