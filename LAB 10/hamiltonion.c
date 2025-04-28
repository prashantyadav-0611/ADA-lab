#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int path[MAX];  // Stores the Hamiltonian path

// Finds next valid vertex for the path
void nextVertex(int pos, int n, int G[MAX][MAX]) {
    while (1) {
        path[pos] = (path[pos] + 1) % (n + 1);
        
        if (path[pos] == 0) {
            return; // No more vertices to try
        }
        
        // Check if this vertex can be added to the path
        if (G[path[pos-1]][path[pos]]) {
            bool alreadyInPath = false;
            for (int i = 1; i < pos; i++) {
                if (path[i] == path[pos]) {
                    alreadyInPath = true;
                    break;
                }
            }
            
            if (!alreadyInPath) {
                // Check if last vertex connects back to first
                if (pos < n || (pos == n && G[path[n]][path[1]])) {
                    return; // Valid vertex found
                }
            }
        }
    }
}

// Finds Hamiltonian cycles using backtracking
void hamiltonian(int pos, int n, int G[MAX][MAX]) {
    while (1) {
        nextVertex(pos, n, G);
        
        if (path[pos] == 0) {
            return; // Backtrack
        }
        
        if (pos == n) {
            // Print the Hamiltonian cycle
            printf("Hamiltonian Cycle: ");
            for (int i = 1; i <= n; i++) {
                printf("%d ", path[i]);
            }
            printf("%d\n", path[1]); // Complete the cycle
        } else {
            hamiltonian(pos + 1, n, G);
        }
    }
}

int main() {
    // Built-in adjacency matrix (1-based indexing)
    int n = 5;  // Number of vertices
    int G[MAX][MAX] = {
        {0, 0, 0, 0, 0, 0},  // Row 0 unused
        {0, 0, 1, 0, 1, 0},  // Vertex 1 connections
        {0, 1, 0, 1, 1, 1},  // Vertex 2 connections
        {0, 0, 1, 0, 0, 1},  // Vertex 3 connections
        {0, 1, 1, 0, 0, 1},  // Vertex 4 connections
        {0, 0, 1, 1, 1, 0}   // Vertex 5 connections
    };
    
    printf("Finding Hamiltonian Cycles for Graph with %d vertices:\n", n);
    printf("Adjacency Matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d ", G[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    // Initialize path
    for (int i = 0; i <= n; i++) {
        path[i] = 0;
    }
    
    // Start with vertex 1
    path[1] = 1;
    
    printf("All Hamiltonian Cycles:\n");
    hamiltonian(2, n, G); // Start from position 2
    
    return 0;
}