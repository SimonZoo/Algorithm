#include <stdio.h>

int main(void) {
    int N, want_floor, cur = 0, sum = 0;
    scanf("%d ", &N);
    while(N > 0) {
        scanf("%d ", &want_floor);
        if (cur > want_floor) sum = sum + (cur - want_floor) * 4;
        else if (cur < want_floor) sum = sum + (want_floor - cur) * 6;
        sum = sum + 5;
        cur = want_floor;
        N--;
    }
    printf("%d", sum);
}