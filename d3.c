#include <stdio.h>

int main() {
    int n, k, comparisons = 0, foundIndex = -1;

    // 1. Input array size
    if (scanf("%d", &n) != 1) return 0;

    int arr[n];

    // 2. Input array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // 3. Input the key to search
    scanf("%d", &k);

    // 4. Linear Search Process
    for (int i = 0; i < n; i++) {
        comparisons++; // Increment for every check made
        if (arr[i] == k) {
            foundIndex = i;
            break; // Stop searching once found
        }
    }

    // 5. Output Results
    if (foundIndex != -1) {
        printf("Found at index %d\n", foundIndex);
    } else {
        printf("Not Found\n");
    }
    printf("Comparisons = %d\n", comparisons);

    return 0;
}
