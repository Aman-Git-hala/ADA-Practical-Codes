#include <stdio.h>

#define MAX 100

int main() {
    int n;
    int s[MAX], f[MAX], idx[MAX];
    int i, j;

    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &s[i]);
    for (i = 0; i < n; i++) scanf("%d", &f[i]);

    for (i = 0; i < n; i++) idx[i] = i;

    for (i = 0; i < n - 1; i++) {
        int minPos = i;
        for (j = i + 1; j < n; j++) {
            if (f[idx[j]] < f[idx[minPos]]) minPos = j;
        }
        if (minPos != i) {
            int temp = idx[i];
            idx[i] = idx[minPos];
            idx[minPos] = temp;
        }
    }

    int last = 0;
    printf("%d ", idx[0] + 1);
    for (i = 1; i < n; i++) {
        if (s[idx[i]] >= f[idx[last]]) {
            printf("%d ", idx[i] + 1);
            last = i;
        }
    }
    printf("\n");

    return 0;
}
