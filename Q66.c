/*Problem: Detect cycle in directed graph using DFS and recursion stack.

Output:
- YES if cycle exists
*/
#include <stdio.h>

#define SIZE 100

int adj[SIZE][SIZE];
int visited[SIZE];
int recStack[SIZE];

// DFS function
int dfs(int node, int n) {
    visited[node] = 1;
    recStack[node] = 1;

    for(int i = 0; i < n; i++) {
        if(adj[node][i]) {
            
            if(!visited[i]) {
                if(dfs(i, n)) return 1;
            }
            else if(recStack[i]) {
                return 1; // cycle found
            }
        }
    }

    recStack[node] = 0; // backtrack
    return 0;
}

// main cycle check
int hasCycle(int n) {
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            if(dfs(i, n)) return 1;
        }
    }
    return 0;
}

int main() {
    int n, m;
    printf("Enter number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    // initialize
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
        visited[i] = 0;
        recStack[i] = 0;
    }

    printf("Enter directed edges (u v):\n");
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1; // directed edge
    }

    if(hasCycle(n)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}