#include <stdio.h>
#include <string.h>
#define N 5

char pic[N][N]= {{'@','*','*','*','@'},{'*','@','@','*','@'},{'*','*','*','*','@'},{'@','@','@','*','@'},{'@','@','*','*','@'}};
int id_pic[N][N];

void DFS(int row, int col, int id);

int main(int argc, char const *argv[])
{
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			printf("%c", pic[i][j]);
		}
		printf("\n");
	}
	memset(id_pic, 0, sizeof(id_pic));
	int count = 0;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (id_pic[i][j] == 0 && pic[i][j] == '@') DFS(i, j, ++count);
		}
	}
	printf("%d\n", count);
	return 0;
}

void DFS(int row, int col, int id) {
	if (row < 0 || row >= N || col < 0 || col >= N) return;
	if (id_pic[row][col] > 0 || pic[row][col] != '@') return;
	id_pic[row][col] = id;
	for (int drow = -1; drow <= 1; drow++) {
		for (int dcol = -1; dcol <= 1; dcol++) {
			if (drow != 0 || dcol != 0) DFS(row + drow, col + dcol, id);
		}
	} 
}