#include <stdio.h>
#define N 7

void search(int current);

int array[N];
int ways = 1;

int main(int argc, char const *argv[])
{
	search(0);
	return 0;
}

void search(int current) {
	int col;
	if (current == N) { 
		printf("----Way %d -----\n", ways);
		for (int k = 0; k < N; k ++){
			printf("%d - %d \n", k, array[k]);
		}
		ways++;
	}	
	else {
		for (col = 0; col < N; col++) {
			int ok = 1;
			//position of queen is (current,col)
			array[current] = col;
			//check if the queen can place
			for (int j = 0; j < current; j++) {
				if (array[current] == array[j] || current - array[current] == j - array[j] ||  current + array[current] == j + array[j]) {
					ok = 0;
					break;
				}
			 }
			if (ok == 1) search(current + 1);	
		}
	}	
}