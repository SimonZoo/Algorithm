#include <stdio.h>
#define N 501

int main(void) {
    int coin[N] = {0};
    int coin_num, pay_money;
    scanf("%d %d", &coin_num, &pay_money);
    for (int i = 0; i < coin_num; i++) {
        int cur;
        scanf("%d", &cur);
        coin[cur]++;
    }
    int max = pay_money > 501 ? 501 : pay_money;
    for (int i = 1; i < max; i++) {
        if (i == pay_money - i && coin[i] == 1) {
            continue;
        } else if (pay_money - i < 501 && coin[i] && coin[pay_money-i]) {
            printf("%d %d", i, pay_money - i);
            return 0;
        }
    }
    printf("No Solution");
}