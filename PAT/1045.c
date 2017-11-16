#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void*b) {
    return *(int*)a - *(int*)b;
}
int main(void) {
    int arr[100000], aux[100000], key[100000];
    int N;
    int max = 0, k = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
        aux[i] = arr[i];
    }
    qsort(arr, N, sizeof(arr[0]), cmp);
    for (int i = 0; i < N; i++) {
        if (arr[i] == aux[i] && aux[i] > max) {
            key[k++] = aux[i];
        } 
        if (aux[i] > max) max = aux[i];
    }
    printf("%d\n", k);
    if (k != 0) {
        for (int i = 0; i < k - 1; i++) {
        printf("%d ", key[i]);
    }
        printf("%d", key[k - 1]);
    }
    printf("\n");
}