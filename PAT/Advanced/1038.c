#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char number[9];
}Num;

int cmp(const void* p1, const void* p2) {
    char A[18];
    char B[18];
    strcpy(A, (*(Num*)p1).number);
    strcpy(B, (*(Num*)p2).number);
    return strcmp(strcat(A, (*(Num *)p2).number), strcat(B, (*(Num *)p1).number)) > 0;
}

int main(void) {
    
    int n;
    scanf("%d", &n);
    Num num[n];
    for (int i = 0; i < n; i++) {
        scanf("%s", num[i].number);
    }
    qsort(num, n, sizeof(num[0]), cmp);
    char all[n*9];
    strcpy(all, num[0].number);
    for (int i = 1; i < n ;i++) {
        strcat(all, num[i].number);
    }
    int len  = strlen(all);
    int p = -1;
    for (int i = 0 ;i < len; i++) {
        if (all[i] == '0') continue;
        else if(all[i] != '0') {
            p = i; 
            break;
        }
    }
    if (p != -1) {
        for (int i = p; i < len; i++) {
            printf("%c", all[i]);
        }
    } else {
        printf("0");
    }    
}