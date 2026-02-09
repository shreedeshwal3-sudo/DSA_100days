#include <stdio.h>

int main() {
    int p, q;

    // 1. Read first log size and elements
    if (scanf("%d", &p) != 1) return 0;
    int log1[p];
    for (int i = 0; i < p; i++) scanf("%d", &log1[i]);

    // 2. Read second log size and elements
    if (scanf("%d", &q) != 1) return 0;
    int log2[q];
    for (int i = 0; i < q; i++) scanf("%d", &log2[i]);

    // 3. Merge process using two pointers
    int i = 0, j = 0;
    int first = 1; // Helper to manage space-separated printing

    while (i < p && j < q) {
        if (!first) printf(" ");
        
        if (log1[i] <= log2[j]) {
            printf("%d", log1[i]);
            i++;
        } else {
            printf("%d", log2[j]);
            j++;
        }
        first = 0;
    }

    // 4. Print remaining elements from log1 (if any)
    while (i < p) {
        printf(" %d", log1[i]);
        i++;
    }

    // 5. Print remaining elements from log2 (if any)
    while (j < q) {
        printf(" %d", log2[j]);
        j++;
    }

    printf("\n");
    return 0;
}
