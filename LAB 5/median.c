#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


int partition(int arr[], int left, int right) {
    int pivot = arr[right];  
    int i = left;  
    
    for (int j = left; j < right; j++) {
        if (arr[j] < pivot) {  
            swap(&arr[i], &arr[j]);  
            i++;
        }
    }
    swap(&arr[i], &arr[right]);  
    return i;  
}

int quickSelect(int arr[], int left, int right, int k) {
    if (left <= right) {
        int pivotIndex = partition(arr, left, right);

        if (pivotIndex == k) 
            return arr[pivotIndex];  
        else if (pivotIndex > k)  
            return quickSelect(arr, left, pivotIndex - 1, k);  
        else  
            return quickSelect(arr, pivotIndex + 1, right, k);  
    }
    return -1;  
}

int findMedian(int arr[], int n) {
    int mid = n / 2;

    if (n % 2 == 1) {
        return quickSelect(arr, 0, n - 1, mid);  
    } else {
        int a = quickSelect(arr, 0, n - 1, mid - 1);
        int b = quickSelect(arr, 0, n - 1, mid);
        return (a + b) / 2;  
    }
}

int main() {
    int arr[] = {12, 3, 5, 7, 19, 26, 13, 2, 10, 15};
    int n = sizeof(arr) / sizeof(arr[0]);

    int median = findMedian(arr, n);
    printf("Median: %d\n", median);

    return 0;
}
