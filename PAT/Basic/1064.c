#include <stdio.h>
#include <string.h>

int main(void) {
    int N;
    int count = 0;
    scanf("%d", &N);
    int friend[100000] = {0};
    for (int i = 0; i < N; i++) {
        int cur;
        int sum = 0;
        scanf("%d", &cur);
        while(cur != 0) {
            sum = sum + cur % 10;
            cur = cur / 10;
        }
        if (friend[sum] == 0) {
            friend[sum] = 1;
            count++;
        }
    }
    printf("%d\n", count);
    for (int i = 0; i < 100000; i++) {
        if (friend[i] == 1 && count > 1) {
            printf("%d ", i);
            count--;
        } else if (friend[i] == 1 && count == 1) {
            printf("%d", i);
        }
    }
}