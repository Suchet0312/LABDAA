#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* link;
}Node;

Node* create(int value){
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = value;
    newnode->link = NULL;

    return newnode;
}

void printlist(Node* adjList[],int vertices){
    for(int i=0;i<vertices;i++){
        printf("%d -> ",i);

        Node* temp = adjList[i];

        while (temp)
        {
            printf("%d -> ",temp->data);
            temp = temp->link;
        }
        printf("NULL\n");
        
    }
}

void printMatrix(int matrix[][10],int vertices){
    printf("adjacency matrix:\n");
    for(int i=0;i<vertices;i++){
        for(int j=0;j<vertices;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int vertices, edges, src,dest;

    printf("enter the number of vertices: ");
    scanf("%d",&vertices);

    printf("enter the number of edges: ");
    scanf("%d",&edges);

    int adjmatrix[10][10] = {0};

    Node* adjlist[10] = {NULL};

    printf("enter the edges (source destination): \n");
    for(int i=0;i<edges;i++){
        scanf("%d %d",&src,&dest);

        adjmatrix[src][dest] = 1;
        adjmatrix[dest][src] = 1;

        Node* newnode = create(dest);
        newnode->link = adjlist[src];
        adjlist[src] = newnode;


        newnode = create(src);
        newnode->link = adjlist[dest];
        adjlist[dest] = newnode;
    } 
    printlist(adjlist,vertices);
    printMatrix(adjmatrix,vertices);

    return 0;
}