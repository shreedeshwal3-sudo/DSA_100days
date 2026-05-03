/*Problem Statement
Find shortest distances from source vertex in a weighted graph with non-negative weights.

Input Format
n m
u v w
source

Output Format
Distances to all vertices.

Sample Input
5 6
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
4 5 1
1

Sample Output
0 2 3 9 6

Explanation
Shortest distances computed via priority queue.

*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure for adjacency list node
struct Node {
    int v;
    int w;
    struct Node* next;
};

// Add edge to adjacency list
void addEdge(struct Node* adj[], int u, int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->v = v;
    newNode->w = w;
    newNode->next = adj[u];
    adj[u] = newNode;
}

// Min-heap node
struct HeapNode {
    int v;
    int dist;
};

// Min-heap structure
struct MinHeap {
    int size;
    int capacity;
    int *pos;
    struct HeapNode **array;
};

// Create a new heap node
struct HeapNode* newHeapNode(int v, int dist) {
    struct HeapNode* node = (struct HeapNode*)malloc(sizeof(struct HeapNode));
    node->v = v;
    node->dist = dist;
    return node;
}

// Create min-heap
struct MinHeap* createMinHeap(int capacity) {
    struct MinHeap* heap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    heap->pos = (int*)malloc(capacity * sizeof(int));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (struct HeapNode**)malloc(capacity * sizeof(struct HeapNode*));
    return heap;
}

// Swap two heap nodes
void swapHeapNode(struct HeapNode** a, struct HeapNode** b) {
    struct HeapNode* t = *a;
    *a = *b;
    *b = t;
}

// Heapify at index
void minHeapify(struct MinHeap* heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap->size && heap->array[left]->dist < heap->array[smallest]->dist)
        smallest = left;

    if (right < heap->size && heap->array[right]->dist < heap->array[smallest]->dist)
        smallest = right;

    if (smallest != idx) {
        struct HeapNode* smallestNode = heap->array[smallest];
        struct HeapNode* idxNode = heap->array[idx];

        heap->pos[smallestNode->v] = idx;
        heap->pos[idxNode->v] = smallest;

        swapHeapNode(&heap->array[smallest], &heap->array[idx]);

        minHeapify(heap, smallest);
    }
}

// Extract min node
struct HeapNode* extractMin(struct MinHeap* heap) {
    if (heap->size == 0)
        return NULL;

    struct HeapNode* root = heap->array[0];
    struct HeapNode* lastNode = heap->array[heap->size - 1];
    heap->array[0] = lastNode;

    heap->pos[root->v] = heap->size - 1;
    heap->pos[lastNode->v] = 0;

    heap->size--;
    minHeapify(heap, 0);

    return root;
}

// Decrease key
void decreaseKey(struct MinHeap* heap, int v, int dist) {
    int i = heap->pos[v];
    heap->array[i]->dist = dist;

    while (i && heap->array[i]->dist < heap->array[(i - 1) / 2]->dist) {
        heap->pos[heap->array[i]->v] = (i - 1) / 2;
        heap->pos[heap->array[(i - 1) / 2]->v] = i;
        swapHeapNode(&heap->array[i], &heap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Check if heap is empty
int isEmpty(struct MinHeap* heap) {
    return heap->size == 0;
}

// Dijkstra’s Algorithm
void dijkstra(int n, struct Node* adj[], int src) {
    int dist[n + 1];
    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    struct MinHeap* heap = createMinHeap(n);
    for (int v = 1; v <= n; v++) {
        heap->array[v - 1] = newHeapNode(v, dist[v]);
        heap->pos[v] = v - 1;
    }
    heap->size = n;

    while (!isEmpty(heap)) {
        struct HeapNode* minNode = extractMin(heap);
        int u = minNode->v;

        struct Node* crawl = adj[u];
        while (crawl != NULL) {
            int v = crawl->v;
            if (dist[u] != INT_MAX && crawl->w + dist[u] < dist[v]) {
                dist[v] = dist[u] + crawl->w;
                decreaseKey(heap, v, dist[v]);
            }
            crawl = crawl->next;
        }
    }

    // Print distances
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX)
            printf("INF ");
        else
            printf("%d ", dist[i]);
    }
    printf("\n");
}

// Driver Code
int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[n + 1];
    for (int i = 1; i <= n; i++)
        adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(adj, u, v, w);
    }

    int src;
    scanf("%d", &src);

    dijkstra(n, adj, src);

    return 0;
}
