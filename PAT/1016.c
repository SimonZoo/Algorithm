#include <stdio.h>
// #include <stdlib.h> 
#define LEN 12
int new_number(int count, int num);
int count (char arr[LEN], char x);
int main(void) {
    char A[LEN], B[LEN];
    char DA, DB;
    scanf("%s %c %s %c", A, &DA, B, &DB);
    int countA = count(A, DA);
    int countB = count(B, DB);
    int da = DA - '0';
    int db = DB - '0';
    int sum_a = new_number(countA, da);
    int sum_b = new_number(countB, db);
    printf("%d", sum_a + sum_b);
}

int new_number(int count, int num) {
    int k = 1;
    int sum = 0;;
    for (int i = 0; i < count; i++) {
        sum = sum + k * num;
        k = k * 10;
    }
    return sum;
}

int count (char arr[], char x) {
    int count = 0;
    for (int i = 0; arr[i] != '\0'; i++) {
        if (arr[i] == x) {
            count++;
        }
    }
    return count;
}