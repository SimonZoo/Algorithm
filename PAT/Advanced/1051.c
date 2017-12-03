#include <stdio.h>
#include <string.h>

int main(void) {
    int max, number, times;
    scanf("%d%d%d", &max, &number, &times);
    int input[number + 1], stack[max + 1], check[number + 1];

    for (int i = 0; i < times; i++) {
        for (int j = 1; j <= number; j++) {
            scanf("%d", &input[j]);
        }
        int k = 1;
        int cur_input = 1, cur_stack = 1, cur_check = 1;
        stack[cur_stack] = k;
        while (cur_check <= number) {
            while(stack[cur_stack] != input[cur_input] && cur_stack < max && k < number) {
                cur_stack++;
                k++;
                stack[cur_stack] = k;
            }
            check[cur_check++] = stack[cur_stack--];
            cur_input++;
        }
        int f = 1;
        for (int k = 1; k <= number; k++) {
            if (check[k] != input[k]) f = 0;
        }
        if (f) printf("YES\n");
        else printf("NO\n");
    }
}