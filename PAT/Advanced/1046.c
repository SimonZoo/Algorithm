//数组模拟循环
#include <stdio.h>

int main(void) {
    int N, all = 0, cur;
    scanf("%d", &N);
    int distance[N+1];
    distance[0] = 0, distance[1] = 0;
    for (int i = 2; i <= N; i++) {
        scanf("%d", &cur);
        distance[i] = distance[i - 1] + cur;
        all = all + cur;
    }
    //每个结点i保存从第一个结点到第i个结点的距离，不然会超时
    scanf("%d", &cur);
    all = all + cur;

    int t;
    scanf("%d", &t);
    while(t > 0) {
        int a, b;
        scanf("%d %d", &a, &b);
        int max = a > b ? a : b;
        int min = a < b ? a : b;
        int wayA = distance[max] - distance[min];
        
        int wayB = all - wayA;
        int min_dis = wayA < wayB ? wayA : wayB;
        printf("%d\n", min_dis);
        t--;
    }
}