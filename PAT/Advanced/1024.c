#include <stdio.h>
#include <string.h>

char string[100]; //最大重复100次

void revString(char s[]) {
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++) {
        char t = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = t;
    }
}

void add(char s[]) {
    int len = strlen(s);
    int flag = 0;
    
    for (int i = 0; i < len; i++) {
        string[i] = s[i] + string[i] + flag - '0';
        flag = 0;
        if (string[i] > '9') {
            string[i] = string[i] - 10;
            flag = 1;
        }
    }
    if (flag)
        strcat(string, "1");
    revString(string);
}

int main(void) {
    int K, times = 0;
    scanf("%s %d", string, &K);
    int len = strlen(string);
    char rev[100];
    int i;
    for (i = 0; i <= K; i++) {
        strcpy(rev, string);
        revString(rev);
        if ((strcmp(rev, string) == 0) || i == K) break;
        add(rev);
    }
    printf("%s\n%d", string, i);
}