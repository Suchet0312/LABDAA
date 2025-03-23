#include<stdio.h>
#include<stdlib.h>


typedef struct node{
    int data;
    struct node*link;
}Node;

Node* create(int value){
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = value;
    newnode->link = NULL;

    return newnode;
}

void printList(Node* adjList[],int vertices){
    printf("Adjacency list representation: \n");
    for(int i=0;i<vertices;i++){
        printf("i->",i);
        Node* temp = adjList[i];
        while(temp){
            printf("%d->",temp->data);
            temp = temp->link;
        }
        printf("NULL\n");
    }
}