#include <stdio.h> 
int main(void) {
    int N,M;
    scanf("%d %d", &N, &M);
    int arr[2*N];
    int times = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
        arr[i + N] = arr[i];
    }
    int loop = M % N;
    for (int i = N - loop; i < 2 * N - loop - 1; i++) {
        printf("%d ", arr[i]);
    }
    //直接取M个数更好..
    printf("%d", arr[2 * N - loop - 1]);
}