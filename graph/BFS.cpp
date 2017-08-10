//Maze Problem

#include <cstdio>
#include <cstring>
#include <queue>

#define N 8

using namespace std;

typedef struct {
	int x;
	int y;
} Node;

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

int BFS();

int main(int argc, char const *argv[])
{
	memset(mark, -1, sizeof(mark));
	printf("%d\n", BFS());
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%3d", mark[i][j]);
		}
		printf("\n");
	}
	return 0;
}

int BFS() {
	queue<Node> q;
	Node n;
	n.x = n.y = 0;
	mark[0][0] = 0;
	q.push(n);
	while(!q.empty()) {
		n = q.front();
		q.pop();
		if (n.x == N - 1 && n.y == N - 1) return mark[N - 1][N - 1];
		for (int i = 0; i < 4; i++) {
			int x = n.x + dx[i];
			int y = n.y + dy[i];
			if (x < 0 || x >= N || y < 0 || y >= N) continue;
			if (mark[x][y] == -1 && maze[x][y] == 0) {
				mark[x][y] = mark[n.x][n.y] + 1;
				Node new_node;
				new_node.x = x;
				new_node.y = y;
				q.push(new_node);
			}
		}
	}
	return -1;
}