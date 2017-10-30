#include <stdio.h>
int main(void) {
    int line;
    scanf("%d", &line);
    int number[line][3];
    int mark[line];
    long long_num[3];
    for (int i = 0;i < line; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &number[i][j]);
            long_num[j] = number[i][j];
        }
        if (long_num[0]  > long_num[2] - long_num[1]) {
            mark[i] = 1;
        } else {
            mark[i] = 0;
        }
    }
    
    for (int i = 0; i < line; i++) {
        printf("Case #%d: ", i + 1);
        if(mark[i]) printf("true\n");
        else printf("false\n");
    }

    
}