#include <stdio.h>

int main() {
    int n, pos;

    // 1. Input the size of the array
    if (scanf("%d", &n) != 1) return 0;

    int arr[n];

    // 2. Input the n integers
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // 3. Input the 1-based position to delete
    scanf("%d", &pos);

    // Validate position to avoid out-of-bounds access
    if (pos < 1 || pos > n) {
        // If invalid, we print original array or handle error
        for (int i = 0; i < n; i++) {
            printf("%d%s", arr[i], (i == n - 1) ? "" : " ");
        }
    } else {
        // 4. Shift elements to the left
        // Start from the deletion point (pos-1) and pull elements forward
        for (int i = pos - 1; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }

        // 5. Print the updated array (n-1 elements)
        for (int i = 0; i < n - 1; i++) {
            printf("%d%s", arr[i], (i == n - 2) ? "" : " ");
        }
    }
    
    printf("\n");

    return 0;
}
