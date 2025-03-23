#include <stdio.h>

#define MAX 100  // Maximum number of vertices

int adj[MAX][MAX];  // Adjacency matrix
int in_degree[MAX]; // In-degree array
int queue[MAX];     // Queue for BFS
int front = 0, rear = -1;
int n;  // Number of vertices

// Function for BFS-based Topological Sort (Source Removal)
void topologicalSort() {
    int sorted[MAX], index = 0;

    // Enqueue nodes with in-degree 0
    for (int i = 0; i < n; i++) {
        if (in_degree[i] == 0) {
            queue[++rear] = i;
        }
    }

    while (front <= rear) {
        int u = queue[front++];  // Dequeue
        sorted[index++] = u;     // Store in topological order

        // Reduce in-degree of neighbors
        for (int v = 0; v < n; v++) {
            if (adj[u][v] == 1) {
                in_degree[v]--;
                if (in_degree[v] == 0) {
                    queue[++rear] = v;
                }
            }
        }
    }

    // If all nodes are sorted, print the order
    if (index != n) {
        printf("Graph has a cycle! Topological sorting is not possible.\n");
    } else {
        printf("Topological Order: ");
        for (int i = 0; i < index; i++) {
            printf("%d ", sorted[i]);
        }
        printf("\n");
    }
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
        in_degree[v]++;  // Increase in-degree of v
    }

    topologicalSort();

    return 0;
}
