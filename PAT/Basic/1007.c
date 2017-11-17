#include <stdio.h>
#include <string.h>
int main(void) {
    int is_prime[100001];
    memset(is_prime, 0, 100001*sizeof(int));
    is_prime[0] = 1;
    is_prime[1] = 1;
    for (int i = 2; i * i <= 100000; i++) {
        if(!is_prime[i]) {
            for (int j = 2;i * j <= 100000; j++) {
                is_prime[i * j] = 1;
            }
        }
    }
    int num_of_prime = 0;
    int prime[99999];
    for (int i = 0; i < 100001; i++) {
        if(!is_prime[i]) {
            prime[num_of_prime] = i;
            num_of_prime++;
        }
    }
    int input;
    scanf("%d", &input);
    int number = 0; 
    int a = 0;
    //判断两个素数有没有超过范围，限制那个大的数
    while(prime[a + 1] <= input) {
        if(prime[a] + 2 == prime[a+1]) {
            number++;
        }
        a++;
    }
    printf("%d", number);
}