#include <math.h>
#include <stdio.h>

int main(void) {
    double x;
    char c;

    if (scanf("%lf%c", &x, &c) != 2 || c != '\n' || x == 0) {
        printf("n/a\n");
        return 1;
    }

    double y = 7e-3 * pow(x, 4) + ((22.8 * pow(x, 1.0 / 3.0) - 1000) * x + 3) / (pow(x, 2) / 2.0) -
               x * pow(10.0 + x, 2.0 / x) - 1.01;

    printf("%.1lf\n", y);

    return 0;
}