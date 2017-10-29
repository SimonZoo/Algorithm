//想了好久怎么做同行N输入结果并不用啊？？？
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    int mark[100];
    memset(mark, 0, 100*sizeof(int));

    int i;
    scanf("%d", &i);
    int input[i];
    int key[i];
    
    for (int j = 0; j < i; j++) {
        scanf("%d", &input[j]);
    }
    for (int j = 0; j < i; j++) {
        int cur = input[j];
        while(cur != 1) {
            if (cur % 2) {
                cur = (3 * cur + 1) / 2;
            } else {
                cur = cur / 2;
            }
            for (int k = 0;k < i; k++) {
                //判断当前数字是否小于100，33以上奇数溢出
                if (cur == input[k] && cur <= 100) {
                    mark[input[k]] = 1;
                }
            }
        }
    }
    int num_of_key = 0;
    for (int k = 0; k < i; k++) {
        if (mark[input[k]] == 0) {
            key[num_of_key] = input[k];
            num_of_key++;
        }
    }
    //选择..
    for (int k = 0; k < num_of_key; k++) {
        int max_pos = k;
        for (int j = k + 1; j < num_of_key; j++) {
            if (key[j] > key[max_pos]) {
                max_pos = j;
            }
        }
        if (max_pos != k) {
            int temp = key[k];
            key[k] = key[max_pos];
            key[max_pos] = temp;
        }
    }
    for (int k = 0; k < num_of_key - 1; k++) {
        printf("%d ", key[k]);
    }
    printf("%d", key[num_of_key - 1]);
}