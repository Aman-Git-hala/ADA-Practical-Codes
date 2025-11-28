#include <stdio.h>

#define MAX 100

void multiply(int A[][MAX], int B[][MAX], int C[][MAX],
              int i, int j, int k, int n, int m, int p) {
    if (i >= n) return;
    if (j >= p) {
        multiply(A, B, C, i + 1, 0, 0, n, m, p);
        return;
    }
    if (k < m) {
        C[i][j] += A[i][k] * B[k][j];
        multiply(A, B, C, i, j, k + 1, n, m, p);
    } else {
        multiply(A, B, C, i, j + 1, 0, n, m, p);
    }
}

int main() {
    int n, m, p;
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    int i, j;

    scanf("%d %d %d", &n, &m, &p);

    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &A[i][j]);

    for (i = 0; i < m; i++)
        for (j = 0; j < p; j++)
            scanf("%d", &B[i][j]);

    for (i = 0; i < n; i++)
        for (j = 0; j < p; j++)
            C[i][j] = 0;

    multiply(A, B, C, 0, 0, 0, n, m, p);

    for (i = 0; i < n; i++) {
        for (j = 0; j < p; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }

    return 0;
}
