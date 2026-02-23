#include <stdio.h>

int main() {
    int m, n;
    if (scanf("%d %d", &m, &n) != 2) return 0;

    int mat[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    if (m != n) {
        printf("Not a Symmetric Matrix\n");
        return 0;
    }

    int symmetric = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < i; j++) {
            if (mat[i][j] != mat[j][i]) {
                symmetric = 0;
                break;
            }
        }
        if (!symmetric) break;
    }

    if (symmetric) {
        printf("Symmetric Matrix\n");
    } else {
        printf("Not a Symmetric Matrix\n");
    }

    return 0;
}
