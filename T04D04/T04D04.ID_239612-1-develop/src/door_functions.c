#include <math.h>
#include <stdio.h>

#define pi 3.14159265358979323846

double aniezi(double x) {
    double y = (1 / (1 + x * x));
    return y;
}

double bernuli(double x) {
    double y = (sqrt(sqrt(1 + 4 * x * x) - x * x - 1));
    if (sqrt(1 + 4 * x * x) - x * x - 1 < 0) {
        return 1;
    }
    return y;
}
double hyperbola(double x) {
    double y = (1 / (x * x));
    return y;
}

int main(void) {
    for (int i = 0; i < 42; i++) {
        double par = -pi + (2 * pi / 41) * i;
        if (bernuli(par) == 1) {
            printf("%.7f | %.7f | - | %.7f\n", par, aniezi(par), hyperbola(par));
        } else {
            printf("%.7f | %.7f | %.7f | %.7f\n", par, aniezi(par), bernuli(par), hyperbola(par));
        }
    }
    return 0;
}