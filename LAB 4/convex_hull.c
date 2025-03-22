#include <stdio.h>
#include <stdlib.h>

int orientation(int x1, int y1, int x2, int y2, int x, int y) {
    int D = (x - x1) * (y2 - y1) - (y - y1) * (x2 - x1);
    return (D > 0) ? 1 : (D < 0) ? -1 : 0;
}

int main() {
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    float arr[n][3]; // Stores x, y, and slope values

    // Input vertices
    for (int i = 0; i < n; i++) {
        printf("Enter the coordinates of %dth point: ", i + 1);
        scanf("%f %f", &arr[i][0], &arr[i][1]);
        arr[i][2] = 0.0; // Initialize slope value
    }

    // Find the lowest point (smallest y-value)
    for (int i = 1; i < n; i++) {
        if (arr[i][1] < arr[0][1]) {
            float temp[2];
            temp[0] = arr[0][0];
            temp[1] = arr[0][1];
            arr[0][0] = arr[i][0];
            arr[0][1] = arr[i][1];
            arr[i][0] = temp[0];
            arr[i][1] = temp[1];
        }
    }

    arr[0][2] = 0.0; // Reference point has slope 0

    // Calculate slopes 
    for (int i = 1; i < n; i++) {
        if (arr[i][0] == arr[0][0]) { 
            arr[i][2] = __FLT_MAX__; 
        } else {
            arr[i][2] = (arr[i][1] - arr[0][1]) / (arr[i][0] - arr[0][0]);
        }
    }

    // Bubble Sort 
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - i; j++) {
            if (arr[j][2] > arr[j + 1][2]) {
                float temp[3];
                temp[0] = arr[j][0];
                temp[1] = arr[j][1];
                temp[2] = arr[j][2];
                arr[j][0] = arr[j + 1][0];
                arr[j][1] = arr[j + 1][1];
                arr[j][2] = arr[j + 1][2];
                arr[j + 1][0] = temp[0];
                arr[j + 1][1] = temp[1];
                arr[j + 1][2] = temp[2];
            }
        }
    }

    printf("\nSorted Points (x, y, slope):\n");
    for (int i = 0; i < n; i++) {
        printf("%f %f %f\n", arr[i][0], arr[i][1], arr[i][2]);
    }

    return 0;
}
