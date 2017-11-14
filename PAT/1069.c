//C++的Map会方便很多（
#include <stdio.h>
#include <string.h>

int check(char name[][22], int n, int s, int cur, int len) {
    for (int k = cur; k <= len; k++) {
        int flag = 1;
        for (int j = s; j < cur; j = j + n) {
            if(strcmp(name[k], name[j]) == 0) {
                flag = 0;
                break;
            }
        }
        if (flag) return k;
    }
    return 0;
}
int main(void) {
    int M, N, S;
    int next;
    scanf("%d %d %d", &M, &N, &S);
    int start = S;
    char name[M+1][22];
    for (int i = 1 ; i <= M; i++) {
        scanf("%s", name[i]);
    }
    if (start > M){
        printf("Keep going...");
        return 0;   
    }
    for (int i = 1; i <= M; i++) {
        if (i == S) {
            next = check(name, N, start, i, M);
            if (next == i) {
                printf("%s\n", name[i]);
                S = S + N;
                continue;
            } else {
                printf("%s\n", name[next]);
                S = S + N + (next - i);
            }  
        }
    }
}