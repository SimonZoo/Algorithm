#include <stdio.h>

int main(void) {
    int N, F = 1; 
    int number[10002]={0};
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int cur; 
        scanf("%d", &cur);
        if (number[cur] == 0) {
            // printf("num : %d f : %d\n", cur, F);
            number[cur] = F++;
        } else {
            number[cur] = -1;
        }
    }
    int min = 10001;
    number[min] = 9999;
    for (int i = 1; i <= 10001; i++) {
        if (number[i] != 0 && number[i] != -1 && number[i] < number[min]) {
            min = i;
        }
    }
    if (min != 10001) {
        printf("%d", min);
    } else {
        printf("None");
    }
}