//Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.
#include <stdio.h>
#include <limits.h>

#define SIZE 100

int adj[SIZE][SIZE];
int visited[SIZE];
int dist[SIZE];

// find minimum distance node
int getMinNode(int n) {
    int min = INT_MAX, index = -1;

    for(int i = 0; i < n; i++) {
        if(!visited[i] && dist[i] < min) {
            min = dist[i];
            index = i;
        }
    }
    return index;
}

void dijkstra(int n, int src) {
    
    // initialize
    for(int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;

    for(int i = 0; i < n; i++) {
        
        int u = getMinNode(n);
        if(u == -1) break;

        visited[u] = 1;

        for(int v = 0; v < n; v++) {
            if(adj[u][v] && !visited[v]) {
                
                if(dist[u] + adj[u][v] < dist[v]) {
                    dist[v] = dist[u] + adj[u][v];
                }
            }
        }
    }

    // print result
    printf("Shortest distances from source %d:\n", src);
    for(int i = 0; i < n; i++) {
        printf("To %d = %d\n", i, dist[i]);
    }
}

int main() {
    int n, m;
    printf("Enter number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    // initialize graph
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter edges (u v weight):\n");
    for(int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
        adj[v][u] = w; // remove if directed
    }

    int src;
    printf("Enter source: ");
    scanf("%d", &src);

    dijkstra(n, src);

    return 0;
}