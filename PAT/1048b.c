#include <stdio.h>
#include <string.h>

void swap(char* a, char*b) {
    int t = *a;
    *a = *b;
    *b = t;
}
int main(void) {
    char A[110];
    char B[110];
    scanf("%s", A);
    getchar();
    scanf("%s", B);
    unsigned int len_A = strlen(A);
    unsigned int len_B = strlen(B);
    int len = len_A >= len_B ? len_A : len_B;
    char C[len];
    int k = 0;
    char str[14] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'J', 'Q', 'K'};
    if (len_A > 1) {
        for (int i = 0; i < len_A / 2; i++)
            swap(&A[i], &A[len_A-1-i]);
    }
    if (len_B > 1) {
        for (int i = 0; i < len_B / 2; i++)
            swap(&B[i], &B[len_B-1-i]);
    }
    if (len_A > len_B) {
        for(int i = 0; i < len_A - len_B; i++)
            strcat(B, "0");
    } else {
        for(int i = 0; i < len_B - len_A; i++)
            strcat(A, "0");
    }
    for (int i = 0; i < len; i++) {
        if (i % 2 == 0) {
            C[k++] = str[(A[i] - '0' + B[i] - '0') % 13];
        } else {
            int temp = B[i] - A[i];
            if (temp < 0) temp = temp + 10;
            C[k++] = str[temp];
        }
    }
    C[k] = 0;
    for(int i = k - 1; i >= 0; i--) {
        printf("%c", C[i]);
    }
}
