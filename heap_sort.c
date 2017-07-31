#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LEN 10

void swap(int *a, int *b);
void max_heapify(int array[], int start, int end);
void heap_sort(int array[], int len);

int main(int argc, char const *argv[])
{
	int array[LEN];
	srand(time(NULL));
	for (int i = 0; i < LEN; i++) {
		array[i] = rand() % 100;
		printf("%4d", array[i]);
	}
	printf("\n After sort:\n");
	heap_sort(array, LEN);
	for (int i = 0; i < LEN; i++) {
		printf("%4d", array[i]);
	}
	printf("\n");
	return 0;
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void max_heapify(int array[], int start, int end) {
	int father = start;
	int son = 2 * father + 1;
	while(son <= end) {
		if (son + 1 <= end && array[son + 1] > array[son]) son++;

		if (array[father] > array[son]) return;
		else {
			swap(&array[father], &array[son]);
			father = son;
			son = 2 * father + 1;
		}
	}
}

void heap_sort(int array[], int len) {
	for (int i = len / 2 - 1; i >= 0; i--) max_heapify(array, i, len - 1);
	for (int i = len - 1; i > 0; i--){
		swap(&array[0], &array[i]);
		max_heapify(array, 0, i - 1);
	}
}