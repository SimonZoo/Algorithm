#include <stdio.h>
#include <stdlib.h>

int cmp (const void* a, const void* b) {
    return *((int*)b) - *((int*)a);
}
int main(void) {
    int day;
    scanf("%d", &day);
    int kilo[day];
    int count = 0;
    for (int i = 0; i < day; i++) {
        scanf("%d", &kilo[i]);
    }
    qsort(kilo, day, sizeof(kilo[0]), cmp);
    for (int i = 0; i < day; i++) {
        if (kilo[i] > count + 1) count++;
    }
    printf("%d", count);
}