#include <math.h>
#include <stdio.h>

#define pi 3.14159265358979323846
#define dif 0.153248422126331

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
    printf("ANIEZI\n\n");
    for (int j = 0; j < 21; j++) {
        double h = 1.0 - (2.0 * j) / 20;
        for (int i = 0; i < 42; i++) {
            double x = -pi + dif * i;
            double y = aniezi(x);
            if (fabs(y - h) < (1.0 / 21)) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    printf("BERNULI\n\n");
    for (int j = 0; j < 21; j++) {
        double h = 1.0 - (2.0 * j) / 20;
        for (int i = 0; i < 42; i++) {
            double x = -pi + dif * i;
            double y = bernuli(x);
            if (fabs(y - h) < (1.0 / 21)) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");

    }
    printf("HYPER\n\n");
    for (int j = 0; j < 21; j++) {
        double h = 1.0 - (2.0 * j) / 20;
        for (int i = 0; i < 42; i++) {
            double x = -pi + dif * i;
            double y = hyperbola(x);
            if (fabs(y - h) < (1.0 / 21)) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;

}
