#include <stdio.h>

int main(void) {
    int a, b;
    char str[10];
    scanf("%d %d", &a, &b);
    int sum = a + b;
    if (sum < 0) {
        sum = -sum;
        putchar('-');
    }
    int len = sprintf(str, "%d", sum);
    int n = (len - 1) / 3;
    int pos = len - n * 3;
    for (int i = 0; i < len; i++) {
        if (pos == i) {
            pos = pos + 3;
            putchar(',');
        }
        putchar(str[i]);
    }
}