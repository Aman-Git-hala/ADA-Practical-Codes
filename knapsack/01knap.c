#include <stdio.h>
#include <string.h>
#include <time.h>

int max(int a, int b) { return (a > b) ? a : b; }

int dp[101][1001];
int wt[101], val[101];

int knapsack(int n, int W) {
    if (n == 0 || W == 0) return 0;
    if (dp[n][W] != -1) return dp[n][W];
    if (wt[n - 1] <= W)
        dp[n][W] = max(val[n - 1] + knapsack(n - 1, W - wt[n - 1]), knapsack(n - 1, W));
    else
        dp[n][W] = knapsack(n - 1, W);
    return dp[n][W];
}

int main() {
    int n, W;
    printf("Enter number of items and capacity: ");
    scanf("%d %d", &n, &W);
    printf("Enter values: ");
    for (int i = 0; i < n; i++) scanf("%d", &val[i]);
    printf("Enter weights: ");
    for (int i = 0; i < n; i++) scanf("%d", &wt[i]);
    memset(dp, -1, sizeof(dp));
    clock_t start = clock();
    int res = knapsack(n, W);
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1e6;
    printf("Max value = %d, Time = %.2f microseconds\n", res, time_taken);
    return 0;
}
