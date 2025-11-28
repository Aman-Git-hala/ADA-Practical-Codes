#include <stdio.h>

#define MAX 100

int main() {
    int n, m;
    int adj[MAX][MAX];
    int visited[MAX];
    int queue[MAX];
    int front = 0, rear = 0;
    int i, j;

    scanf("%d %d", &n, &m);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            adj[i][j] = 0;

    for (i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        adj[u][v] = adj[v][u] = 1;
    }

    for (i = 0; i < n; i++)
        visited[i] = 0;

    int start;
    scanf("%d", &start);
    start--;

    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        int u = queue[front++];
        printf("%d ", u + 1);
        for (i = 0; i < n; i++) {
            if (adj[u][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
    return 0;
}
