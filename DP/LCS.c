#include <stdio.h>
#include <string.h>
#define N 20

char string1[N];
char string2[N];
int mark[N][N];

int LCS(char string1[], char string2[]);

int main(int argc, char const *argv[])
{
	gets(string1);
	gets(string2);
	printf("%d\n", LCS(string1, string2));
	return 0;
}

int LCS(char string1[], char string2[]) {
	int row = strlen(string2);
	int col = strlen(string1);
	memset(mark, 0, sizeof(mark));
	for (int i = 1; i <= row; i++) {
		for (int j =1; j <= col; j++) {
			if (string2[i - 1] == string1[j - 1]) {
				mark[i][j] = mark[i - 1][j - 1] + 1;
			}
			else {
				int max = mark[i - 1][j] >= mark[i][j - 1] ? mark[i - 1][j] : mark[i][j - 1];
				mark[i][j] = max;
			}
		}
	}
	return mark[row][col];
}