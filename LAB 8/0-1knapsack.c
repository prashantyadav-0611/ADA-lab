#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int p;
    int w;
} pw;

int compare(const void* a, const void* b) {
    pw* pa = (pw*)a;
    pw* pb = (pw*)b;
    if (pa->w != pb->w)
        return pa->w - pb->w;
    return pa->p - pb->p;
}

int is_equal(pw a, pw b) {
    return a.p == b.p && a.w == b.w;
}

int exists(pw* arr, int size, pw target) {
    for (int i = 0; i < size; i++) {
        if (is_equal(arr[i], target))
            return 1;
    }
    return 0;
}

pw* merge_purge(pw* S1, int size1, pw* S2, int size2, int* new_size) {
    pw* merged = (pw*)malloc((size1 + size2) * sizeof(pw));
    int i = 0, j = 0, k = 0;

    // Merge
    while (i < size1 && j < size2) {
        if (compare(&S1[i], &S2[j]) <= 0)
            merged[k++] = S1[i++];
        else
            merged[k++] = S2[j++];
    }
    while (i < size1) merged[k++] = S1[i++];
    while (j < size2) merged[k++] = S2[j++];

    // Purge
    pw* purged = (pw*)malloc(k * sizeof(pw));
    int max_p = -1, purged_size = 0;
    for (int m = 0; m < k; m++) {
        if (merged[m].p > max_p) {
            purged[purged_size++] = merged[m];
            max_p = merged[m].p;
        }
    }

    free(merged);
    *new_size = purged_size;
    return purged;
}

void solve_knp(int n, int* p, int* w, int W, pw** S, int* sizes) {
    S[0] = (pw*)malloc(sizeof(pw));
    S[0][0].p = 0;
    S[0][0].w = 0;
    sizes[0] = 1;

    for (int i = 1; i <= n; i++) {
        pw* S_i_prev = (pw*)malloc(sizes[i - 1] * sizeof(pw));
        int count = 0;
        for (int j = 0; j < sizes[i - 1]; j++) {
            int new_p = S[i - 1][j].p + p[i - 1];
            int new_w = S[i - 1][j].w + w[i - 1];
            if (new_w <= W) {
                S_i_prev[count].p = new_p;
                S_i_prev[count].w = new_w;
                count++;
            }
        }

        int new_size;
        S[i] = merge_purge(S[i - 1], sizes[i - 1], S_i_prev, count, &new_size);
        sizes[i] = new_size;
        free(S_i_prev);
    }
}

void trace_knp(pw** S, int* sizes, int n, int* p, int* w, int* x) {
    for (int i = 0; i < n; i++) x[i] = 0;

    pw current = S[n][sizes[n] - 1];

    for (int i = n; i >= 1; i--) {
        pw prev = {current.p - p[i - 1], current.w - w[i - 1]};
        if (exists(S[i - 1], sizes[i - 1], prev)) {
            x[i - 1] = 1;
            current = prev;
        }
    }
}

int main() {
    int n = 4;
    int p[] = {1, 2, 3, 4};
    int w[] = {2, 3, 4, 5};
    int W = 10;

    pw* S[100]; // assume n <= 100
    int sizes[100];

    solve_knp(n, p, w, W, S, sizes);

    if (sizes[n] == 0) {
        printf("No feasible solution!\n");
    } else {
        pw optimal = S[n][sizes[n] - 1];
        printf("Optimal solution:\n");
        printf("Total profit p = %d\n", optimal.p);
        printf("Total weight w = %d\n", optimal.w);

        int x[100];
        trace_knp(S, sizes, n, p, w, x);
        printf("Selected items (x_i values): ");
        for (int i = 0; i < n; i++) {
            printf("%d ", x[i]);
        }
        printf("\n");
    }

    for (int i = 0; i <= n; i++) free(S[i]);

    return 0;
}
