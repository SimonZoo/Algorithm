//DP...
#include <stdio.h>
#include <string.h>

int main(void) {
    char string[1002];
    fgets(string, 1002, stdin);
    int len = strlen(string);
    int book[len][len];
    int max = 1;
    for (int i = 0; i < len; i++) {
        book[i][i] = 1;
        if (string[i] == string[i+1] && i < len - 1) { 
            book[i][i+1] = 1;
            max = 2;
        }
    }
    for (int l = 3; l <= len; l++) {
        for(int i = 0; i + l - 1 < len; i++) { //max i is len-1
            int j = i + l - 1;//tail
            if (string[i] == string[j] && book[i+1][j-1] == 1) {
                book[i][j] = 1;
                max = l;
            }
        }
    }
    printf("%d",max);
}