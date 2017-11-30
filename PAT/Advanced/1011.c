#include <stdio.h>

int main(void) {
    char flag[4] = {'W', 'T', 'L'};
    double number[3][3];
    int max[3];
    int max_pos = 0;
    double sum = 1.0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%lf", &number[i][j]);
            if (number[i][j] > number[i][max_pos])
                max_pos = j;
        }
        max[i] = max_pos;
    }
    for (int i = 0; i < 3; i++) {
        printf("%c ", flag[max[i]]);
        sum = sum * number[i][max[i]];
    }
    sum = (sum * 0.65 - 1) * 2;
    printf("%.2lf", sum);
}