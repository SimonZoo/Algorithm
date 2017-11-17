#include <stdio.h>

int main(void) {
    int need[3];
    int give[3];
    int change[3];
    int flag = 0;
    scanf("%d.%d.%d", &need[0], &need[1], &need[2]);
    scanf("%d.%d.%d", &give[0], &give[1], &give[2]);
    if (give[0] > need[0] || (give[0] == need[0] && give[1] > need[1]) || (give[0] == need[0] && give[1] == need[1] && give[2] >= need[2]))
        flag = 0;
    else flag = 1;
    if (flag) {
        for (int i = 0; i < 3; i++) {
            int t = need[i];
            need[i] = give[i];
            give[i] = t;
        }
    }
    if (give[2] >= need[2]) 
        change[2] = give[2] - need[2];
    else {
        change[2] = give[2] + 29 - need[2];
        give[1] = give[1] - 1;
    }
    if (give[1] >= need[1])
        change[1] = give[1] - need[1];
    else {
        change[1] = give[1] + 17 - need[1];
        give[0] = give[0] - 1;
    }
    change[0] = give[0] - need[0];
    if (flag)
        printf("-%d.%d.%d", change[0], change[1], change[2]);
    else
        printf("%d.%d.%d", change[0], change[1], change[2]);
}