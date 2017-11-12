#include <stdio.h>
#include <string.h>
#define N 16

int n;
int sum = 0;
int array[N];
int mark[N];

int is_prime(int number);
void DFS(int current);


int main(int argc, char const *argv[])
{
	printf("Enter a number n (n < 16)\n");
	scanf("%d",&n);
	memset(mark, 0, sizeof(mark));
	memset(array, 0, sizeof(array));
	array[0] = 1;
	DFS(1);
	printf("There are %d ways.\n", sum);
	return 0;
}

int is_prime(int number) {
	int flag = 1;
	for (int i = 2; i * i <= number; i++) {
		if (number % i == 0) {
			flag = 0;
			break;
		}
	}
	if (flag) return 1;
	else return 0;
}

void DFS(int current) {
	if (current == n && is_prime(array[0] + array[n - 1])) {
		sum++;
		for (int i = 0; i < n; i++) printf("%4d", array[i]);
		printf("\n");
		return;
	}
	else {
		for (int i = 2; i <= n; i++) {
			if (mark[i] == 0 && is_prime(i + array[current - 1])) {
				array[current] = i;
				mark[i] = 1;
				DFS(current + 1);
				mark[i] = 0;
			}
		}
	}
}