#include <stdio.h>
#include <time.h>

long long memo[100000];

long long fib_topdown(int n) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    memo[n] = fib_topdown(n - 1) + fib_topdown(n - 2);
    return memo[n];
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) memo[i] = -1;
    clock_t start = clock();
    long long res = fib_topdown(n);
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1e6;
    printf("DP Top-Down Fibonacci(%d) = %lld, Time = %.2f microseconds\n", n, res, time_taken);
    return 0;
}
