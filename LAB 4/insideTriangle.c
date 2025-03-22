#include <stdio.h>

int orientation(int x1, int y1, int x2, int y2, int x, int y) {
    int D = (x - x1) * (y2 - y1) - (y - y1) * (x2 - x1);
    return (D > 0) ? 1 : (D < 0) ? -1 : 0; 
}

int InsideTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y) {
    int o1 = orientation(x1, y1, x2, y2, x, y);
    int o2 = orientation(x2, y2, x3, y3, x, y);
    int o3 = orientation(x3, y3, x1, y1, x, y);

    
    if(o1 == o2 && o2 == o3)
        return  1;
    else 
        return 0;
    
}

int main() {
    int x1, y1, x2, y2, x3, y3, x, y;

    printf("Enter coordinates of the first vertex (x1, y1): ");
    scanf("%d %d", &x1, &y1);
    
    printf("Enter coordinates of the second vertex (x2, y2): ");
    scanf("%d %d", &x2, &y2);
    
    printf("Enter coordinates of the third vertex (x3, y3): ");
    scanf("%d %d", &x3, &y3);
    
    printf("Enter coordinates of the point to check (x, y): ");
    scanf("%d %d", &x, &y);

    if (InsideTriangle(x1, y1, x2, y2, x3, y3, x, y))
        printf("The point (%d, %d) is INSIDE the triangle.\n", x, y);
    else
        printf("The point (%d, %d) is OUTSIDE the triangle.\n", x, y);

    return 0;
}
