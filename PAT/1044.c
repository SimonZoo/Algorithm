#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char number[14][5] = {"null","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
char high_number[14][5] = {"null","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

int change(int n,int k) {
    int num[3];
    int i = 0;
    while(n != 0) {
        num[i++] = n % k;
        n = n / k;
    }
    return num[2]*k*k + num[1]*k + num[0];
}
int main(void) {
    int N;
    scanf("%d", &N);
    getchar();
    char input[20];
    char after[N][20];
    for (int i = 0; i < N; i++) {
        gets(input);
        int mtoe = 0;
        if (input[0]>=97 && input[0] <= 122) mtoe = 1;
        //etom
        if (!mtoe) {
            int cur = atoi(input);
            cur = change(cur, 13);
            if (cur / 13 != 0) {
                strcpy(after[i], high_number[cur/13]);
                cur = cur % 13;
                strcat(after[i], " ");
                strcat(after[i], number[cur]);
            } else {
                strcpy(after[i], number[cur]);
            }
        } else { //mtoe
            int j = 0;
            int flag = 0;
            for(int k = 0; input[k] != '\0'; k++) {
                if (input[k] == ' ') {
                    j = k;
                    flag = 1;//两个单词
                }
            }
            if(flag) {
                char a[5];
                char b[5];
                int p = 0;
                int aa = 0, bb = 0;
                strncpy(a, input, j);
                for (int k = j+1; input[k] != '\0'; k++) {
                    b[p++] = input[k];
                }
                for (int k = 0; k <= 12; k++) {
                    if (strcmp(a, high_number[k]) == 0) aa = k;
                    if (strcmp(b, number[k]) == 0) bb = k;
                }
                aa = aa * 13 + bb;
                sprintf(after[i], "%d", aa);
            } else {
                int aa;
                int high = 0;
                for (int k = 0; k <= 12; k++) {
                    if (strcmp(input, high_number[k]) == 0) {
                        aa = k;
                        high = 1;
                    }
                    if (strcmp(input, number[k]) == 0) aa = k;   
                }
                if (high) aa = aa * 13;
                else aa = aa;
                sprintf(after[i], "%d", aa);
            }
        }
    }
        for (int i = 0; i < N; i++) {
            printf("%s\n", after[i]);
        }
    }
