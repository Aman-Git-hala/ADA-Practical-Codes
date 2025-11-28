#include <stdio.h>

#define MAX 100

int n;
int adj[MAX][MAX];
int visited[MAX];

void dfs(int u) {
    int i;
    visited[u] = 1;
    printf("%d ", u + 1);
    for (i = 0; i < n; i++)
        if (adj[u][i] && !visited[i])
            dfs(i);
}

int main() {
    int m;
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

    dfs(start);
    printf("\n");
    return 0;
}
