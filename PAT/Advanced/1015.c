#include <stdio.h>
#include <math.h>

int judge(int num, int n) {
    char t_num[16];
    int i = 0, p = 0;
    int sum = 0;
    while(num != 0) {
        int cur = num % n;
        sprintf(&t_num[i], "%d", cur);
        num = num / n;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        int k = pow(n, p);
        int c = t_num[j] - '0';
        sum = sum + c * k;
        p++;
    }
    return sum;
}

int prime(int sum) {
    if (sum <= 1) return 0;
    for (int i = 2; i * i <= sum; i++) {
        for (int j = 2; i * j <= sum; j++) {
            if(sum == i * j) return 0;
        }
    }
    return 1;
} 

int main(void) {
    while(1){
        int m, n;
        scanf("%d %d", &m, &n);
        if (m < 0) break; 
        int s = judge(m, n);
        int result = prime(s);
        if (result && prime(m)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
}