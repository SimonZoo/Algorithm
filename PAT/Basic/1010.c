#include <stdio.h>
int main(void) {
    int number[8];
    for (int i = 0; i < 8; i++) {
        scanf("%d",&number[i]);
    }
    int count_number[8];
    int num = 0;
    for (int i = 0; i < 8; i = i + 2) {
        if (number[i] * number[i + 1] != 0) {
            count_number[i] = number[i] * number[i + 1];
            count_number[i + 1] = number[i + 1] - 1;
            num = num + 2;
        }
    }
    for (int i = 0; i < num - 1; i++) {
        printf("%d ", count_number[i]);
    }
    printf("%d", count_number[num - 1]);
}
