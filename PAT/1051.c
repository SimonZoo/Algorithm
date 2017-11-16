#include <stdio.h>
#include <math.h>

int main(void) {
    double R1, P1, R2, P2;
    scanf("%lf %lf %lf %lf", &R1, &P1, &R2, &P2);
    double a1 = R1 * cos(P1);
    double b1 = R1 * sin(P1);
    double a2 = R2 * cos(P2);
    double b2 = R2 * sin(P2);
    double a = a1 * a2 - b1 * b2;
    double b = a1 * b2 + a2 * b1;
    if (a + 0.005 >= 0 && a < 0) {
        printf("0.00");
    } else {
        printf("%.2lf", a);
    }
    if (b >= 0) {
        printf("+%.2lfi", b);
    } else if (b + 0.005 >= 0 && b < 0) { // 对浮点数的判断-0.00001的时候应该输出0.00 而不是-0.00
        printf("+0.00i");
    } else {
        printf("%.2lfi", b);
    }

}