//第一万个素数是103079
//应该换一种求素数的方法
#include <stdio.h> 
#include <string.h>
int main(void) {
    int is_prime[110000];
    memset(is_prime, 0, 110000*sizeof(int));
    is_prime[0] = 1;
    is_prime[1] = 1;
    for (int i = 2; i * i <= 110000; i++) {
        if(!is_prime[i]) {
            for (int j = 2;i * j <= 110000; j++) {
                is_prime[i * j] = 1;
            }
        }
    }
    int num_of_prime = 0;
    int prime[20000];
    for (int i = 0; i < 110000; i++) {
        if(!is_prime[i]) {
            prime[num_of_prime] = i;
            num_of_prime++;
        }
    }
    int start;
    int end;
    scanf("%d %d", &start, &end);
    int j = 0;
    for (int i = start - 1; i < end; i++) {
        printf("%d",prime[i]);
        if (j == 9) {
            printf("\n");
            j = 0;
        }
        else if (i == end - 1) {
            
        }
        else {
            printf(" ");
            j++;
        }
    }
}