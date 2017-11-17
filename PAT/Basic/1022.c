#include <stdio.h> 

int main(void) {
    int A, B, D;
    scanf("%d %d %d", &A, &B, &D);
    int len = 10000;
    int arr[len];
    int num = 0;
    A = A + B;
    while(A != 0) {
        arr[num++] = A % D;
        A = A / D;
    }
    if (num == 0) {
        printf("%d", arr[num]);
        return 0;
    }
    int i = num - 1;
    for (; i >= 0; i--) {
        printf("%d", arr[i]);
    } 
}