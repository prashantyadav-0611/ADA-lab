#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int path[MAX];  


void nextVertex(int pos, int n, int G[MAX][MAX]) {
    while (1) {
        path[pos] = (path[pos] + 1) % (n + 1);
        
        if (path[pos] == 0) {
            return; 
        }
        
        
        if (G[path[pos-1]][path[pos]]) {
            bool alreadyInPath = false;
            for (int i = 1; i < pos; i++) {
                if (path[i] == path[pos]) {
                    alreadyInPath = true;
                    break;
                }
            }
            
            if (!alreadyInPath) {

                if (pos < n || (pos == n && G[path[n]][path[1]])) {
                    return; 
                }
            }
        }
    }
}


void hamiltonian(int pos, int n, int G[MAX][MAX]) {
    while (1) {
        nextVertex(pos, n, G);
        
        if (path[pos] == 0) {
            return; 
        }
        
        if (pos == n) {
            printf("Hamiltonian Cycle: ");
            for (int i = 1; i <= n; i++) {
                printf("%d ", path[i]);
            }
            printf("%d\n", path[1]); 
        } else {
            hamiltonian(pos + 1, n, G);
        }
    }
}

int main() {
    
    int n = 5;  
    int G[MAX][MAX] = {
        {0, 0, 0, 0, 0, 0},  
        {0, 0, 1, 0, 1, 0},  
        {0, 1, 0, 1, 1, 1},
        {0, 0, 1, 0, 0, 1},  
        {0, 1, 1, 0, 0, 1},  
        {0, 0, 1, 1, 1, 0}   
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
    
    
    for (int i = 0; i <= n; i++) {
        path[i] = 0;
    }
    
    
    path[1] = 1;
    
    printf("All Hamiltonian Cycles:\n");
    hamiltonian(2, n, G); 
    
    return 0;
}