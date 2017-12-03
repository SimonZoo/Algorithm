//The string lengths of both strings are no more than 10^4...
#include <stdio.h>
#include <string.h>

int main(void) {
    char s1[100000], s2[100000];
    int flag[128] = {0};
    fgets(s1, 100000, stdin);
    fgets(s2, 100000, stdin);

    int len1 = strlen(s1);
    int len2 = strlen(s2);
    for (int i = 0; i < len2; i++) {
        flag[s2[i]] = 1;
    }
    for (int i = 0; i < len1; i++) {
        if (!flag[s1[i]]){
            printf("%c", s1[i]);
        } 
    }
}