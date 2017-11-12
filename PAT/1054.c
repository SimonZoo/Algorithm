#include <stdio.h>
#include <string.h>

int main(void) {
    int N;
    scanf("%d", &N);
    double sum = 0.0;
    int count = 0;
    char a[50], b[50];//合理的数字最多八位够了，不合法的输入可能很长
    double temp;
    for (int i = 0; i < N; i++) {
        scanf("%s", a);
        sscanf(a, "%lf", &temp); // (double)temp = (char)a;
        sprintf(b, "%.2lf", temp); //(char)b = (double)temp
        int flag = 0;
        int len = strlen(a);
        for (int k = 0; k < len; k++) {
            if (a[k] != b[k]) flag = 1;
        }        
        if (flag || temp > 1000 || temp < -1000) {
            printf("ERROR: %s is not a legal number\n", a);
            continue;
        } else {
            sum = sum + temp;
            count++;
        }
    }
    if(count == 1) {
        printf("The average of 1 number is %.2lf", sum);
    } else if(count > 1) {
        printf("The average of %d numbers is %.2lf", count, sum / count);
    } else {
        printf("The average of 0 numbers is Undefined");
    }
}