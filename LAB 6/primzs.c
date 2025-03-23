#include<stdio.h>
#include <limits.h>  

int findMinVertex(int key[], int mstSet[], int n) {
    int min = INT_MAX, minIndex = -1;
    for (int v = 0; v < n; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void primMST(int n, int graph[n][n]) {
    int parent[n];  
    int key[n];     
    int mstSet[n];  

    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;     
    parent[0] = -1; 

    for (int count = 0; count < n - 1; count++) {
        int u = findMinVertex(key, mstSet, n);
        mstSet[u] = 1; 

        for (int v = 0; v < n; v++) {
            if (graph[u][v] != INT_MAX && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printf("Edge \tWeight\n");
    for (int i = 1; i < n; i++)
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
}

int main() {
    int n = 5;  
    int graph[5][5] = {  
        {0, 2, INT_MAX, 6, INT_MAX},
        {2, 0, 3, 8, 5},
        {INT_MAX, 3, 0, INT_MAX, 7},
        {6, 8, INT_MAX, 0, 9},
        {INT_MAX, 5, 7, 9, 0}
    };

    primMST(n, graph);
    return 0;
}
