/*
    Search module for the desired value from data array.

    Returned value must be:
        - "even"
        - ">= mean"
        - "<= mean + 3 * sqrt(variance)"
        - "!= 0"

        OR

        0
*/

#include <math.h>
#include <stdio.h>
#define NMAX 30

int input(int *a, int *n);
int output(int *a, int n);
int is_even(int x);
double mean(int *a, int n);
double sigma(int *a, int n);
double variance(int *a, int n);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == 1) {
        printf("n/a");
        return 0;
    };
    output(data, n);
    return 0;
}

int input(int *a, int *n) {
    char c;
    if (scanf("%d%c", n, &c) != 2 || c != '\n' || *n <= 0 || *n > NMAX) {
        return 1;
    };
    for (int *p = a; p - a < *n; p++) {
        if (scanf("%d%c", p, &c) != 2) {
            return 1;
        }
        if (p - a != *n - 1) {
            if (c != ' ') {
                return 1;
            }
        } else {
            if (c != '\n') {
                return 1;
            }
        }
    }
    return 0;
}
int output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        if (is_even(*p) == 0 && *p >= mean(a, n) && *p <= sigma(a, n) && *p != 0) {
            printf("%d", *p);
            return 0;
        }
    }
    printf("0");
    return 0;
}

double mean(int *a, int n) {
    double sum = *a;
    for (int *p = a + 1; p - a < n; p++) {
        sum += *p;
    }
    return sum / n;
}

double variance(int *a, int n) {
    double res = 0;
    double sred = mean(a, n);
    for (int *p = a; p - a < n; p++) {
        res += pow((*p - sred), 2);
    }
    return res / n;
}

int is_even(int x) {
    if (x % 2 != 0) {
        return 1;
    }
    return 0;
}

double sigma(int *a, int n) {
    double res;
    res = mean(a, n) + 3 * sqrt(variance(a, n));
    return res;
}