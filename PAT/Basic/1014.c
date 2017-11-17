#include <stdio.h>
#include <ctype.h>
#define LINE 4
#define COL 65
int main(void) {
    char string[LINE][COL];
    char day;
    char hour;
    int min;
    int times = 0;
    for (int i = 0; i < LINE; i++) {
        gets(string[i]);
    }
    //考虑到第二个字字符串和第四个字符串有可能比第一个和第三个短
    for (int i = 0; string[0][i] != '\0' && string[1][i] != '\0'; i++) {
        if (string[0][i] == string[1][i] ) {
            //星期A-G
            if (isupper(string[1][i]) && string[1][i] <= 71 && times == 0){ 
                day = string[1][i];
                times++;
            }
            //24小时
            else if (times == 1 && (isdigit(string[1][i]) || (string[1][i] >= 65 && string[1][i]<= 78))) {
                hour = string[1][i];
                times++;
            }
        }     
    }
    for (int i = 0; string[2][i] != '\0' && string[3][i] != '\0'; i++) {
        if (string[2][i] == string[3][i] && isalpha(string[3][i])) {
            min = i;
        }
    }
    switch(day) {
        case 'A':   
            printf("MON ");
            break;
        case 'B':   
            printf("TUE ");
            break;
        case 'C':   
            printf("WED ");
            break;
        case 'D':   
            printf("THU ");
            break;
        case 'E':   
            printf("FRI ");
            break;
        case 'F':   
            printf("SAT ");
            break; 
        case 'G':   
            printf("SUN ");
            break;         
    }
    
    if(hour >= 48 && hour <= 57) {
        printf("0%c:", hour);
    }else {
        printf("%d:", hour - 55);
    }
    if (min < 10) printf("0%d",min);
    else printf("%d",min);
}