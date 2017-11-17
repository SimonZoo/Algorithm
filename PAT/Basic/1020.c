//精度问题 用float
#include <stdio.h>
int main(void) {
    int kind, market;
    scanf("%d %d", &kind, &market);
    float count[kind];
    float price[kind];
    double count_price[kind];
    double one = 1;
    int sign[kind];
    for (int i = 0; i < kind; i++) {
        scanf("%d", &count[i]);
    }
    for (int i = 0; i < kind; i++) {
        scanf("%d", &price[i]);
        count_price[i] = price[i] / (count[i] * one);
    }
    for (int j = 0; j < kind; j++) {
        int max = j;
        for (int k = 0; k < kind; k++) {
            if (count_price[max] < count_price[k])  max = k;
        }
        sign[j] = max;
        count_price[max] = 0.0;
    }
    float cur_good = market;
    double sum = 0.0;
    for (int i = 0; i < kind; i++) {
        if (cur_good >= count[sign[i]]) {
            sum = sum + price[sign[i]];
            cur_good = cur_good - count[sign[i]];
        } else if (cur_good < count[i] && cur_good !=0) {
            sum = sum + cur_good * one / count[sign[i]] * price[sign[i]];
            cur_good = 0;
        }
    }
    printf("%.2f", sum);
}