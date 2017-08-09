#include <cstdio>
#include <cstring>
#define N 8

int maze[N][N] = {  {0, 1, 1, 1, 1, 1, 1, 0},
					{0, 1, 1, 1, 1, 1, 0, 1},
					{0, 0, 1, 0, 0, 0, 0, 0},
					{1, 0, 1, 0, 1, 1, 1, 0},
					{1, 0, 0, 0, 0, 0, 0, 0},
					{0, 1, 0, 1, 1, 0, 0, 0},
					{0, 1, 1, 1, 0, 0, 1, 0},
					{0, 1, 0, 0, 0, 1, 1, 0},
				 };
int mark[N][N];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int BFS(int row, int col);

int main(int argc, char const *argv[])
{
	memset(mark, 0, sizeof(mark));
	printf("%d\n", BFS());
	return 0;
}

int BFS() {
	queue<Node> q;
	
	while() {

		if (row == N - 1 && col == N - 1) return mark[row][col];
		for (int i = 0; i < 4; i++) {
			int x = row + dx[i];
			int y = col + dy[i];
			if (x < 0 || x >= N || y < 0 || y >= N) continue;
			if (!mark[x][y] && !maze[x][y]) {
				mark[x][y] = mark[row][col] + 1;

			}
		}
	}
	return -1;	
}