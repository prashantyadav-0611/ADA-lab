#include <stdio.h>
#include <limits.h>

#define INF INT_MAX
#define N 4  // Number of cities

int tsp(int pos, int visited_mask, int dp[N][1 << N], int path[N][1 << N], int cost[N][N]) {
    if (visited_mask == (1 << N) - 1)
        return cost[pos][0];

    if (dp[pos][visited_mask] != -1)
        return dp[pos][visited_mask];

    int minCost = INF, bestCity = -1;

    for (int city = 0; city < N; city++) {
        if ((visited_mask & (1 << city)) == 0) {
            int newMask = visited_mask | (1 << city);
            int newCost = cost[pos][city] + tsp(city, newMask, dp, path, cost);

            if (newCost < minCost) {
                minCost = newCost;
                bestCity = city;
            }
        }
    }

    path[pos][visited_mask] = bestCity;
    return dp[pos][visited_mask] = minCost;
}

void printPath(int path[N][1 << N]) {
    int pos = 0, visited_mask = 1;
    printf("Optimal Path: %d", pos);

    for (int i = 1; i < N; i++) {
        int nextCity = path[pos][visited_mask];
        if (nextCity == -1) break;
        printf(" --> %d", nextCity);
        visited_mask |= (1 << nextCity);
        pos = nextCity;
    }

    printf(" --> 0\n");  // Return to starting city
}

int main() {
    int cost[N][N] = {
        { 0, 10, 15, 20 },
        { 5,  0,  9, 10 },
        { 6, 13,  0, 12 },
        { 8,  8,  9,  0 }
    };

    int dp[N][1 << N];
    int path[N][1 << N];

    // Initialize dp and path arrays
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < (1 << N); j++) {
            dp[i][j] = -1;
            path[i][j] = -1;
        }
    }

    printf("Using cost matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%3d ", cost[i][j]);
        }
        printf("\n");
    }

    int minCost = tsp(0, 1, dp, path, cost);

    if (minCost == INF) {
        printf("No valid tour exists.\n");
    } else {
        printf("Minimum cost of travelling: %d\n", minCost);
        printPath(path);
    }

    return 0;
}
