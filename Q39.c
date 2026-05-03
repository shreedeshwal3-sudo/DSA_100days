/*Problem Statement:
Implement a Min Heap using an array where the smallest element is always at the root.

Supported Operations:
- insert x
- extractMin
- peek

Input Format:
- First line contains integer N
- Next N lines contain heap operations

Output Format:
- Print results of extractMin and peek
- Print -1 if operation cannot be performed

Example:
Input:
6
insert 40
insert 10
insert 30
peek
extractMin
peek

Output:
10
10
30
*/
#include <stdio.h>

int heap[1000];
int size = 0;

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

void insert(int x){
    heap[size] = x;
    int i = size;
    size++;

    while(i > 0){
        int parent = (i - 1) / 2;
        if(heap[parent] > heap[i]){
            swap(&heap[parent], &heap[i]);
            i = parent;
        } else break;
    }
}

int extractMin(){
    if(size == 0) return -1;

    int min = heap[0];
    heap[0] = heap[size - 1];
    size--;

    int i = 0;
    while(2*i + 1 < size){
        int left = 2*i + 1;
        int right = 2*i + 2;
        int smallest = i;

        if(left < size && heap[left] < heap[smallest])
            smallest = left;
        if(right < size && heap[right] < heap[smallest])
            smallest = right;

        if(smallest != i){
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        } else break;
    }

    return min;
}

int peek(){
    if(size == 0) return -1;
    return heap[0];
}

int main(){
    int n;
    scanf("%d", &n);

    char op[20];
    int x;

    for(int i = 0; i < n; i++){
        scanf("%s", op);

        if(op[0] == 'i'){
            scanf("%d", &x);
            insert(x);
        }
        else if(op[0] == 'e'){
            int res = extractMin();
            printf("%d\n", res);
        }
        else if(op[0] == 'p'){
            int res = peek();
            printf("%d\n", res);
        }
    }

    return 0;
}