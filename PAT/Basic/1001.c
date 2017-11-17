//如果输入1的话就是0步，不用考虑1是奇数所以要操作2步……
//当然0也是不用考虑的……
#include <stdio.h>
int main(void) {
    int number;
    int i = 0;
    scanf("%d",&number);
    while(number != 1) {
        if (number % 2) {
            number = (3 * number + 1) / 2;
        } else {
            number = number / 2;
        }
        i++;
    }
    printf("%d",i);
}
