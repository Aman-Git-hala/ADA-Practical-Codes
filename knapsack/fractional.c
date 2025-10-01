#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Item {
    int value, weight;
};

int cmp(const void *a, const void *b) {
    double r1 = (double)((struct Item *)a)->value / ((struct Item *)a)->weight;
    double r2 = (double)((struct Item *)b)->value / ((struct Item *)b)->weight;
    if (r1 < r2) return 1;
    if (r1 > r2) return -1;
    return 0;
}

double fractionalKnapsack(int W, struct Item arr[], int n) {
    qsort(arr, n, sizeof(struct Item), cmp);
    double totalValue = 0.0;
    for (int i = 0; i < n; i++) {
        if (arr[i].weight <= W) {
            W -= arr[i].weight;
            totalValue += arr[i].value;
        } else {
            totalValue += arr[i].value * ((double)W / arr[i].weight);
            break;
        }
    }
    return totalValue;
}

int main() {
    int n, W;
    printf("Enter number of items and capacity: ");
    scanf("%d %d", &n, &W);
    struct Item arr[n];
    printf("Enter values: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i].value);
    printf("Enter weights: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i].weight);
    clock_t start = clock();
    double res = fractionalKnapsack(W, arr, n);
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1e6;
    printf("Max value = %.2f, Time = %.2f microseconds\n", res, time_taken);
    return 0;
}
