#include <stdio.h>

int main(void) {
    int N;
    scanf("%d", &N);
    double number;
    double sum = 0;
    for (int i = 0; i < N; i++) {
        scanf("%lf", &number);
        sum = sum + number * (N - (i + 1) + 1) * (i + 1);
    }
    printf("%.2lf", sum);
}