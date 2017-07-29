#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LEN 10

void insert_sort(int array[]);

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	int array[LEN];
	for (int i = 0; i < LEN; i++) array[i] = rand() % 100;
	for (int i = 0; i < LEN; i++) printf("%4d", array[i]);

	insert_sort(array);
	printf("\nAfter sort:\n");
	for (int i = 0; i < LEN; i++) printf("%4d", array[i]);

	return 0;
}

void insert_sort(int array[]){
 	int i, j, temp;
	for (i = 1; i < LEN; i++)
	{
		temp = array[i];
		j = i - 1;
		for (; j >= 0 && array[j] > temp; j--)
		{
			array[j + 1] = array[j];
		}
		array[j + 1] = temp;
	}
}