#include <stdio.h>
#include <stdlib.h>

int* solve(int T, int** edges) {
    int* finalans = malloc(T * sizeof(int));
    for (int i = 0; i < T; i++) {
        int n = edges[i][0];
        int m = edges[i][1];
        int k = edges[i][2];
        int* A = edges[i] + 3;
        int count = 0;
        for (int i = 0; i < n; i++) {
            int product = 1;
            for (int j = i; j < n; j++) {
                product = (product * A[j]) % m;
                if (product == k) {
                    count++;
                }
            }
        }
        finalans[i] = count;
    }
    return finalans;
}

int main() {
    int t;
    scanf("%d", &t);
    int** edges = malloc(t * sizeof(int*));
    for (int i = 0; i < t; i++) {
        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);
        int* arr = malloc((n + 3) * sizeof(int));
        arr[0] = n;
        arr[1]=m;
        arr[2] = k;
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[j + 3]);
        }
        edges[i] = arr;
    }
    int* ans = solve(t, edges);
    for (int i = 0; i < t; i++) {
        printf("%d\n", ans[i]);
    }
    for (int i = 0; i < t; i++) {
        free(edges[i]);
    }
    free(edges);
    free(ans);
    return 0;
}
