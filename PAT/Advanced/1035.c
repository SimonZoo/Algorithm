#include <stdio.h>
#include <string.h>

int main(void) {
    int N, count = 0;  
    scanf("%d", &N);
    char id[11], pwd[11], modify[N][25];
    for (int j = 0; j < N; j++) {
        int f = 0;
        scanf("%s %s", id, pwd);
        for (int i = 0; pwd[i] != '\0'; i++) {
            switch(pwd[i]) {
                case '1' : pwd[i] = '@'; f = 1; break;
                case '0' : pwd[i] = '%'; f = 1; break;
                case 'l' : pwd[i] = 'L'; f = 1; break;
                case 'O' : pwd[i] = 'o'; f = 1; break;
            }
        }
        if (f) {
            strcat(modify[count], id);
            strcat(modify[count], " ");
            strcat(modify[count], pwd);
            count++;
        }
    }
    if (count != 0) {
        printf("%d\n", count);
        for (int i = 0; i < count; i++) {
            printf("%s\n", modify[i]);
        }
    } else if (N == 1) {
        printf("There is 1 account and no account is modified");
    } else {
        printf("There are %d accounts and no account is modified", N);
    }          
}