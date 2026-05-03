/*Problem Statement
Using BFS or DFS, check if the entire graph is connected.

Input Format
n m
edges

Output Format
CONNECTED
NOT CONNECTED

Sample Input
4 2
1 2
3 4

Sample Output
NOT CONNECTED
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005

int adj[MAXN][MAXN];   // adjacency matrix (for simplicity, but not memory efficient for very large n)
int adjSize[MAXN];     // adjacency list sizes
int visited[MAXN];

void dfs(int u, int n, int** edges, int* adjSize, int** adjList) {
    visited[u] = 1;
    for (int i = 0; i < adjSize[u]; i++) {
        int v = adjList[u][i];
        if (!visited[v]) {
            dfs(v, n, edges, adjSize, adjList);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // adjacency list
    int** adjList = (int**)malloc(n * sizeof(int*));
    int* adjSize = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        adjList[i] = (int*)malloc(n * sizeof(int)); // worst case
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--; // convert to 0-based index
        adjList[u][adjSize[u]++] = v;
        adjList[v][adjSize[v]++] = u;
    }

    // DFS from node 0
    dfs(0, n, NULL, adjSize, adjList);

    // check if all visited
    int connected = 1;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            connected = 0;
            break;
        }
    }

    if (connected) {
        printf("CONNECTED\n");
    } else {
        printf("NOT CONNECTED\n");
    }

    return 0;
}
