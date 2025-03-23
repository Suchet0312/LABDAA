#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node*link;
}Node;

Node* create(int value){
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data= value;
    newnode->link = NULL;

    return newnode;
}

Node* createList(Node*adjlist[],int vertices){
    printf("adjacency matrix:\n");
    for(int i=0;i<vertices;i++){
        printf("%d->",i);
        Node* temp = adjlist[i];
        while(temp){
            printf("%d->",temp->data);
            temp = temp->link;
        }
        printf("NULL\n");
    }
}

void printAdjMatrix(int matrix[][10], int vertices) {
    printf("\nAdjacency Matrix Representation:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int vertices, edges, src, dest;

    // Step 1: Input number of vertices and edges
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Step 2: Initialize adjacency matrix
    int adjMatrix[10][10] = {0};

    // Step 3: Initialize adjacency list
    struct Node* adjList[10] = {NULL};

    // Step 4: Input edges
    printf("Enter the edges (source destination):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);

        // Update adjacency matrix
        adjMatrix[src][dest] = 1;
        adjMatrix[dest][src] = 1;  // Uncomment for undirected graph

        // Update adjacency list
        Node* newNode = createNode(dest);
        newNode->link = adjList[src];
        adjList[src] = newNode;

        newNode = createNode(src);  // Uncomment for undirected graph
        newNode->link = adjList[dest];
        adjList[dest] = newNode;
    }

    // Step 5: Print representations
    printAdjMatrix(adjMatrix, vertices);
    createList(adjList, vertices);

    return 0;
}
