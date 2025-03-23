#include<stdio.h>
#include<stdlib.h>

void sort(int a[3][20], int cat) {
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19 - i; j++) {
            if (a[cat][j] > a[cat][j + 1]) { 
                for (int k = 0; k < 3; k++) {
                    int temp = a[k][j];
                    a[k][j] = a[k][j + 1];
                    a[k][j + 1] = temp;
                }
            }
        }
    }
}

int selectActivities(int a[3][20]) {
    int count = 1;
    int lastEnd = a[1][0];
    for (int i = 1; i < 20; i++) {
        if (a[0][i] >= lastEnd) {
            count++;
            lastEnd = a[1][i];
        }
    }
    return count;
}

int main() {
    int arr[3][20];
    printf("s.no  By Start Time  By End Time  By Duration  Max Activities\n");
    
    for (int k = 0; k < 20; k++) {
        int activities[3] = {0, 0, 0};
        int maxActivities = 0;
        
        for (int i = 0; i < 20; i++) {
            arr[0][i] = rand() % 50; 
            arr[1][i] = arr[0][i] + (1 + rand() % 10); 
            arr[2][i] = arr[1][i] - arr[0][i]; 
        }
        
        sort(arr, 0);
        activities[0] = selectActivities(arr);
        
        sort(arr, 1);
        activities[1] = selectActivities(arr);
        
        sort(arr, 2);
        activities[2] = selectActivities(arr);
        
        maxActivities = activities[0];
        if (activities[1] > maxActivities) maxActivities = activities[1];
        if (activities[2] > maxActivities) maxActivities = activities[2];
        
        printf("%d       %d           %d           %d           %d\n", k + 1, activities[0], activities[1], activities[2], maxActivities);
    }
    return 0;
}
