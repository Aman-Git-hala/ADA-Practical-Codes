#include <stdio.h>
#include <time.h>

long long fib_recursive(int n) {
    if (n <= 1) return n;
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    clock_t start = clock();
    long long res = fib_recursive(n);
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1e6;
    printf("Recursive Fibonacci(%d) = %lld, Time = %.2f microseconds\n", n, res, time_taken);
    return 0;
}
