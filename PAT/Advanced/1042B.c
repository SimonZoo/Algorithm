#include <stdio.h>
#include <stdlib.h>

void swap(int **a, int **b) {
    int *t = *a;
    *a = *b;
    *b = t;
}

int main(void) {
    char card[] = {'S', 'H', 'C', 'D', 'J'}; 
    int *start = (int*)malloc(sizeof(int)*54);
    int *end = (int*)malloc(sizeof(int)*54);
    int *order = (int*)malloc(sizeof(int)*54);
    int times;
    scanf("%d", &times);
    for (int i = 0; i < 54; i++) {
        scanf("%d", &order[i]);
        start[i] = i;
    }
    for (int i = 0; i < times; i++) {
        for (int j = 0; j < 54; j++) {
            int n = order[j];
            end[n-1] = start[j];
        }
        swap(&start, &end);
    }
    for (int i = 0; i < 54; i++) {
        printf("%c%d", card[start[i]/13], start[i]%13+1);
        if (i != 53) printf(" ");
    }
}