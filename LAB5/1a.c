#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX]; // Adjacency matrix
int visited[MAX]; // Visited array
int stack[MAX]; // Stack to store topological order
int top = -1, vertices;

// Function to perform DFS
void dfs(int v) {
    visited[v] = 1;
    for (int i = 0; i < vertices; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
    stack[++top] = v; // Push to stack after visiting all neighbors
}

// Function to perform Topological Sorting using DFS
void topologicalSort() {
    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
    }
    
    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    
    // Print topological order
    printf("Topological Sort: ");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
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
