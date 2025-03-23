#include <stdio.h>
#include <stdlib.h>

int opcount = 0; // Operation counter

typedef struct node {
    int data;
    struct node *rchild;
    struct node *lchild;
} Node;

Node* create(int value) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = value;
    newnode->lchild = newnode->rchild = NULL;
    return newnode;
}

Node* insert(Node* root, int value) {
    opcount++; // Counting comparison operation
    if (root == NULL) {
        return create(value);
    }
    if (value < root->data) {
        opcount++; // Counting comparison operation
        root->lchild = insert(root->lchild, value);
    } else {
        root->rchild = insert(root->rchild, value);
    }
    return root;
}

int countNodes(Node* root) {
    opcount++; // Counting function call operation
    if (root == NULL) {
        return 0;
    }
    return 1 + countNodes(root->lchild) + countNodes(root->rchild);
}

int main() {
    Node* root = NULL;
    
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 7);
    
    printf("Total number of nodes: %d\n", countNodes(root));
    printf("Total operation count: %d\n", opcount);
    
    return 0;
}
