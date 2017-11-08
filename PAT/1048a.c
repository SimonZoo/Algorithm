//题目看错卡了好久...
#include <stdio.h>
#include <string.h>

int main(void) {
    char A[110];
    char B[110];
    scanf("%s", A);
    getchar();
    scanf("%s", B);
    unsigned int len_B = strlen(B);
    unsigned int len_A = strlen(A);
    char itoc[14] = {'0', '1', '2', '3', '4', '5','6', '7', '8', '9', 'J', 'Q', 'K'};
    int len = len_A >= len_B ? len_A : len_B;
    int min = len_A <= len_B ? len_A : len_B;
    char C[len];
    int k = 0;
    if (len_A != len_B) {
        int k = 0;
        char t[len - min + 1]; 
        for (int j = 0; j < len - min; j++) {
            if (j == 0) strcpy(t, "0");
            else strcat(t, "0");
            k++;
        }
        t[k] = 0;
        if (len_A > len_B) {
            strcat(t, B);
            strcpy(B, t);
        } else {
            strcat(t, A);
            strcpy(A, t);
        }
    } 
    for(int i = 0; i < len; i++) {
        int a = A[i] - '0';
        int b = B[i] - '0';
        if ((len - i) % 2) {
            int cur = (a + b) % 13;
            C[k++] = itoc[cur];
        } else {
            int cur = b - a;            
            if (cur < 0) cur = cur + 10;
            C[k++] = itoc[cur];
        }
    }
    C[k] = 0;
    printf("%s", C);
}