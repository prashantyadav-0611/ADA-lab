#include<stdio.h>
#include<stdlib.h>

void swap(int arr[7][3],int x,int y){
    int temp = arr[x][0];
    arr[x][0]=arr[y][0];
    arr[y][0]=temp;
     temp = arr[x][1];
    arr[x][1]=arr[y][1];
    arr[y][1]=temp;
     temp = arr[x][2];
    arr[x][2]=arr[y][2];
    arr[y][2]=temp;
}

void heapify(int arr[7][3],int n,int i){
int smallest=i;
int l=2*i +1;
int r =2*i +2;

if(l<n && arr[l][2]<arr[smallest][2]){
    smallest = l;
}

if(r<n && arr[r][2]<arr[smallest][2]){
    smallest=r;
}

if(smallest!=i){
    swap(arr,smallest,i);
    heapify(arr,n,smallest);
}
}

void buildheap(int arr[7][3],int n){
    int index=(n/2)-1;
    for(int z=index;z>=0;z--){
    heapify(arr,n,z);
    }
}

int main(){
int arr[7][3]={{0,2,2},{2,3,4},{3,4,1},{4,1,6},{1,0,3},{0,3,5},{2,1,7}};
buildheap(arr,7);
for(int j=0;j<7;j++){
    printf("\n %d",arr[j][2]);
}
return 0;
}