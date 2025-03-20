#include<stdio.h>
#include<stdlib.h>
  int peak(int a[],int low,int high){
        int mid;
        mid = (low+high)/2;
        
        if(mid>0 && a[mid]<a[mid-1]){
            return peak(a,low,mid-1);
        }
        if(mid<9 && a[mid]<a[mid+1]){
            return peak(a,mid+1,high);
        }
        if ((mid == 0 || a[mid] >= a[mid - 1]) &&
        (mid == high || a[mid] >= a[mid + 1])) {
        return mid;
        } 
    }
int main(){
    int low = 0;
    int high = 9;
    int a[10]={4,7,8,1,0,4,3,2,5,10};
    int result = peak(a,low,high);
    printf("%d",result);
      return 0;
}
