#include <stdio.h>
#include <string.h>

int main(void) {
    char str[102];
    char* eng[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
    int sum = 0;
    scanf("%s", str);
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        sum = sum + str[i] - '0';
    }
    int h = sum / 100;
    int t = sum / 10 % 10;
    int d = sum % 10;
    if (h != 0) {
        printf("%s %s %s", eng[h], eng[t], eng[d]);
    } else if (t != 0) {
        printf("%s %s", eng[t], eng[d]);
    } else {
        printf("%s", eng[d]);
    }

}