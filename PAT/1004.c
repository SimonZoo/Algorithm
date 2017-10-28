#include <stdio.h>
#define N 12
int main(void) {
    int number;
    scanf("%d", &number);
    char name[number][N];
    char stu_num[number][N];
    int score[number];
    int max = 0,min = 0;
    for (int i = 0; i < number; i++) {
        scanf("%s %s %d", name[i], stu_num[i], &score[i]);
    }
    for (int i = 0; i < number; i++) {
        if(score[i] > score[max]) max = i;
        if(score[i] < score[min]) min = i;
    }
    printf("%s %s\n", name[max], stu_num[max]);
    printf("%s %s\n", name[min], stu_num[min]);
}

