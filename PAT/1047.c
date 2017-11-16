#include <stdio.h>

int main(void) {
    int N;
    int team[10000] = {0};
    int max = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int cur_team;
        int teammate;
        int score;
        scanf("%d-%d %d", &cur_team, &teammate, &score);
        team[cur_team] += score;
    }
    for (int i = 0; i < 10000; i++) {
        if (team[max] < team[i]) max = i;
    }
    printf("%d %d", max, team[max]);
}