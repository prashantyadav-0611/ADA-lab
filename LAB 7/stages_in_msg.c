#include <stdio.h>
#define MAX_NODES 100

int findStages(int graph[MAX_NODES][MAX_NODES], int n) { 
    int stages =0;
    int i=0;
        for(int j=0; j<n ;j++){
            if(graph[i][j]!=0){
                stages++;
                i=j;
                j=-1;
            }
        }
        
    return stages+2;//one for source stage and one for sink stage
}

int main() {
    
    int graph[MAX_NODES][MAX_NODES] = {
        {0, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 0, 0},
        {0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0}
    };
    
    int n = 7;
    int stages = findStages(graph, n);
    printf("Number of stages in the multistage graph: %d\n", stages);
    return 0;
}
