#include <stdio.h>
#include <stdlib.h>
int cmp(const void* a, const void* b) {
    return *((int*)b) - *((int*)a);
}
int main(void) {
    int N;
    scanf("%d", &N);
    int num[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &num[i]);
    }
    qsort(num, N, sizeof(num[0]), cmp);
    int min = 9999;
    int max_m = 0;
    for (int m = N; m * m >= N; m--) {
        int n = N / m;
        if (m * n == N && m >= n &&(m - n) < min) {
            min = m - n;
            max_m = m;
        }
    }
    int n = N / max_m;
    int arr[max_m][n];
    int t = 0;
    int level = max_m / 2 + max_m % 2; 
    for (int i = 0; i < level; i++) {
        for (int j = i; j <= n - 1 - i && t <= N - 1; j++) {
            arr[i][j] = num[t++];
        }
        for (int j = i + 1; j <= max_m - 2 - i && t <= N - 1; j++) {
            arr[j][n - 1 - i] = num[t++];
        }
        for (int j = n - 1 - i; j >= i && t <= N - 1; j--) {
            arr[max_m - 1 - i][j] = num[t++];
        }
        for (int j = max_m - 2 - i; j >= i + 1 && t <= N - 1; j--) {
            arr[j][i] = num[t++];
        }
    }  
    for (int i = 0; i < max_m; i++) {
        for (int j = 0; j < n - 1; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("%d", arr[i][n - 1]);
        printf("\n");
    }
}