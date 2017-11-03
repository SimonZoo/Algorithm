#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
	return *(int*)a - *(int*)b;
}
int main(int argc, char const *argv[])
{
	int n;
	long p;
	scanf("%d %ld", &n, &p);
	int num[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}	
	qsort(num, n, sizeof(int), cmp);
	int max_count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + max_count; j < n; j++) { // 因为是有序数组，所以 j 从 i + max_count 开始
			if (num[i] * p >= num[j]) {
				if (j - i + 1 > max_count) {
					max_count = j - i + 1;
				}
			} else break; // 及时退出，不然会超时
		}
	}
	printf("%d", max_count);
	return 0;
}
