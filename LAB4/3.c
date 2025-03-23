#include <stdio.h>

#define MAX 10

int graph[MAX][MAX]; 
int visited[MAX];    
int queue[MAX];      
int front = 0, rear = 0;
int pushOrder[MAX], popOrder[MAX];
int pushIndex = 0, popIndex = 0;
int vertices;

void bfs(int start) {
    queue[rear++] = start;  
    visited[start] = 1;

    while (front < rear) {
        int current = queue[front++];  
        printf("%d ", current);        
        popOrder[popIndex++] = current;

        for (int i = 0; i < vertices; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                queue[rear++] = i;  
                visited[i] = 1;
                pushOrder[pushIndex++] = i;
            }
        }
    }
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

    printf("BFS: ");
    pushOrder[pushIndex++] = start;
    bfs(start);
    printf("\n");

    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            pushOrder[pushIndex++] = i;
            bfs(i);
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
