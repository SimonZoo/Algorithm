//score17 格式错误
#include <stdio.h>

int main(void) {
    int N;
    scanf("%d", &N);
    int raw[N];
    int flag[5] = {0, 0, 0, 0, 0};
    int five[5] = {0, 0, 0, 0, 0};
    //flag和储存分开，因为A3最后加减的结果可能是0
    int flag_A3 = 1;
    // int count_2 = 0;
    float sum = 0;
    float count_3 = 0;
    int max = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d",&raw[i]);
        if (raw[i] % 5 == 0 && raw[i] % 2== 0) {
            flag[0] = 1;
            five[0] = five[0] + raw[i];
        } else if (raw[i] % 5 == 1) {
            flag[1] = 1;
            five[1] = five[1] + flag_A3 * raw[i];
            flag_A3 = -flag_A3;
        }else if (raw[i] % 5 == 2) {
            flag[2] = 1;
            five[2]++;
        }else if (raw[i] % 5 == 3) {
            flag[3] = 1;
            five[3] = 1;
            count_3++;
            sum = sum + raw[i];
        }else if (raw[i] % 5 == 4) {
            flag[4] = 1;
            if (raw[i] > five[4]) five[4] = raw[i];
        }
    }

    for (int i = 0; i < 3; i++) {
        if (flag[i] == 0) {
            printf("N ");
        } else {
            printf("%d ", five[i]);
        }
    }
    if (five[3] == 0) printf("N ");
    else printf("%.1f ", sum / count_3);

    if (five[4] == 0) printf("N");
    else printf("%d", five[4]);
}