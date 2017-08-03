#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LEN 10

void merge_sort(int array[], int array_after[], int start, int end);

int main(int argc, char const *argv[])
{
	int array[LEN];
	int array_after[LEN];
	srand(time(NULL));
	for (int i = 0; i < LEN; i++) { 
		array[i] = rand() % 100;
		printf("%4d", array[i]);
	}
	printf("\nAfter merge_sort:\n");
	merge_sort(array, array_after, 0, LEN - 1);
	for (int j = 0; j < LEN; j++) printf("%4d", array[j]);
	int error = 0;
	for (int j = 0; j < LEN - 1; j++) {
		if (array[j] > array[j + 1]) {
			error = 1;
			break;
		}
	}
	printf(error ? "\nError\n" : "\nPass\n");

	return 0;
}

void merge_sort(int array[], int array_after[], int start, int end) {
	if (start >= end) return;
	int len = end - start, mid = len / 2 + start;
	int start1 = start, end1 = mid;
	int start2 = mid + 1, end2 = end;
	// printf("%d %d %d\n", start, mid, end);
	merge_sort(array, array_after, start1, end1);
	merge_sort(array, array_after, start2, end2);
	int i = start;
	while (start1 <= end1 && start2 <= end2) {
		array_after[i++] = array[start1] < array[start2] ? array[start1++] : array[start2++];
	}
	while (start1 <= end1) {
		array_after[i++] = array[start1++];
	}
	while (start2 <= end2) {
		array_after[i++] = array[start2++];
	}
	for (int k = start; k <= end; k++) {
		array[k] = array_after[k];
	}
}
