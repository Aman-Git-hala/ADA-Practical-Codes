#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void add(int **A, int **B, int **C, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void sub(int **A, int **B, int **C, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void strassen(int **A, int **B, int **C, int n) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }
    int k = n / 2;
    int **A11 = (int**)malloc(k * sizeof(int*));
    int **A12 = (int**)malloc(k * sizeof(int*));
    int **A21 = (int**)malloc(k * sizeof(int*));
    int **A22 = (int**)malloc(k * sizeof(int*));
    int **B11 = (int**)malloc(k * sizeof(int*));
    int **B12 = (int**)malloc(k * sizeof(int*));
    int **B21 = (int**)malloc(k * sizeof(int*));
    int **B22 = (int**)malloc(k * sizeof(int*));
    int **C11 = (int**)malloc(k * sizeof(int*));
    int **C12 = (int**)malloc(k * sizeof(int*));
    int **C21 = (int**)malloc(k * sizeof(int*));
    int **C22 = (int**)malloc(k * sizeof(int*));
    int **M1 = (int**)malloc(k * sizeof(int*));
    int **M2 = (int**)malloc(k * sizeof(int*));
    int **M3 = (int**)malloc(k * sizeof(int*));
    int **M4 = (int**)malloc(k * sizeof(int*));
    int **M5 = (int**)malloc(k * sizeof(int*));
    int **M6 = (int**)malloc(k * sizeof(int*));
    int **M7 = (int**)malloc(k * sizeof(int*));
    int **AResult = (int**)malloc(k * sizeof(int*));
    int **BResult = (int**)malloc(k * sizeof(int*));
    for (int i = 0; i < k; i++) {
        A11[i] = (int*)malloc(k * sizeof(int));
        A12[i] = (int*)malloc(k * sizeof(int));
        A21[i] = (int*)malloc(k * sizeof(int));
        A22[i] = (int*)malloc(k * sizeof(int));
        B11[i] = (int*)malloc(k * sizeof(int));
        B12[i] = (int*)malloc(k * sizeof(int));
        B21[i] = (int*)malloc(k * sizeof(int));
        B22[i] = (int*)malloc(k * sizeof(int));
        C11[i] = (int*)malloc(k * sizeof(int));
        C12[i] = (int*)malloc(k * sizeof(int));
        C21[i] = (int*)malloc(k * sizeof(int));
        C22[i] = (int*)malloc(k * sizeof(int));
        M1[i] = (int*)malloc(k * sizeof(int));
        M2[i] = (int*)malloc(k * sizeof(int));
        M3[i] = (int*)malloc(k * sizeof(int));
        M4[i] = (int*)malloc(k * sizeof(int));
        M5[i] = (int*)malloc(k * sizeof(int));
        M6[i] = (int*)malloc(k * sizeof(int));
        M7[i] = (int*)malloc(k * sizeof(int));
        AResult[i] = (int*)malloc(k * sizeof(int));
        BResult[i] = (int*)malloc(k * sizeof(int));
    }

    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }

    add(A11, A22, AResult, k);
    add(B11, B22, BResult, k);
    strassen(AResult, BResult, M1, k);

    add(A21, A22, AResult, k);
    strassen(AResult, B11, M2, k);

    sub(B12, B22, BResult, k);
    strassen(A11, BResult, M3, k);

    sub(B21, B11, BResult, k);
    strassen(A22, BResult, M4, k);

    add(A11, A12, AResult, k);
    strassen(AResult, B22, M5, k);

    sub(A21, A11, AResult, k);
    add(B11, B12, BResult, k);
    strassen(AResult, BResult, M6, k);

    sub(A12, A22, AResult, k);
    add(B21, B22, BResult, k);
    strassen(AResult, BResult, M7, k);

    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++) {
            C11[i][j] = M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j];
            C12[i][j] = M3[i][j] + M5[i][j];
            C21[i][j] = M2[i][j] + M4[i][j];
            C22[i][j] = M1[i][j] - M2[i][j] + M3[i][j] + M6[i][j];
        }

    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++) {
            C[i][j] = C11[i][j];
            C[i][j + k] = C12[i][j];
            C[i + k][j] = C21[i][j];
            C[i + k][j + k] = C22[i][j];
        }

    for (int i = 0; i < k; i++) {
        free(A11[i]); free(A12[i]); free(A21[i]); free(A22[i]);
        free(B11[i]); free(B12[i]); free(B21[i]); free(B22[i]);
        free(C11[i]); free(C12[i]); free(C21[i]); free(C22[i]);
        free(M1[i]); free(M2[i]); free(M3[i]); free(M4[i]); free(M5[i]); free(M6[i]); free(M7[i]);
        free(AResult[i]); free(BResult[i]);
    }

    free(A11); free(A12); free(A21); free(A22);
    free(B11); free(B12); free(B21); free(B22);
    free(C11); free(C12); free(C21); free(C22);
    free(M1); free(M2); free(M3); free(M4); free(M5); free(M6); free(M7);
    free(AResult); free(BResult);
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
    strassen(A, B, C, n);
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1e6;
    printf("Strassen Recursive Time: %.2f microseconds\n", time_taken);
    for (int i = 0; i < n; i++) {
        free(A[i]); free(B[i]); free(C[i]);
    }
    free(A); free(B); free(C);
    return 0;
}
