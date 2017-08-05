#include <stdio.h>
int main(int argc, char const *argv[])
{
	int number1,number2;
	printf("Input two number:\n");
	scanf("%d,%d", &number1, &number2);
	if (number1 < number2) {
		int temp = number1;
		number1 = number2;
		number2 = temp;
	}
	while(number1 % number2 != 0){
		number1 %= number2;
		number2 %= number1;
	}
	printf("%d\n", number2);
	return 0;
 }