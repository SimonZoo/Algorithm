#include <stdio.h>

int main(void) {
    int stu, numOfThing;
    int ban[10000] = {0};
    scanf("%d %d", &stu, &numOfThing);
    char name[stu][5];
    int ban_thing = 0;
    int ban_stu = 0;
    for (int i = 0; i < numOfThing; i++) {
        int cur;
        scanf("%d", &cur);
        ban[cur] = 1;
    }
    for (int i = 0; i < stu; i++) {
        int n;
        scanf("%s %d", name[i], &n);
        int flag = 0;
        for (int j = 0; j < n; j++) {
            int t;
            scanf("%d", &t);
            if (flag == 0 && ban[t] == 1) {
                printf("%s:", name[i]);
                printf(" %04d", t);
                ban_stu++;
                ban_thing++;
                flag = 1;
            } else if (flag == 1 && ban[t] == 1) {
                printf(" %04d", t);
                ban_thing++;
            }
        }
        if (flag) printf("\n");
    }
    printf("%d %d", ban_stu, ban_thing);
}