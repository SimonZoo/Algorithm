//out of time
//score 18
#include <stdio.h>
#define N 16777217

int book[N]={0};

int main(void) {
    int row, col;
    scanf("%d %d", &row, &col);
    int max = -1, min = 16777216;
    int n = row * col;
    for (int i = 0; i < n; i++) {
        int cur;
        scanf("%d", &cur);
        if (cur > max) max = cur;
        if (cur < min) min = cur;
        book[cur]++;
    }
    int max_p = 0;
    for (int i = min; i <= max; i++) {
        if (book[i] > book[max_p]) max_p = i;
    }
    printf("%d\n", max_p);
}