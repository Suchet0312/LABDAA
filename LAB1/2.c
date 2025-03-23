#include <stdio.h>
#include <stdlib.h>

// Structure for adjacency list node
struct Node {
    int vertex;
    struct Node* next;
};

// Function to create a new adjacency list node
struct Node* createNode(int vertex) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to print the adjacency list
void printAdjList(struct Node* adjList[], int vertices) {
    printf("\nAdjacency List Representation:\n");
    for (int i = 0; i < vertices; i++) {
        printf("%d -> ", i);
        struct Node* temp = adjList[i];
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Function to print the adjacency matrix
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
        struct Node* newNode = createNode(dest);
        newNode->next = adjList[src];
        adjList[src] = newNode;

        newNode = createNode(src);  // Uncomment for undirected graph
        newNode->next = adjList[dest];
        adjList[dest] = newNode;
    }

    // Step 5: Print representations
    printAdjMatrix(adjMatrix, vertices);
    printAdjList(adjList, vertices);

    return 0;
}
