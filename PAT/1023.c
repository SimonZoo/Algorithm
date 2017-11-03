#include <stdio.h>
#define N 10
int main(void) {
	int count[N];
	int number[100];
	int n = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &count[i]);
		if (count[i] != 0) {
			for (int j = 0; j < count[i]; j++) {
				number[n++] = i;
			}
		}
	}

	if (number[0] == 0) {
		for (int i = 0; i < n; i++) {
			if (number[i] != 0) {
				int temp = number[0];
				number[0] = number[i];
				number[i] = temp;
				break;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d", number[i]);
	}
}