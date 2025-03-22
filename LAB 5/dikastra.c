#include<stdio.h>
#include<stdlib.h>
#include<time.h>
sssp(int v,int cost[6][6],int n,int dist[6],int flag[6]){
    for(int i=0;i<n;i++){
        dist[i]=cost[v][i];
        flag[i]=0;
    }
    flag[v]=1;
    for(int j=1;j<n-2;j++){
        int u=6;
        dist[u]=999;
        
        for(int k=0;k<n;k++){
            if(dist[u]>dist[k]&&flag[k]==0){
                u=k;
            }
        }
        flag[u]=1;
        for(int w=0;w<n;w++){
            if(cost[u][w]<99){
                if(dist[w]>dist[u]+cost[w][u]){
                    dist[u]=dist[u]+cost[w][u];
                }
            }
        }
    }
    for(int d=0;d<n;d++){
        printf("%d  ",dist[d]);
    }
}
int main(){
    srand(time(0));
    int cost[6][6];
    int flag[4]={0,0,0,0};
    int v,n=6;
    int dist[7];
    for(int i=0;i<6;i++){
        for (int j=0;j<6;j++){
            if(i==j){
                cost[i][j]=0;
            }
            else{
            cost[i][j]=rand()%50;}
            if(cost[i][j]>10){
                cost[i][j]=99;
            }
        }
    }
    for(int i=0;i<6;i++){
        for (int j=0;j<6;j++){
            printf("%d  ",cost[i][j]);
        }
        printf("\n");
    }
    printf("enter the source vertex(0-5)");
    scanf("%d",&v);
    sssp(v,cost,n,dist,flag);
    return 0;
}