#include <stdio.h>

int main(void) {
    int num, n;
    scanf("%d %d", &num, &n);
    int i = 0;
    int t_num[50];
    if (num == 0) t_num[0] = 0;
    while (num != 0)
    {
        t_num[i] = num % n;
        num = num / n;
        i++;
    }
    int flag = 1;
    for(int j = 0; j < i / 2; j++) {
        if (t_num[j] != t_num[i - j - 1]) {
            flag = 0;
            break;
        }
    }    
    if (flag) printf("Yes\n");
    else printf("No\n");
    for (int j = i - 1; j > 0; j--)
        printf("%d ", t_num[j]);
    printf("%d", t_num[0]);
} 