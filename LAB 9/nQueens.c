#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>  // Add this to use bool, true, false

bool place(int k, int i, int* x) {
    for (int j = 0; j < k; j++) {
        if (x[j] == i || abs(j - k) == abs(x[j] - i)) {
            return false;
        }
    }
    return true;
}

void print(int* x, int n) {
    printf("\nSolution:\n");
    for (int p = 0; p < n; p++) {
        for (int q = 0; q < n; q++) {
            if (x[p] == q) {
                printf("1 ");
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

void NQueens(int k, int n, int* x) {
    for (int i = 0; i < n; i++) {
        if (place(k, i, x)) {
            x[k] = i;
            if (k == n - 1) {
                print(x, n);
            } else {
                NQueens(k + 1, n, x);
            }
        }
    }
}

int main() {
    printf("Enter the number of queens: ");
    int n;
    scanf("%d", &n);
    int* x = (int*)malloc(n * sizeof(int));
    NQueens(0, n, x);
    free(x);
    return 0;
}
