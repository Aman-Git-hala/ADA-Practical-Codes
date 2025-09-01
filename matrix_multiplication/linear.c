#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void multiply(int **A, int **B, int **C, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
}

int main() {
    int n;
    printf("Enter matrix size (power of 2): ");
    scanf("%d", &n);
    int **A = (int**)malloc(n * sizeof(int*));
    int **B = (int**)malloc(n * sizeof(int*));
    int **C = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        A[i] = (int*)malloc(n * sizeof(int));
        B[i] = (int*)malloc(n * sizeof(int));
        C[i] = (int*)malloc(n * sizeof(int));
    }
    srand(time(0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            A[i][j] = rand() % 100;
            B[i][j] = rand() % 100;
        }
    clock_t start = clock();
    multiply(A, B, C, n);
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1e6;
    printf("Iterative Matrix Multiplication Time: %.2f microseconds\n", time_taken);
    for (int i = 0; i < n; i++) {
        free(A[i]); free(B[i]); free(C[i]);
    }
    free(A); free(B); free(C);
    return 0;
}
