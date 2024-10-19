#include <stdio.h>
#include <stdlib.h>

#define MAX 100
int adj[MAX][MAX];
int visited[MAX];
int n;

void DFS(int v) {
    printf(" %d ", v);
    visited[v] = 1;

    for(int i = 0; i < n; i++) {
        if(adj[v][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }



    for(int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("DFS Traversal starting from vertex 0: ");
    DFS(0);
    printf("\n");

    return 0;
}