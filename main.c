#include <assert.h>
#include "node.h"
#include "queue.h"
#include <stdio.h>

int main() {
    Node* root = NULL;
    root = insertNode(root, 10);
    insertNode(root, 20);

    printf("%d\n", root->data);
    printf("%d\n", root->left->data);

    freeNode(root);
    return 0;
}