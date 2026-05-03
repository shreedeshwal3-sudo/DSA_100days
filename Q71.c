/*Problem Statement
Implement a hash table using quadratic probing with formula:

h(k, i) = (h(k) + i*i) % m

Input Format
Same as previous.

Output Format
Result of SEARCH operations.

Sample Input
7
4
INSERT 49
INSERT 56
SEARCH 49
SEARCH 15

Sample Output
FOUND
NOT FOUND

Explanation
Collisions resolved using i² jumps.
*/
#include <stdio.h>
#include <string.h>

#define SIZE 100
#define EMPTY -1

int table[SIZE];
int m; // table size

// hash function
int hash(int key) {
    return key % m;
}

// insert
void insert(int key) {
    int h = hash(key);

    for(int i = 0; i < m; i++) {
        int index = (h + i*i) % m;

        if(table[index] == EMPTY) {
            table[index] = key;
            return;
        }
    }

    printf("Hash table full\n");
}

// search
void search(int key) {
    int h = hash(key);

    for(int i = 0; i < m; i++) {
        int index = (h + i*i) % m;

        if(table[index] == EMPTY) {
            printf("NOT FOUND\n");
            return;
        }

        if(table[index] == key) {
            printf("FOUND\n");
            return;
        }
    }

    printf("NOT FOUND\n");
}

int main() {
    int q;
    scanf("%d", &m);   // table size
    scanf("%d", &q);   // number of operations

    // initialize
    for(int i = 0; i < m; i++) {
        table[i] = EMPTY;
    }

    while(q--) {
        char op[10];
        int key;

        scanf("%s %d", op, &key);

        if(strcmp(op, "INSERT") == 0) {
            insert(key);
        }
        else if(strcmp(op, "SEARCH") == 0) {
            search(key);
        }
    }

    return 0;
}