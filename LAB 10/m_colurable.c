#include <stdio.h>
#include <stdbool.h>

#define MAX 100

void nextValue(int k, int n, int m, int G[MAX][MAX], int x[MAX]) {
    while (1) {
        x[k] = (x[k] + 1) % (m + 1); // Try next color
        
        if (x[k] == 0) {
            return; // No more colors to try
        }
        
        // Check if color is valid for all adjacent vertices
        bool valid = true;
        for (int i = 1; i <= n; i++) {
            if (G[k][i] && x[i] == x[k]) {
                valid = false;
                break;
            }
        }
        
        if (valid) {
            return; // Found valid color
        }
    }
}

void mColoring(int k, int n, int m, int G[MAX][MAX], int x[MAX]) {
    while (1) {
        nextValue(k, n, m, G, x);
        
        if (x[k] == 0) {
            return; // Backtrack
        }
        
        if (k == n) {
            // Print solution
            printf("Valid coloring: ");
            for (int i = 1; i <= n; i++) {
                printf("Vertex %d=%d  ", i, x[i]);
            }
            printf("\n");
        } else {
            mColoring(k + 1, n, m, G, x);
        }
    }
}

int main() {
    int n = 4;  // Number of vertices
    int m;      // Number of colors
    int x[MAX]; // Color assignments
    
    // Initialize graph adjacency matrix (1-based indexing)
    int G[MAX][MAX] = {
        {0, 0, 0, 0, 0},  // Row 0 unused
        {0, 0, 1, 1, 1},  // Vertex 1
        {0, 1, 0, 1, 0},  // Vertex 2
        {0, 1, 1, 0, 1},  // Vertex 3
        {0, 1, 0, 1, 0}   // Vertex 4
    };
    
    printf("Graph Coloring Problem\n");
    printf("Vertices: 4\n");
    printf("Edges: 1-2, 1-3, 1-4, 2-3, 3-4\n\n");
    
    printf("Enter number of colors: ");
    scanf("%d", &m);
    
    // Initialize color assignments
    for (int i = 0; i <= n; i++) {
        x[i] = 0;
    }
    
    printf("\nAll valid colorings with %d colors:\n", m);
    mColoring(1, n, m, G, x);
    
    return 0;
}