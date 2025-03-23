#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int key;
    int height;
    struct Node* left,*right;
}Node;

int getHeight(Node*node){
    return node? node->height:0;
}

int getBalancefactor(Node*node){
    return node ? getHeight(node->left)-getHeight(node->right) :0 ;
}

Node* create(int key){
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->key = key;
    newnode->height = 1;
    newnode->left = newnode->right = NULL;

    return newnode;
}

Node* rightRotate(Node*y){
    Node* x  = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    
}