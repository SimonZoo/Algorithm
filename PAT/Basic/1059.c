#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int is_prime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}
int main(void) {
    int N;
    scanf("%d", &N);
    getchar();
    int member[10001] = {0};
    int mark[N + 1];
    memset(mark, 0, sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        int id;
        scanf("%d", &id);
        member[id] = i + 1;
    }
    int times;
    scanf("%d", &times);
    // getchar();
    for (int i = 0; i < times; i++){
        int cur_id;
        scanf("%d", &cur_id);
        printf("%04d: ", cur_id);
        if (member[cur_id] == 0) {
            printf("Are you kidding?\n");
            continue;
        }
        if (mark[member[cur_id]] == 1) {
            printf("Checked\n");
            continue;
        }
        if (member[cur_id] == 1 && mark[member[cur_id]] == 0) {
            mark[member[cur_id]] = 1;
            printf("Mystery Award\n");
            continue;
        } else if (is_prime(member[cur_id]) && mark[member[cur_id]] == 0) {
            mark[member[cur_id]] = 1;
            printf("Minion\n");
            continue;
        } else {
            mark[member[cur_id]] = 1;
            printf("Chocolate\n");
        }
       
    }
}