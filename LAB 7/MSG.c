#include <stdio.h>
#include <limits.h>

#define INF INT_MAX
#define N 8 

void shortestPath(int graph[N][N], int n) {
    int fdist[N]; 
    int path[N]; 

    
    for (int i = 0; i < n; i++) {
        fdist[i] = INF;
        path[i] = -1;
    }

    fdist[n - 1] = 0;


    for (int i = n - 2; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            if (graph[i][j] != 0) {
                if (fdist[i] > graph[i][j] + fdist[j]) {
                    fdist[i] = graph[i][j] + fdist[j];
                    path[i] = j;
                }
            }
        }
    }

    printf("Minimum cost from source to destination: %d\n", fdist[0]);


    printf("Path: ");
    int temp = 0;
    while (temp != -1) {
        printf("%d ", temp);
        temp = path[temp];
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
