#include <stdio.h>
#include <string.h>

int main(void) {
    int N;
    scanf("%d", &N);
    int score[N+1];
    memset(score, 0, sizeof(score));
    int cur_number;
    int cur_score;
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &cur_number, &cur_score);
        score[cur_number] += cur_score;
    }
    int max = 0;
    for (int i = 0; i <= N; i++) {
        if (score[i] > score[max]) max = i;
    }
    printf("%d %d", max , score[max]);
}