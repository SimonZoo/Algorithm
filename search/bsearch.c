#include <stdio.h>
#define LEN 10

int binary_search(int array[], int start, int end, int number);

int main(int argc, char const *argv[])
{
	int array[LEN] = {7, 9, 29, 34, 44, 58, 60, 71, 84, 90};
	for (int i = 0; i < LEN; i++) printf("%4d", array[i]);
	int number;
	printf("\n Input the number:\n");
	scanf("%d", &number);
	int k = binary_search(array, 0, LEN, number);
	printf("The number is  %d  in the array.\n", k + 1);
}

int binary_search(int array[], int start, int end, int number) {
	if (start > end) return -1; 

	int mid = (end - start) / 2 + start;
	if (array[mid] > number) return binary_search(array, start, mid - 1, number);
	if (array[mid] < number) return binary_search(array, mid + 1, end, number);
	return mid ;
} 