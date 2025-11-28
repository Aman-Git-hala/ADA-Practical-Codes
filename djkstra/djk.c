#include <stdio.h>

#define MAXN 100
#define INF 1000000000

int main() {
    int n, m;
    int adj[MAXN][MAXN];
    int dist[MAXN];
    int visited[MAXN];
    int i, j;

    scanf("%d %d", &n, &m);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j) adj[i][j] = 0;
            else adj[i][j] = INF;
        }
    }

    for (i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        u--; v--;
        if (w < adj[u][v]) {
            adj[u][v] = w;
            adj[v][u] = w;
        }
    }

    int src;
    scanf("%d", &src);
    src--;

    for (i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[src] = 0;

    for (i = 0; i < n - 1; i++) {
        int u = -1;
        int minDist = INF;
        for (j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                u = j;
            }
        }
        if (u == -1) break;
        visited[u] = 1;

        for (j = 0; j < n; j++) {
            if (!visited[j] && adj[u][j] < INF) {
                if (dist[u] + adj[u][j] < dist[j]) {
                    dist[j] = dist[u] + adj[u][j];
                }
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (dist[i] == INF) printf("INF ");
        else printf("%d ", dist[i]);
    }
    printf("\n");

    return 0;
}
