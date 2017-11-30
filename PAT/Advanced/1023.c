#include <stdio.h>
#include <string.h>

int main(void) {
    char num[22];
    int count[10] = {0}, new[22];
    scanf("%s", num);
    int len = strlen(num);
    int flag = 0;
    for (int i = len - 1; i >= 0; i--) {
        int cur = num[i] - '0';
        count[cur]++;
        cur = cur * 2 + flag;
        flag = 0; // 上一位的进位结束 
        if (cur >= 10) {
            flag = 1;
            cur = cur % 10;
        }
        new[i] = cur;
        count[cur]--;// 把计数减掉，如果最后的数字是符合要求的，那么数组应为全0
    }
    int f = 0;
    for (int i = 0; i < 10; i++) {
        if (count[i] != 0) {
            f = 1;
            break;
        }
    }
    if (f == 1 || flag == 1) {
        printf("No\n");
    } else {
        printf("Yes\n");
    }
    if (flag == 1) printf("1");
    for (int i = 0; i < len; i++)
        printf("%d", new[i]);
    
}