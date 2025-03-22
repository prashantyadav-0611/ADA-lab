#include <stdio.h>

void min_max(int arr[], int low, int high, int *min, int *max) {
    if (low == high) {
        *max = *min = arr[low];  // Fix pointer usage
        return;
    }

    int mid = (low + high) / 2;
    int min1, max1;

    min_max(arr, low, mid, min, max);
    min_max(arr, mid + 1, high, &min1, &max1); // Pass addresses

    if (*max < max1) {
        *max = max1;
    }
    if (*min > min1) {
        *min = min1;
    }
}

int main() {
    int arr[10] = {7, 5, 9, 1, 4, 8, 2, 6, 3, 10};
    int max, min;
    
    min_max(arr, 0, 9, &min, &max);
    printf("Max = %d\nMin = %d\n", max, min);

    return 0;
}
