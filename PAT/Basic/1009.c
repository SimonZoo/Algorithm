#include <stdio.h>
#include <string.h>
int main(void) {
    char b_word[81];
    char a_word[81];
    gets(b_word);
    int a = 0;
    int i = strlen(b_word) - 1;
    while (i >= 0){
        int j = i;
        while(j > 0 && b_word[j - 1] != ' ') {
            j--;
            if(j == 0) break;
        }
        int len = -(j - i - 1);
        for (;j <= i; j++) {
            a_word[a] = b_word[j];
            if(a <= strlen(b_word) - 1) a++;
        }
        if(a < strlen(b_word) - 1) {
            a_word[a] = ' ';
            a++;
        }
        i = i - len - 1;
    }
    a_word[a] = 0;
    puts(a_word);
}