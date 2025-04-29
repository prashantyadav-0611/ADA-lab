#include <stdio.h>
#include <stdbool.h>

#define MAX 100

void nextValue(int k, int n, int m, int G[MAX][MAX], int x[MAX]) {
    while (1) {
        x[k] = (x[k] + 1) % (m + 1); 
        
        if (x[k] == 0) {
            return; 
        }
        
        
        bool valid = true;
        for (int i = 1; i <= n; i++) {
            if (G[k][i] && x[i] == x[k]) {
                valid = false;
                break;
            }
        }
        
        if (valid) {
            return; 
        }
    }
}

void mColoring(int k, int n, int m, int G[MAX][MAX], int x[MAX]) {
    while (1) {
        nextValue(k, n, m, G, x);
        
        if (x[k] == 0) {
            return; 
        }
        
        if (k == n) {
            
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
    int n = 4;  
    int m;      
    int x[MAX]; 
    
    
    int G[MAX][MAX] = {
        {0, 0, 0, 0, 0},  
        {0, 0, 1, 1, 1},  
        {0, 1, 0, 1, 0},  
        {0, 1, 1, 0, 1},  
        {0, 1, 0, 1, 0}   
    };
    
    printf("Graph Coloring Problem\n");
    printf("Vertices: 4\n");
    printf("Edges: 1-2, 1-3, 1-4, 2-3, 3-4\n\n");
    
    printf("Enter number of colors: ");
    scanf("%d", &m);
    
    
    for (int i = 0; i <= n; i++) {
        x[i] = 0;
    }
    
    printf("\nAll valid colorings with %d colors:\n", m);
    mColoring(1, n, m, G, x);
    
    return 0;
}