#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
} 
int main(void) {
    int N;
    scanf("%d", &N);
    int couple[100000];
    memset(couple, -1, 2 * N * sizeof(int));
    for (int i = 0; i < N; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        couple[a] = b;
        couple[b] = a;
    }
    int guest_num;
    int single = 0;
    int k = 0;
    scanf("%d", &guest_num);
    int guest[guest_num];
    int single_guest[guest_num];
    for (int i = 0; i < guest_num; i++) {
        int cur;
        scanf("%d", &cur);
        if (couple[cur] == -1) {
            single_guest[single++] = cur;
            continue;
        } else {
            guest[k++] = cur; 
        }
    }
    for (int i = 0; i < k; i++) {
        int flag = 1;
        int cur = guest[i];
        for (int j = 0; j < k; j++) {
            if (i != j && couple[cur] == guest[j]) {
                flag = 0;
            }
        }
        if (flag) {
            single_guest[single++] = cur;
        }
    }
    qsort(single_guest, single, sizeof(single_guest[0]), cmp);
    printf("%d", single); // single = 0 时不要换行
    if (single == 0) {
        return 0;
    } else {
        printf("\n");
    }
    for (int i = 0; i < single - 1; i++) {
        printf("%05d ", single_guest[i]);
    } 
    printf("%05d", single_guest[single - 1]);
}