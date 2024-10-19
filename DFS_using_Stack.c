#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int graph[MAX][MAX];
int top = -1;
int visited[MAX] = {0};

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

int isEmpty() {
    return top == -1;
}

void DFS(int graph[MAX][MAX], int v, int n) {
    push(v);
    visited[v] = 1;

    printf("DFS Traversal: ");

    while (!isEmpty()) {
        int current = pop();
        printf("%d ", current+1);

        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                push(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    
    DFS(graph, 0, n);

    return 0;
}
