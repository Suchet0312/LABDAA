#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int graph[MAX][MAX],visted[MAX];
int vertices;

void dfs(int v){
    printf("%d ",v);
    visted[v] = 1;


    for(int i=0;i<vertices;i++){
        if(graph[v][i]==1 && !visted[i]){
            dfs(i);
        }
    }
}

int main(){
    int edges , v1,v2, start;

    printf("enter the number of vertices: ");
    scanf("%d ",&vertices);

    for(int i=0;i<vertices;i++){
        for(int j=0;j<vertices;j++){
            graph[i][j] = 0;
        }
        visted[i] = 0;
    }

    printf("enter the number of edges(v1 v2):\n");
    for(int i=0;i<edges;i++){
        scanf("%d %d",&v1,&v2);
        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }

    printf("Enter the starting vertex: ");
    scanf("%d ",&start);

    printf("DFS trraversal: ");
    dfs(start);
    printf("\n");

    return 0;
}