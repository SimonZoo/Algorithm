#include <stdio.h>

int main(void) {
    int cur, num = 3;
    char mars[14] = {'0','1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'};
    printf("#");
    while(num > 0) {
        scanf("%d", &cur);
        int a = cur / 13;
        int b = cur % 13;
        printf("%c%c", mars[a], mars[b]);
        num--;
    }
}