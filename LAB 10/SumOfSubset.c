#include <stdio.h>
#include <stdlib.h>

void print(int* arr, int* x, int n) {
    printf("Solution: \n");
    for(int i = 0; i < n; i++) {
        if(x[i] == 1) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

void sum_subsequence(int k, int* x, int* arr, int s, int r, int m, int n) {
    if(k >= n) {
        if(s == m) print(arr, x, n);
        return;
    }
    else { // include
        x[k] = 1;
        if(s + arr[k] <= m) sum_subsequence(k + 1, x, arr, s + arr[k], r - arr[k], m, n);
    }

    if(s + r - arr[k] >= m) {
        x[k] = 0;
        sum_subsequence(k + 1, x, arr, s, r - arr[k], m, n);
    }
}

int main() {
    printf("Enter size: ");
    int n, s = 0, m;
    scanf("%d", &n);
    
    printf("Enter elements: ");
    int* arr = (int*)malloc(n * sizeof(int));
    int* x = (int*)malloc(n * sizeof(int));
    
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        s += arr[i];
        x[i] = 0;
    }

    printf("Enter the sum: ");
    scanf("%d", &m);
    
    sum_subsequence(0, x, arr, 0, s, m, n);
    
    free(arr);
    free(x);
    
    return 0;
}