#include <stdio.h>

int main() {
    int n;

    // 1. Input the size of the array
    if (scanf("%d", &n) != 1) return 0;
    
    // Handle empty array case
    if (n == 0) return 0;

    int arr[n];

    // 2. Input the sorted array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // 3. In-place duplicate removal logic
    // j tracks the index of the last unique element
    int j = 0;
    for (int i = 1; i < n; i++) {
        // If we find a new unique element
        if (arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }

    // 4. Output the unique elements (from index 0 to j)
    for (int i = 0; i <= j; i++) {
        printf("%d%s", arr[i], (i == j) ? "" : " ");
    }
    printf("\n");

    return 0;
}
