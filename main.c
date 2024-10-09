#include "functions.h"
#include <assert.h>
#include <stdio.h>

int main() {
    Node* root = createNode(1);
    assert(root->data == 1);
    freeNode(root);
    return 0;
}