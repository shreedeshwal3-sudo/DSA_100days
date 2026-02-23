#include <stdio.h>

int main() {
    int m, n;
    if (scanf("%d %d", &m, &n) != 2) return 0;

    int mat1[m][n], mat2[m][n];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d", mat1[i][j] + mat2[i][j]);
            if (j < n - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
