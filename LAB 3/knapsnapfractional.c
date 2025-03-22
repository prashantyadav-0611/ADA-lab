#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void sort(int a[3][20],int cat){
    for(int i=0;i<19;i++){
        for(int j=0;j<19-i;j++){
            if(a[cat][j]<a[cat][j+1]){
                int temp = a[0][j];
                a[0][j]=a[0][j+1];
                a[0][j+1]=temp;
                temp = a[1][j];
                a[1][j]=a[1][j+1];
                a[1][j+1]=temp;
                temp = a[2][j];
                a[2][j]=a[2][j+1];
                a[2][j+1]=temp;
            }
        }
    }
}
int main(){
    int arr[3][20];
    printf("s.no  profit1 profit2    profit3   maxprofit\n");
    for(int k=0;k<20;k++){
    int profit[3]={0,0,0};
    int maxprofit=0;
    int cap=100;
    int index;
    for(int i=0;i<20;i++){
        arr[0][i] = rand()%150;
        arr[1][i] = 1+rand()%15;
        arr[2][i] = (double)arr[0][i]/arr[1][i];
    }
    sort(arr,0);
    for( index=0;cap>arr[1][index] && index<20;index++){
        cap=cap-arr[1][index];
        profit[0]=profit[0]+arr[0][index];
    }
    if (index <20 ) profit[0] += ((double)arr[0][index] / arr[1][index]) * cap;
    sort(arr,1);
    cap=100;
    for( index=19;index>=0 && cap>arr[1][index];index--){
        cap=cap-arr[1][index];
        profit[1]=profit[1]+arr[0][index];
    }
if (index >= 0) profit[1] += ((double)arr[0][index] / arr[1][index]) * cap;    sort(arr,2);
    sort(arr,2);
    cap=100;
    for( index=0;cap>arr[1][index] && index<20;index++){
        cap=cap-arr[1][index];
        profit[2]=profit[2]+arr[0][index];
    }
    if (index <20 ) profit[2] += ((double)arr[0][index] / arr[1][index]) * cap;
    maxprofit=profit[0];
   if(profit[0]<profit[1]){
    maxprofit=profit[1];
   }
   if(profit[2]>maxprofit){
    maxprofit=profit[2];
   }
   printf("%d     %d      %d       %d       %d\n",k+1,profit[0],profit[1],profit[2],maxprofit);
//     printf("profit ");
//     for(int i=0;i<5;i++){
//         printf("%d  ",arr[0][i]);
//     }
//     printf("\n");
//     printf("weight ");
//     for(int i=0;i<5;i++){
//         printf("%d  ",arr[1][i]);
//     }
//     printf("\n");
//     printf("p/w ");
//     for(int i=0;i<5;i++){
//         printf("%d  ",arr[2][i]);
//     }
//     printf("\n");
//     sort(arr,0);
//     printf("profit ");
//     for(int i=0;i<5;i++){
//         printf("%d  ",arr[0][i]);
//     }
//     printf("\n");
//     printf("weight ");
//     for(int i=0;i<5;i++){
//         printf("%d  ",arr[1][i]);
//     }
//     printf("\n");
//     printf("p/w ");
//     for(int i=0;i<5;i++){
//         printf("%d  ",arr[2][i]);
//     }
//     printf("\n");
//    sort(arr,1);
//     printf("profit ");
//     for(int i=0;i<5;i++){
//         printf("%d  ",arr[0][i]);
//     }
//     printf("\n");
//     printf("weight ");
//     for(int i=0;i<5;i++){
//         printf("%d  ",arr[1][i]);
//     }
//     printf("\n");
//     printf("p/w ");
//     for(int i=0;i<5;i++){
//         printf("%d  ",arr[2][i]);
//     }
//     printf("\n");
//     sort(arr,2);
//     printf("profit ");
//     for(int i=0;i<5;i++){
//         printf("%d  ",arr[0][i]);
//     }
//     printf("\n");
//     printf("weight ");
//     for(int i=0;i<5;i++){
//         printf("%d  ",arr[1][i]);
//     }
//     printf("\n");
//     printf("p/w ");
//     for(int i=0;i<5;i++){
//         printf("%d  ",arr[2][i]);
//     }
//     printf("\n");
   }
return 0;
}