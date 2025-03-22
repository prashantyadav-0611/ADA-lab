#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sssp(int v, int cost[6][6], int n, int dist[6], int flag[6]) {
    for (int i = 0; i < n; i++) {
        dist[i] = cost[v][i]; 
        flag[i] = 0; 
    }
    flag[v] = 1; 

    for (int j = 1; j < n - 1; j++) {
        int u = -1;
        int minDist = 999;

        
        for (int k = 0; k < n; k++) {
            if (flag[k] == 0 && dist[k] < minDist) {
                minDist = dist[k];
                u = k;
            }
        }

        if (u == -1) break;

        flag[u] = 1; 

        for (int w = 0; w < n; w++) {
            if (flag[w] == 0 && cost[u][w] < 99) { 
                if (dist[w] > dist[u] + cost[u][w]) {
                    dist[w] = dist[u] + cost[u][w];
                }
            }
        }
    }

    
    printf("Shortest distances from source vertex %d:\n", v);
    for (int d = 0; d < n; d++) {
        printf("%d  ", dist[d]);
    }
    printf("\n");
}

int main() {
    srand(time(0));
    int cost[6][6], flag[6] = {0}; 
    int v, n = 6;
    int dist[6]; 


    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (i == j) {
                cost[i][j] = 0; 
            } else {
                cost[i][j] = rand() % 50;
                if (cost[i][j] > 10) {
                    cost[i][j] = 99; 
                }
            }
        }
    }

    
    printf("Cost Matrix:\n");
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            printf("%2d  ", cost[i][j]);
        }
        printf("\n");
    }

    
    printf("Enter the source vertex (0-5): ");
    scanf("%d", &v);
    
    sssp(v, cost, n, dist, flag);

    return 0;
}
