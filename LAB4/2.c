#include <stdio.h>

#define MAX 10

int graph[MAX][MAX];
int pushOrder[MAX], popOrder[MAX];
int pushIndex = 0, popIndex = 0;
int visited[MAX];
int vertices;

void dfs(int val) {
    visited[val] = 1;
    printf("%d ", val); 
    pushOrder[pushIndex++] = val;

    for (int i = 0; i < vertices; i++) {
        if (!visited[i] && graph[val][i] == 1) { 
            dfs(i);
        }
    }
    popOrder[popIndex++] = val;
}

int main() {
    int edges, u, v;
    
    printf("Enter the number of vertices: "); 
    scanf("%d", &vertices);
    
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
        visited[i] = 0;
    }

    printf("Enter the edges (u v) format:\n"); 
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; 
    }

    printf("Enter starting vertex: "); 
    int start;
    scanf("%d", &start);

    printf("DFS: ");
    dfs(start);
    printf("\n");

    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) { //unvisited nodes after dfs(start)
            dfs(i);
        }
    }

    printf("Push order: ");
    for (int i = 0; i < pushIndex; i++) {
        printf("%d ", pushOrder[i]);
    }
    printf("\n");

    printf("Pop order: ");
    for (int i = 0; i < popIndex; i++) {
        printf("%d ", popOrder[i]);
    }
    printf("\n");

    return 0;
}
