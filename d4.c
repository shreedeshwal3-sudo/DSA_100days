#include <stdio.h>

int main() {
    int n;

    // 1. Input the size of the array
    if (scanf("%d", &n) != 1) return 0;

    int arr[n];

    // 2. Input the array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // 3. Two-pointer approach to reverse in-place
    int left = 0;
    int right = n - 1;
    while (left < right) {
        // Swap arr[left] and arr[right]
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        // Move pointers closer to the middle
        left++;
        right--;
    }

    // 4. Output the reversed array
    for (int i = 0; i < n; i++) {
        printf("%d%s", arr[i], (i == n - 1) ? "" : " ");
    }
    printf("\n");

    return 0;
}
