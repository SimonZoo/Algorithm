//if define list[N][N]..it cause segmentation fault..
//score 23
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 175770 // 26*26*26*10+10

int getID(char name[5]) {
    int id = 0;
    for (int i = 0; i < 3;i++) {
        id = id * 26 + (name[i] - 'A');
    }
    id = id * 10 + (name[3] - '0');
    return id;
}

int cmp(const void *p1, const void* p2) {
    return (*(char*)p1) - (*(char*)p2);
}

int main(void) {
    int stu, class;
    scanf("%d %d", &stu, &class);
    char list[N][class*2+10];
    for (int i = 0; i < N; i++) {
        list[i][0] = '0';
    }
    for (int i = 0; i < class; i++) {
        char cur_class[2];
        int in_class;
        scanf("%s %d", cur_class, &in_class);
        for (int j = 0; j < in_class; j++) {
            char name[5];
            scanf("%s", name);
            int id = getID(name);
            if (list[id][0] == '0') strcpy(list[id], cur_class);
            else strcat(list[id], cur_class);
         }
    }
    for (int i = 0; i < stu; i++) {
        char name[5];
        scanf("%s", name);
        int id = getID(name);
        int len = strlen(list[id]);
        printf("%s", name);
        qsort(list[id], len, sizeof(list[id][0]), cmp);
        if (list[id][0] != '0') {
            printf(" %d", len);
            for (int j = 0; j < len; j++) {
                printf(" %c", list[id][j]);
            }
        } else {
            printf(" 0");
        }
        printf("\n");
    }
}