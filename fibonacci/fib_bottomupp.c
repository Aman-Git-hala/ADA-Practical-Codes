#include <stdio.h>
#include <time.h>

long long fib_bottomup(int n) {
    if (n <= 1) return n;
    long long fib[n + 1];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++) fib[i] = fib[i - 1] + fib[i - 2];
    return fib[n];
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    clock_t start = clock();
    long long res = fib_bottomup(n);
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1e6;
    printf("DP Bottom-Up Fibonacci(%d) = %lld, Time = %.2f microseconds\n", n, res, time_taken);
    return 0;
}
