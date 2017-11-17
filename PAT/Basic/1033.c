#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void) {
    char broken[80];
    char text[100009];
    gets(broken); // 考虑到出错的键盘可能没有，用gets
    scanf("%s", text);
    if (strlen(broken) == 0) {
        printf("%s", text);
        return 0;
    }
    int alpha = 0;
    for (int i = 0; broken[i] != '\0'; i++) {
        if (broken[i] == '+') alpha = 1;
    }
    if (alpha) {
        for (int i = 0; text[i] != '\0'; i++) {
            if (isupper(text[i])) text[i] = '*';
        }
    }
    for (int i = 0; broken[i] != '\0'; i++) {
        for (int j = 0;text[j] != '\0'; j++) {
            if (isalpha(text[j]) && toupper(text[j]) == toupper(broken[i])) 
                text[j] = '*';
            else if (text[j] == broken[i])
                text[j] = '*';
        }
    }
    int zero = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] != '*') {
            printf("%c", text[i]);
            zero = 1;
        }
    }
    if (!zero) printf("\n");
}