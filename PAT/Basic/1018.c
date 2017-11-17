//shit code...
#include <stdio.h>
int main(void) {
    int N;
    scanf("%d", &N);
    getchar();
    char game[N][3];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%c", &game[i][j]);
            getchar();
        }
    }
    int gamer_A[3] = {0};
    int max_A[3] = {0};
    int gamer_B[3] = {0};
    int max_B[3] = {0};
    for (int i = 0; i < N; i++) {
        char a = game[i][0];
        char b = game[i][1];
        if (a == b) {
            gamer_A[1]++;
            gamer_B[1]++;//平
        } else if ( (a == 'B' && b =='C') || (a == 'J' && b == 'B') || (a == 'C' && b == 'J')) {
            gamer_A[0]++;
            gamer_B[2]++;
            switch(a) {
                case 'B':
                    max_A[0]++;
                    break;
                case 'C':
                    max_A[1]++;
                    break;
                case 'J':
                    max_A[2]++;
                    break;
            }
        } else {
            gamer_A[2]++;
            gamer_B[0]++;
            switch(b) {
                case 'B':
                    max_B[0]++;
                    break;
                case 'C':
                    max_B[1]++;
                    break;
                case 'J':
                    max_B[2]++;
                    break;
            }
        }
    }
    for(int i = 0; i < 2; i++) {
        printf("%d ", gamer_A[i]);
    }
    printf("%d\n", gamer_A[2]);
    for(int i = 0; i < 2; i++) {
        printf("%d ", gamer_B[i]);
    }
    printf("%d\n", gamer_B[2]);

    int a;
    if (max_A[0] >= max_A[1]) {
        a = 0;
    } else {
        a = 1;
    }
    if (max_A[2] > max_A[a]) {
        a = 2;
    }
    switch(a) {
        case 0: 
            printf("B ");
            break;
        case 1: 
            printf("C ");
            break;
        case 2: 
            printf("J ");
            break;
    }
    int b;
    if (max_B[0] >= max_B[1]) {
        b = 0;
    } else {
        b = 1;
    }
    if (max_B[2] > max_B[b]) {
        b = 2;
    }
    switch(b) {
        case 0: 
            printf("B");
            break;
        case 1: 
            printf("C");
            break;
        case 2: 
            printf("J");
            break;
    }
    
}