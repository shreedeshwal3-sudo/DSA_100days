// Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.
#include <stdio.h>

#define SIZE 100

int adj[SIZE][SIZE];
int visited[SIZE];
int stack[SIZE];
int top = -1;

// push into stack
void push(int x) {
    stack[++top] = x;
}

// DFS function
void dfs(int node, int n) {
    visited[node] = 1;

    for(int i = 0; i < n; i++) {
        if(adj[node][i] && !visited[i]) {
            dfs(i, n);
        }
    }

    push(node); // push after visiting children
}

// Topological sort
void topoSort(int n) {
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(i, n);
        }
    }

    // print in reverse order
    printf("Topological Order: ");
    while(top != -1) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
}

int main() {
    int n, m;
    printf("Enter number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    // initialize
    for(int i = 0; i < n; i++) {
        visited[i] = 0;
        for(int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter directed edges (u v):\n");
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    topoSort(n);

    return 0;
}