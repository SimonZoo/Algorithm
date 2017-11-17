#include <stdio.h>

int main(void) {
    int b_number;
    int count[3];

    scanf("%d", &b_number);
    count[0] = b_number / 100;
    count[1] = b_number / 10 % 10;
    count[2] = b_number % 10;

    int len = count[0] + count[1] + count[2];
    char a_number[len];
    for (int i = 0; i < count[0]; i++) {
        a_number[i] = 'B';
    }
    for (int i = count[0]; i < count[0] + count[1]; i++) {
        a_number[i] = 'S';
    }
    char j = '1';
    for (int i = count[0] + count[1]; i < len; i++) {
        a_number[i] = j;
        j++;
    }
    for (int i = 0; i < len;i++) {
        printf("%c", a_number[i]);
    }
    
}