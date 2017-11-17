#include <stdio.h>
#include <string.h>
int compute_num(int n);
int main(void) {
    int N;
    scanf("%d", &N);
    int end = 0;
    while(end != 6174 && N != 0) {
        end = compute_num(N);
        N = end; 
    }
}

int compute_num(int n) {
    int number_A = 0, number_B = 0;
    int a[4];
    int i = 0;
    while(i != 4) {
        int cur = n % 10;
        a[i++] = cur;
        n = n / 10;
    }
    for (int j = 0; j < 4; j++) {
        int max = j;
        for (int k = j + 1; k < 4; k++) {
            if (a[k] > a[max]) max = k;
        }
        if (max != j) {
            int temp = a[j];
            a[j] = a[max];
            a[max] = temp;
        }
    }
    number_A = a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3];
    number_B = a[3] * 1000 + a[2] * 100 + a[1] * 10 + a[0];
    if (number_A - number_B) {
        printf("%04d - %04d = %04d", number_A,number_B, number_A - number_B);
    } else {
        printf("%d - %d = %s", number_A,  number_B, "0000");
    }
    if(number_A - number_B == 6174 || number_A - number_B == 0) {
        ;
    } else {
        printf("\n");
    }
    return number_A - number_B;
}

//So stupid, only number_B < 1000 will be true..just add '0' 
//6174: 7641 - 1467 = 6174