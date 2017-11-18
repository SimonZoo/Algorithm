#include <stdio.h>

int main(void) {
    int k1, k2;
    float sum[1001] = {0};
    int s = 0;
    int e;
    float c;
    scanf("%d", &k1);
    for (int i = 0; i < k1; i++) {
        scanf("%d %f", &e, &c);
        sum[e] += c;
    }
    scanf("%d", &k2);
    for (int i = 0; i < k2; i++) {
        scanf("%d %f", &e, &c);
        sum[e] += c;
    }
    for (int i = 0; i < 1001; i++) {
        if (sum[i] != 0.0) {
            s++;
        }
    }
    printf("%d", s);
    for(int i = 1000; i >= 0; i--) {
        if (sum[i] != 0) {
            printf(" %d %.1f", i, sum[i]);
        } 
    }
}