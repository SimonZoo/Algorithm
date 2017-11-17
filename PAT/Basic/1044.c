#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* num_low[] = {"tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
char* num_high[] = {"tret","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
int main(void) {
    int N;
    scanf("%d ", &N);
    for (int i = 0; i < N; i++) {
        char in[10];
        fgets(in, 20, stdin);
        if (isdigit(in[0])) { // 地球数字转换为火星文
            int number = atoi(in);
            int h = number / 13;
            int l = number % 13;
            if (h != 0 && l != 0) 
                printf("%s %s\n", num_high[h],num_low[l]);
            else if(h != 0 && l ==0) 
                printf("%s\n", num_high[h]);
            else 
                printf("%s\n", num_low[l]);
        } else { //火星文转换为地球数字
            char high[4];
            char low[5];
            int number = 0;
            if (in[3] == ' ') { //两位火星数字
                sscanf(in, "%s", high);
                sscanf(in+4,"%s", low);
                for (int i = 0; i < 13; i++) {
                    if (strcmp(num_high[i], high) == 0) number = number + 13 * i;
                    if (strcmp(num_low[i], low) == 0) number = number + i;
                }
            } else {
                sscanf(in, "%s", high);
                for(int i = 1; i < 13; i++) {
                    if (strcmp(num_low[i], high) == 0) number = i;
                    if (strcmp(num_high[i], high) == 0) number = i * 13;
                }
            }
            printf("%d\n", number);
        }
    }
}