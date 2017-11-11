#include <stdio.h>
#include <stdlib.h>

int cmp(const void*a, const void* b) {
    return *(int*)a - *(int*)b;
}
int main(void) {
    int N, D;
    float e;
    float may_vacant = 0;
    float vacant = 0;
    scanf("%d %f %d", &N, &e, &D);
    for (int i = 0; i < N; i++) {
        int k;
        scanf("%d", &k);
        float observe[k];
        for (int j = 0; j < k; j++) {
            scanf("%f", &observe[j]);
        }
        qsort(observe, k, sizeof(observe[0]), cmp);
        if (k > D && observe[k/2] < e) {
            vacant++;
            // for (int p = 0; p < k; p++) printf("%f  ", observe[p]);
            // printf("1 \n");
        }
        else if (observe[k/2] < e){
            may_vacant++;
            // for (int p = 0; p < k; p++) printf("%f  ", observe[p]);
            // printf("2 \n");
        }   
    }
    printf("%.1f%% %.1f%%", may_vacant/N * 100, vacant/ N * 100);
}