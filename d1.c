#include <stdio.h>

int main() {
    int n, pos, x;

    // 1. Input the initial size of the array
    if (scanf("%d", &n) != 1) return 0;

    // Initialize array with space for the new element
    int arr[n + 1];

    // 2. Input the n integers
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // 3. Input position and the element to insert
    scanf("%d", &pos);
    scanf("%d", &x);

    // 4. Shift elements to the right to make space
    // We start from the end (index n) and move backwards to (pos-1)
    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    // 5. Insert the element at the 1-based position (pos-1 index)
    arr[pos - 1] = x;

    // 6. Print the updated array
    for (int i = 0; i <= n; i++) {
        printf("%d%s", arr[i], (i == n) ? "" : " ");
    }
    printf("\n");

    return 0;
}
