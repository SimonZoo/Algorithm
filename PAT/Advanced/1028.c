#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char name[9];
    int score;
} Student;

int cmp_1(const void *p1, const void *p2) {
    return (*(Student *)p1).id > (*(Student *) p2).id ? 1 : -1;
}
int cmp_2(const void *p1, const void *p2)
{
    int k = strcmp((*(Student *)p1).name, (*(Student *)p2).name);
    if (k == 0)
        return (*(Student *)p1).id > (*(Student *)p2).id ? 1 : -1;
    return k > 0? 1: -1;
}
int cmp_3(const void *p1, const void *p2)
{
    if ((*(Student *)p2).score == (*(Student *)p1).score)
        return (*(Student *)p1).id > (*(Student *)p2).id ? 1 : -1;
    return (*(Student *)p2).score < (*(Student *)p1).score ? 1 : -1;
}

int main(void) {
    int N, C;
    scanf("%d %d", &N, &C);
    Student students[N];
    for (int i = 0; i < N; i++) {
        scanf("%d %s %d", &students[i].id, students[i].name, &students[i].score);
    }
    switch(C) {
        case 1:
            qsort(students, N, sizeof(students[0]), cmp_1);
            break;
        case 2:
            qsort(students, N, sizeof(students[0]), cmp_2);
            break;
        case 3:
            qsort(students, N, sizeof(students[0]), cmp_3);
            break;
        }
    for (int i = 0; i < N; i++) {
        printf("%06d %s %d\n", students[i].id, students[i].name, students[i].score);
    }
}