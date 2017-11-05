//idea from liuchuo.net
#include <stdio.h>
#define N 100002
int main(void) {
    char string[N];
    scanf("%s", string);
    int countP = 0, countT = 0, result = 0;
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == 'T') countT++;
    }
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == 'P') countP++;
        if (string[i] == 'T') countT--;
        if (string[i] == 'A') result = (result + (countP * countT) % 1000000007) % 1000000007;
    }
    printf("%d", result);
}