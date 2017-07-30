#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LEN 10
void shell_sort(int array[],int len);

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	int array[LEN];
	for (int i = 0; i < LEN; i++) array[i] = rand()%100;
	for (int i = 0; i < LEN; i++) printf("%4d", array[i]);
	printf("\nAfter shell_sort\n");	
	shell_sort(array, LEN);
	for (int i = 0; i < LEN; i++) printf("%4d", array[i]);
	return 0;
}

void shell_sort(int array[],int len){
	int i, j, step,temp;
	for (step = len / 2 ; step > 0; step = step / 2){
		for (i = step; i < len; i++){
			temp = array[i];
			j = i - step;
			for (; j >= 0 && array[j] > array[j + step];j -= step) array[j + step] = array[j];
			array[j + step] = temp;
		}
	}
}