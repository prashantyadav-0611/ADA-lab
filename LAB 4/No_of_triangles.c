#include <stdio.h>
#include <stdlib.h>

int isCollinear(int x1, int y1, int x2, int y2, int x3, int y3) {
    int area = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);
    if(area!=0){
        return 0;
    }
    else return 1;
}

int countTriangles(int points[][2], int n) {
    if (n < 3) return 0; 

    int totalTriangles = (n * (n - 1) * (n - 2)) / 6; 
    int collinearCount = 0;

    
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if (isCollinear(points[i][0], points[i][1],
                                points[j][0], points[j][1],
                                points[k][0], points[k][1])) {
                    collinearCount++;
                }
            }
        }
    }

    return totalTriangles - collinearCount;
}

int main() {
    int n;
    printf("Enter the number of points: ");
    scanf("%d", &n);

    int points[n][2];
    for (int i = 0; i < n; i++) {
        printf("Enter coordinates of point %d: ", i + 1);
        scanf("%d %d", &points[i][0], &points[i][1]);
    }

    int result = countTriangles(points, n);
    printf("Number of non-collinear triangles: %d\n", result);

    return 0;
}
