#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX]; // Adjacency matrix
int inDegree[MAX]; // Array to store in-degrees
int queue[MAX]; // Queue for storing nodes with 0 in-degree
int front = 0, rear = -1, vertices;

// Function to perform Topological Sorting using Source Removal (Kahn's Algorithm)
void topologicalSort() {
    int count = 0; // Count of visited vertices
    for (int i = 0; i < vertices; i++) {
        inDegree[i] = 0;
    }
    
    // Compute in-degrees of all vertices
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (adj[i][j] == 1) {
                inDegree[j]++;
            }
        }
    }
    
    // Enqueue vertices with 0 in-degree
    for (int i = 0; i < vertices; i++) {
        if (inDegree[i] == 0) {
            queue[++rear] = i;
        }
    }
    
    printf("Topological Sort: ");
    while (front <= rear) {
        int v = queue[front++];
        printf("%d ", v);
        count++;
        
        for (int i = 0; i < vertices; i++) {
            if (adj[v][i] == 1) {
                if (--inDegree[i] == 0) {
                    queue[++rear] = i;
                }
            }
        }
    }
    
    if (count != vertices) {
        printf("\nGraph contains a cycle! Topological sort not possible.\n");
    } else {
        printf("\n");
    }
}

int main() {
    int edges, src, dest;
    
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    
    // Initialize adjacency matrix
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            adj[i][j] = 0;
        }
    }
    
    printf("Enter edges (source destination):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        adj[src][dest] = 1; // Directed edge
    }
    
    topologicalSort();
    return 0;
}
