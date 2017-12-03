#include <stdio.h>
#include <stdlib.h>

int cmp(const void* p1, const void* p2) {
    return *(int*)p2 - *(int*)p1;
}

int main(void) {
    int n, k, sum = 0;
    scanf("%d", &n);
    int coupon[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &coupon[i]);
    }
    scanf("%d", &k);
    int produce[k];
    for (int i = 0; i < k; i++) {
        scanf("%d", &produce[i]);
    }
    qsort(coupon, n, sizeof(coupon[0]), cmp);
    qsort(produce, k, sizeof(produce[0]), cmp);
    int p1 = 0, p2 = 0;
    while (p1 < n && p2 < k && coupon[p1] > 0 && produce[p2] > 0) {
        sum = sum + coupon[p1] * produce[p2];
        p1++;
        p2++;
    }
    p1 = n - 1, p2 = k - 1;
    while (p1 > 0 && p2 > 0 && coupon[p1] < 0 && produce[p2] < 0) {
        sum = sum + coupon[p1] * produce[p2];
        p1--;
        p2--;
    }
    printf("%d", sum);
}