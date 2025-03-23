#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;
int vertices;

void push(int val){
    stack[top++] = val;
}

int pop(){
    return stack[top--];
}

int isEmpty(){
    return top==-1;
}

void dfs(int start){
    push(start);

    while(isEmpty()){
        int v = pop();

        if(!visited[v]){
            printf("%d",v);
            visited[v] = 1;
        }

        for(int i=vertices-1;i>=0;i--){
            if(graph[v][i]==1 && !visited[i]){
                push(i);
            }
        }
    }
}
int main() {
    int edges, v1, v2, start;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    // Initialize the adjacency matrix and visited array
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
        visited[i] = 0;
    }

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (v1 v2):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &v1, &v2);
        graph[v1][v2] = 1;
        graph[v2][v1] = 1; // For an undirected graph
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    printf("DFS Traversal: ");
    dfs(start);
    printf("\n");

    return 0;
}
