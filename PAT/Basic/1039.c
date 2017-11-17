#include <stdio.h>
#include <string.h>
int main(void) {
    char buy[1001];
    char want[1001];
    unsigned int number = 0;
    scanf("%s", buy);
    scanf("%s", want);
    for (int i = 0; want[i] != '\0'; i++) {
        for (int j = 0; buy[j] != '\0'; j++) {
            if (want[i] == buy[j]) {
                want[i] = '*';
                buy[j] = '!'; 
                number++;
            }
        }
    }
    
    if (number == strlen(want)) 
        printf("Yes %lu", strlen(buy) - number);
    else 
        printf("No %lu", strlen(want) - number);
}