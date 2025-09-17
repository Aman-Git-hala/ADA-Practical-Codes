#include <stdio.h>
#include <time.h>

long long fib_iterative(int n) {
    if (n <= 1) return n;
    long long a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    clock_t start = clock();
    long long res = fib_iterative(n);
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1e6;
    printf("Iterative Fibonacci(%d) = %lld, Time = %.2f microseconds\n", n, res, time_taken);
    return 0;
}
