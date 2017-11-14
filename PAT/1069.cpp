#include <iostream>
#include <map>
using namespace std;

int main(void) {
    int M, N, S;
    scanf("%d %d %d", &M, &N, &S);
    string str;
    map<string, int> alredyGetPrice;
    int flag = 0;
    if (S > M) {
        cout << "Keep going...";
        return 0;
    }
    for (int i = 1; i <= M; i++) {
        cin >> str;
        if (alredyGetPrice[str] == 1) S = S + 1;
        if (i == S && alredyGetPrice[str] == 0) {
            alredyGetPrice[str] = 1;
            cout << str << endl;
            S = S + N;
        }
    }
}