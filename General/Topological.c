#include <stdio.h>

#define MAX 100  // Maximum number of vertices

int adj[MAX][MAX];  // Adjacency matrix
int visited[MAX];   // Visited array
int stack[MAX];     // Stack to store the topological order
int top = -1;       // Stack pointer
int n;              // Number of vertices

// Function to perform DFS
void dfs(int v) {
    visited[v] = 1;  // Mark the node as visited
    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
    stack[++top] = v;  // Push to stack after visiting all neighbors
}

// Function to perform Topological Sort
void topologicalSort() {
    for (int i = 0; i < n; i++)
        visited[i] = 0;  // Initialize visited array

    for (int i = 0; i < n; i++) {
        if (!visited[i])
            dfs(i);
    }

    printf("Topological Order: ");
    while (top >= 0)
        printf("%d ", stack[top--]);  // Pop from stack
    printf("\n");
}

// Main function
int main() {
    int edges, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;  // Directed edge u → v
    }

    topologicalSort();

    return 0;
}
