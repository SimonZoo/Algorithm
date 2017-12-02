#include <stdio.h>
#include <string.h>
#define N 81

int main(void) {
    char string[N];
    scanf("%s", string);
    int len = strlen(string);
    int n1 = 1, n2 = 3, col = 0, row = 0;
    int sum = 2 * n1 + n2;
    row = (len-5)/3 + n1 + 1;
    col = (len-5)/3 + n2;
    if ((len-5)%3 == 2) row++;
    else if ((len-5)%3 ==1) col++;

    char output[row][col];
    memset(output, ' ', row*col);
    int i = 0;
    for (int j = 0; j < row - 1; j++) {
        output[j][0] = string[i];
        i++;
    }
    for (int j = 0; j < col - 1; j++) {
        output[row-1][j] = string[i];
        i++;
    }
    for (int j = row - 1; j >= 0; j--) {
        output[j][col-1] = string[i];
        i++;
    }
    for (int j = 0; j < row; j++) {
        for (int k = 0; k < col; k++) {
            if (output[j][k] == ' ') printf(" ");
            else printf("%c", output[j][k]);
        }
        printf("\n");
    }
}