#include <stdio.h>
#include <ctype.h>
#include <string.h>


int main(void) {
    char string[100002];
    fgets(string, 100002, stdin);
    int sum = 0;
    int len = strlen(string);
    for (int i = 0; i < len; i++) {
        if (isalpha(string[i])) {
            sum = sum + (toupper(string[i]) - 'A' + 1);
        }
    }
    int count_zero = 0, count_one = 0;
    while(sum != 0) {
        int k = sum % 2;
        if (k) count_one++;
        else count_zero++;
        sum = sum / 2;
    }
    printf("%d %d", count_zero, count_one);
}