#include <stdio.h>
#include <string.h>
#include <ctype.h>

int get_number(char n[], int r) {
    int len = strlen(n);
    int t = 1, sum = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (isalpha(n[i])) {
            sum += (n[i] - 'a' + 10) * t;
        } else if (isnumber(n[i])) {
            sum += (n[i] - '0') * t;
        }
        t = t * r;
    }
    return sum;
}

int find_radix(int flag, int min, int max, int know_n, char n[]) { // max = r - 1, n1 = 
    if (flag) { // flag == 1 means another number's radix < the radix have told
        for (int i = max; i >= 2; i--) {
            int result = get_number(n, i);
            if (result == know_n) {
                printf("%d", i);
                return 0;
            }
        }
    } else {
        for (int i = min; i <= 36; i++) {
            int result = get_number(n, i);
            if (result == know_n) {
                printf("%d", i);
                return 0;
            }
        }
    }
    printf("Impossible");
    return 0;
}

int main(void) {
    char num_1[11], num_2[11];
    int n, r;
    scanf("%s %s %d %d", num_1, num_2, &n, &r);
    int n1 = get_number(num_1, r);
    int n2 = get_number(num_2, r);
    int flag = n2 > n1 ? 1 : 0;
    if (n == 1) {
        find_radix(flag, r + 1, r - 1, n1, num_2);
    } else {
        find_radix(flag, r + 1, r - 1, n2, num_1);
    }
}