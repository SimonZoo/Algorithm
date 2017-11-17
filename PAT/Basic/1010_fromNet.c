#include <stdio.h>

int main(void) {
    int number_a,number_b;
    int flag = 0;
    while(~scanf("%d %d", &number_a, &number_b)) {
        if (number_a * number_b) {
            if (flag) printf(" ");
            else flag = 1;
            printf("%d %d", number_a * number_b, number_b - 1);
        }
        else if (number_a == 0 && number_b == 0) printf("0 0\n");//输入0 0 是为0 0
        else if (!flag) printf("0 0\n");//无输入为 0 0
        else printf("\n");//输入 0 3 则不再输出
    }
}