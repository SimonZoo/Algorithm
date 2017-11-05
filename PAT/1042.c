#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(void) {
    char string[1001];
    gets(string);
    // scanf("%[^\n]",string); 
    int count[27] = {0};
    for (unsigned int i = 0; i < strlen(string); i++) {
        if (isalpha(string[i])) {
            int cur = tolower(string[i]) - 97;
            count[cur] = count[cur] + 1;
        }        
    }
    int max = 0;
    for (int i = 0; i <= 26; i++) {
        if (count[i] > count[max]) {
            max = i;
        }
    }   
    printf("%c %d", max+97, count[max]);
}