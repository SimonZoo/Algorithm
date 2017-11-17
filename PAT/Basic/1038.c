#include <stdio.h>
#include <string.h>

int main(void) {
    int N;
    scanf("%d", &N);
    int score[101];
    memset(score, 0, sizeof(int)*101);
    int cur;
    for (int i = 0; i < N; i++) {
        scanf("%d", &cur);
        score[cur]++;
    }
    int K;
    scanf("%d", &K);
    int search[K];
    int search_score;
    for (int i = 0; i < K; i++) {
        scanf("%d", &search_score);
        search[i] = score[search_score];
    }
    for (int i = 0; i < K - 1; i++) 
        printf("%d ", search[i]);
    printf("%d", search[K - 1]);
}