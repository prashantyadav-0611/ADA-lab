#include <stdio.h>
#include <stdlib.h>

void swap(int arr[7][3], int x, int y) {
    int temp = arr[x][0];
    arr[x][0] = arr[y][0];
    arr[y][0] = temp;

    temp = arr[x][1];
    arr[x][1] = arr[y][1];
    arr[y][1] = temp;

    temp = arr[x][2];
    arr[x][2] = arr[y][2];
    arr[y][2] = temp;
}

void heapify(int arr[7][3], int n, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l][2] < arr[smallest][2]) {
        smallest = l;
    }
    if (r < n && arr[r][2] < arr[smallest][2]) {
        smallest = r;
    }
    if (smallest != i) {
        swap(arr, smallest, i);
        heapify(arr, n, smallest);
    }
}

void buildheap(int arr[7][3], int n) {
    for (int z = (n / 2) - 1; z >= 0; z--) {
        heapify(arr, n, z);
    }
}

void delete_min(int arr[7][3], int *n) {
    if (*n <= 0) return; 

    arr[0][0] = arr[*n - 1][0];
    arr[0][1] = arr[*n - 1][1];
    arr[0][2] = arr[*n - 1][2];

    *n = *n - 1;

    heapify(arr, *n, 0);
}

int find(int p[], int x) {
    if (p[x] < 0) return x; 
    return (p[x] = find(p, p[x])); 
}

void uni(int p[], int x, int y) {
    int rootX = find(p, x);
    int rootY = find(p, y);

    if (rootX != rootY) {
        if (p[rootX] < p[rootY]) { 
            p[rootX] += p[rootY]; 
            p[rootY] = rootX; 
        } else { 
            p[rootY] += p[rootX]; 
            p[rootX] = rootY; 
        }
    }
}

int kruskal(int arr[7][3], int edgeCount, int t[4][3]) {
    buildheap(arr, edgeCount);

    int parent[5];
    for (int i = 0; i < 5; i++) parent[i] = -1;

    int selectedEdges = 0, min_cost = 0;
    int heapSize = edgeCount;

    while (selectedEdges < 4 && heapSize > 0) {  
        int u = arr[0][0];
        int v = arr[0][1];
        int cost = arr[0][2];

        delete_min(arr, &heapSize);

        int rootU = find(parent, u);
        int rootV = find(parent, v);

        if (rootU != rootV) {
            t[selectedEdges][0] = u;
            t[selectedEdges][1] = v;
            t[selectedEdges][2] = cost;
            min_cost += cost;
            uni(parent, rootU, rootV);
            selectedEdges++;
        }
    }

    return (selectedEdges == 4) ? min_cost : -1;
}

int main() {
    int size = 7;
    int arr[7][3] = {{0, 2, 2}, {2, 3, 4}, {3, 4, 1}, {4, 1, 6}, {1, 0, 3}, {0, 3, 5}, {2, 1, 7}};
    int t[4][3]; 

    int result = kruskal(arr, size, t);

    if (result == -1) {
        printf("Spanning tree not possible\n");
        return 0;
    }

    printf("Minimum Spanning Tree edges:\n");
    for (int i = 0; i < 4; i++) {
        printf("%d -- %d (Cost: %d)\n", t[i][0], t[i][1], t[i][2]);
    }
    printf("Total Minimum Cost: %d\n", result);

    return 0;
}
