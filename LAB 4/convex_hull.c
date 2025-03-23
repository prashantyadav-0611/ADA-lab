#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int orientation(int x1, int y1, int x2, int y2, int x, int y) {
    int D = (x - x1) * (y2 - y1) - (y - y1) * (x2 - x1);
    return (D > 0) ? 1 : (D < 0) ? -1 : 0;
}

int distance(int x1, int y1, int x2, int y2, int x, int y) {
    return abs((y2 - y1) * x - (x2 - x1) * y + x2 * y1 - y2 * x1);
}

void addPoint(int outputarr[][2], int *j, int x, int y) {
    for (int k = 0; k < *j; k++) {
        if (outputarr[k][0] == x && outputarr[k][1] == y) {
            return; 
        }
    }
    outputarr[*j][0] = x;
    outputarr[*j][1] = y;
    (*j)++;
}


void quickHull(int arr[][2], int n, int x1, int y1, int x2, int y2, int outputarr[][2], int *j) {
    int subArr[n][2]; 
    int count = 0;

    
    for (int i = 0; i < n; i++) {
        if (orientation(x1, y1, x2, y2, arr[i][0], arr[i][1]) > 0) {
            subArr[count][0] = arr[i][0];
            subArr[count][1] = arr[i][1];
            count++;
        }
    }

    
    if (count == 0) {
        addPoint(outputarr, j, x1, y1);
        addPoint(outputarr, j, x2, y2);
        return;
    }

    
    int farthestIndex = 0, maxDist = 0;
    for (int i = 0; i < count; i++) {
        int d = distance(x1, y1, x2, y2, subArr[i][0], subArr[i][1]);
        if (d > maxDist) {
            maxDist = d;
            farthestIndex = i;
        }
    }

    
    quickHull(subArr, count, subArr[farthestIndex][0], subArr[farthestIndex][1], x1, y1, outputarr, j);
    quickHull(subArr, count, subArr[farthestIndex][0], subArr[farthestIndex][1], x2, y2, outputarr, j);
}

int main() {
    int n;
    printf("Enter the number of points: ");
    scanf("%d", &n);

    int arr[n][2];
    for (int i = 0; i < n; i++) {
        printf("Enter coordinates of point %d: ", i + 1);
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }

    int outputarr[2 * n][2]; 
    int j = 0; 
    int min_x = 0, max_x = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i][0] < arr[min_x][0]) min_x = i;
        if (arr[i][0] > arr[max_x][0]) max_x = i;
    }

    // Compute the convex hull for upper and lower halves
    quickHull(arr, n, arr[min_x][0], arr[min_x][1], arr[max_x][0], arr[max_x][1], outputarr, &j);
    quickHull(arr, n, arr[max_x][0], arr[max_x][1], arr[min_x][0], arr[min_x][1], outputarr, &j);

    
    printf("Convex Hull points:\n");
    for (int i = 0; i < j; i++) {
        printf("(%d, %d)\n", outputarr[i][0], outputarr[i][1]);
    }

    return 0;
}
