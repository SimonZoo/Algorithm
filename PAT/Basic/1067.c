//
#include <stdio.h>
#include <string.h>

int main(void) {
    int num;
    char pwd[22];
    scanf("%s %d", pwd, &num);
    getchar();
    for (int i = 1; i <= num ; i++) {
        char cur[40];
        gets(cur);
        if (strcmp(cur, "#") == 0){
            break;
        }
        if (strcmp(pwd, cur) == 0 && i <= num) {
            printf("Welcome in\n");
            break;
        } else if (strcmp(pwd, cur) != 0){
            printf("Wrong password: %s\n", cur);
            if (i == num) {
                printf("Account locked");
                break;
            }
        } 
    }
}