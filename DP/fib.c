#include <stdio.h>

int fib(int n);

int main(int argc, char const *argv[])
{
	fib(8);
	return 0;
}

int fib(int n) {
	int f = 1, g = 1;//f(1) = 1,f(1) = 2
	printf("%d\n%d\n", f, g);
	while(n > 2) {
		g = g + f;
		f = g - f;
		printf("%d\n", g);
		n--;
	}
	return g;
}