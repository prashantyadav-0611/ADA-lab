#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int partition(int arr[], int low, int high) {
    int pivot = arr[high];  
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}


void QSI(int arr[], int low, int high) {
    int stack[100];  
    int top = -1;

    
    while (low < high || top >= 0) {  
        while (low < high) {
            int j = partition(arr, low, high);

            if (j - low > high - j) {  
                stack[++top] = low;
                stack[++top] = j - 1;
                low = j + 1;
            } else {  
                stack[++top] = j + 1;
                stack[++top] = high;
                high = j - 1;
            }
        }
        if (top >= 0) {
            high = stack[top--];
            low = stack[top--];
        }
    }
}

int main() {
    int n;
    
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n]; 
    
    srand(time(0));//if i will not use this it will generate same numbers again and again

    printf("Generated Unsorted Array: ");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;  
        printf("%d ", arr[i]);
    }
    printf("\n");

    QSI(arr, 0, n - 1);

    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
