#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void print(int** s, int i, int j) {
    if (i == j) {
        printf("A%d ", i);
    } else {
        printf("( ");
        print(s, i, s[i][j]);
        print(s, s[i][j] + 1, j);
        printf(") ");
    }
}

void mcm(int* p, int n, int** s, int** m) {
    for (int i = 1; i < n; i++) {
        m[i][i] = 0;
    }

    for (int l = 2; l < n; l++) { // l = chain length
        for (int i = 1; i < n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of matrices: ");
    scanf("%d", &n);

    int* p = (int*)malloc((n + 1) * sizeof(int));
    printf("Enter dimensions (length %d): ", n + 1);
    for (int i = 0; i < n + 1; i++) {
        scanf("%d", &p[i]);
    }

    int** m = (int**)malloc((n + 1) * sizeof(int*));
    int** s = (int**)malloc((n + 1) * sizeof(int*));
    for (int i = 0; i <= n; i++) {
        m[i] = (int*)malloc((n + 1) * sizeof(int));
        s[i] = (int*)malloc((n + 1) * sizeof(int));
    }

    mcm(p, n + 1, s, m);

    printf("Minimum number of scalar multiplications: %d\n", m[1][n]);
    printf("Optimal Parenthesization: ");
    print(s, 1, n);
    printf("\n");

    for (int i = 0; i <= n; i++) {
        free(m[i]);
        free(s[i]);
    }
    free(m);
    free(s);
    free(p);

    return 0;
}
