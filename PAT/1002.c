#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char str[100], cur[1];
    int sum = 0, i = 0,j = 0, cur_num;
    scanf("%s", str);
    while(str[i] != '\0') {
        cur[0] = str[i];
        cur_num = atoi(cur);
        sum = sum + cur_num;
        i++;
    }
    // printf("%d\n",sum);

    char str_sum[10];
    sprintf(str_sum, "%d", sum);
    // printf("String is %s \n", str_sum);
    while(str_sum[j] != '\0') {
        switch(str_sum[j]) {
            case '1':
                 printf("yi");
                 break;
            case '2':
                 printf("er");
                 break;
            case '3':
                 printf("san");
                 break;
            case '4':
                 printf("si");
                 break;
            case '5':
                 printf("wu");
                 break;
            case '6':
                 printf("liu");
                 break;
            case '7':
                 printf("qi");
                 break;
            case '8':
                 printf("ba");
                 break;
            case '9':
                 printf("jiu");
                 break;
            case '0':
                 printf("ling");
                 break;
        }
        if(str_sum[j + 1] != '\0') printf(" ");
        j++; 
    }
}