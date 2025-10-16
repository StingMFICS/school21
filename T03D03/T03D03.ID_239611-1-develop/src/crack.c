#include <stdio.h>

int main(void) {
    double a, b;
    char c;
    if (scanf("%lf %lf%c", &a, &b, &c) != 3 || c != '\n') {
        printf("n/a\n");
        return 1;
    }
    if (a * a + b * b < 25) {
        printf("GOTCHA\n");
    } else {
        printf("MISS\n");
    }
    return 0;
}