#include <stdio.h>
#include <limits.h>

#define INF INT_MAX
#define N 8 

void shortestPath(int graph[N][N], int n) {
    int dist[N]; 
    int path[N]; 
    int visited[N];

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        path[i] = -1;
        visited[i] = 0;
    }

    dist[0] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = -1;

        
        for (int i = 0; i < n; i++) {
            if (!visited[i] && (u == -1 || dist[i] < dist[u])) {
                u = i;
            }
        }

        if (u == -1) break;

        visited[u] = 1;

        
        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0 && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                path[v] = u;
            }
        }
    }

    printf("Minimum cost from source to destination: %d\n", dist[n - 1]);

    
    printf("Path: ");
    int stack[N], top = -1;
    int temp = n - 1;
    while (temp != -1) {
        stack[++top] = temp;
        temp = path[temp];
    }
    while (top >= 0) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
}

int main() {
    int graph[N][N] = {
        {0, 1, 2, 0, 0, 0, 0, 0},
        {0, 0, 0, 3, 6, 0, 0, 0},
        {0, 0, 0, 0, 0, 4, 2, 0},
        {0, 0, 0, 0, 0, 0, 0, 5},
        {0, 0, 0, 0, 0, 0, 0, 2},
        {0, 0, 0, 0, 0, 0, 0, 3},
        {0, 0, 0, 0, 0, 0, 0, 4},
        {0, 0, 0, 0, 0, 0, 0, 0}
    };

    shortestPath(graph, N);
    return 0;
}
