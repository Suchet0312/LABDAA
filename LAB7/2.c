#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key, height;
    struct Node *left, *right;
} Node;

Node *successor(Node *root, int key) {
    Node *succ = NULL;
    while (root) {
        if (key < root->key) { succ = root; root = root->left; }
        else root = root->right;
    }
    return succ;
}

Node *predecessor(Node *root, int key) {
    Node *pred = NULL;
    while (root) {
        if (key > root->key) { pred = root; root = root->right; }
        else root = root->left;
    }
    return pred;
}

void findPreSuc(Node *root, int key) {
    Node *pred = predecessor(root, key);
    Node *succ = successor(root, key);
    printf("Predecessor: %d\n", pred ? pred->key : -1);
    printf("Successor: %d\n", succ ? succ->key : -1);
}

int main() {
    Node *root = NULL;
    int keys[] = {10, 20, 30, 40, 50, 25}, i;
    for (i = 0; i < 6; i++) root = insert(root, keys[i]);

    int key = 25;
    findPreSuc(root, key);
    return 0;
}
