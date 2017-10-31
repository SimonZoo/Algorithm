#include <stdio.h>
#include <string.h>
#define LEN 1002

int main(void) {
    char A[LEN],Q[LEN];
    int B, R;
    scanf("%s %d", A, &B);
    int rest = 0;
    int q = 0;
    for (int i = 0; i < strlen(A); i++) {
        rest = rest * 10 + A[i] - '0';
        if (i == 0 && strlen(A) > 1 && A[i] - '0' < B) {
            //在有大于一位数的情况下，如果第一位数小于B，那么往后再取
        } else {
            Q[q++] = rest / B + '0';
        }
        rest = rest % B;
    }
    Q[q] = 0;
    R = rest;
    printf("%s %d", Q, R);
}
//两位两位取数，逐步拿到商，最后拿到余数