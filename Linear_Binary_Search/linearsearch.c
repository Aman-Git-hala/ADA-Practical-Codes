#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++)
        if (arr[i] == key) return i;
    return -1;
}

int main() {
    srand(time(0));
    int sizes[5];
    for (int i = 0; i < 5; i++) sizes[i] = (rand() % 900000) + 100000;
    for (int i = 0; i < 5; i++) {
        int n = sizes[i];
        int *arr = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) arr[j] = j;
        int key = n - 1;
        clock_t start = clock();
        int index = linearSearch(arr, n, key);
        clock_t end = clock();
        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1e6;
        printf("Test %d: n=%d, Time=%.2f microseconds\n", i + 1, n, time_taken);
        free(arr);
    }
    return 0;
}
