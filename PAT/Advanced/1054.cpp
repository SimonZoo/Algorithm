#include <cstdio>
#include <map>

using namespace std;

int main(void) {
    int row, col;
    scanf("%d %d", &row, &col);
    int p = row * col;
    int half = p/2;
    map<int, int> book;
    for (int i = 0; i < p; i++) {
        int cur;
        scanf("%d", &cur);
        book[cur]++;
        if (book[cur] >= half) {
            printf("%d", cur);
            return 0;
        }
    }
}