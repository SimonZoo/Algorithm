#include <stdio.h>
#include <math.h>
int main(void) {
	int num;
	char signal;
	scanf("%d %c", &num, &signal);
	int line = sqrt((num+1)/2);//一个三角形(半个沙漏)的层数，等差数列求和推出
	for (int i = line; i > 0; i--) {
		for (int k = 0; k < line - i; k++) 
			printf(" ");
		for (int j = 0; j < 2*(i-1)+1; j++) 
			printf("%c", signal);
		printf("\n");
	}
	for (int i = 2; i <= line; i++) {
		for (int k = 0; k < line - i; k++) 
			printf(" ");
		for (int j = 0; j < 2*(i-1)+1; j++) 
			printf("%c", signal);
		printf("\n");
	}
	printf("%d", num - (2*line*line-1));	
}