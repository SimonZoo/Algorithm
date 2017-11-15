// Silly Code
#include <stdio.h>
#include <string.h>

int cmp(int a[], int b[], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) return 0;
    }
    return 1; // equal
}

void insert_sort(int a[], int N, int cmp_arr[]) {
    for(int i = 1; i < N; i++) {
        int j = i - 1;
        int t = a[i];
        for (; j >= 0 && a[j] > t; j--) {
            a[j + 1] = a[j];
        }
        a[j + 1] = t;
        if (cmp(a, cmp_arr, N)) {
            printf("Insertion Sort\n");
            int p = i + 1;
            int q = p - 1;
            int tt = a[p];
            for (; q >= 0 && a[q] > tt; q--) {
                a[q + 1] = a[q];
            }
            a[q + 1] = tt;
            for (int s = 0; s < N - 1; s++) printf("%d ", a[s]);
            printf("%d", a[N-1]);
            return;
        }
    }
}

void merge(int a[], int low, int mid, int high) {
    int i = low, j = mid + 1;
    int aux[high + 1];
    for (int k = low; k <= high; k++) 
        aux[k] = a[k];
    for (int k = low; k <= high; k++) {
        if (i > mid)                a[k] = aux[j++];
        else if (j > high)          a[k] = aux[i++];
        else if (aux[i] > aux[j])   a[k] = aux[j++];
        else                        a[k] = aux[i++];
    }
}
void merge_sort(int a[], int N, int cmp_arr[]) {
    for (int sz = 1; sz < N; sz = sz + sz) {
        for (int low = 0; low < N - sz; low += sz + sz) {
            int min = low + sz + sz - 1  < N - 1 ? low + sz + sz - 1 : N - 1;
            merge(a, low, low + sz - 1, min);
        }
        if (cmp(a, cmp_arr, N)) {
            printf("Merge Sort\n");
            sz = sz + sz;
            for (int low = 0; low < N - sz; low += sz + sz) {
                int min = low + sz + sz - 1  < N - 1 ? low + sz + sz - 1 : N - 1;
                merge(a, low, low + sz - 1, min);
            }
            for (int s = 0; s < N - 1; s++) printf("%d ", a[s]);
            printf("%d", a[N-1]);
            return;
        }
    }
}

int main(void) {
    int N;
    scanf("%d", &N);
    int arr[N];
    int insert[N];
    int merge[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    int sort[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &sort[i]);
    }
    memcpy(insert, arr, N*sizeof(int));
    memcpy(merge, arr, N*sizeof(int));
    merge_sort(merge, N, sort);
    insert_sort(insert, N, sort);
}