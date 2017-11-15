#include <stdio.h>


int main(void) {
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    int h = 1;
    while(h < N / 3) h = 3 * h + 1;
    while(h >= 1) {
        for (int i = h; i < N; i = i + h) {
            int t = arr[i];
            int j = i - h;
            for (; j >= 0 && arr[j] > t; j = j - h) {
                arr[j + h] = arr [j];
            }
            arr[j + h] = t;
        }
        h = h / 3;
    }
    for (int i = 0; i < N; i++) printf("%d ", arr[i]);
}