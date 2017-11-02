#include <stdio.h>
#include <string.h>
#define NUM 10
int main(void) {
    char N[1002];
    scanf("%s", N);
    int flag[NUM] = {0};
    int count[NUM] = {0};
    int number[NUM] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; N[i] != '\0'; i++) {
        int cur = N[i] - '0';
        int j = 0;
        while(j < NUM) {
            if (cur == number[j]) {
                flag[j] = 1;
                count[j]++;
                break;
            } else {
                j++;
            }
        }
    }
    for (int i = 0; i < NUM; i++) {
        if (flag[i]) {
            printf("%d:%d\n", i,count[i]);
        }
    }
}