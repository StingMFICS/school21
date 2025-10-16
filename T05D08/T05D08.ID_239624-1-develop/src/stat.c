#include <stdio.h>
#include <math.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v,
                   int min_v,
                   double mean_v,
                   double variance_v);

int main()
{
    int n, data[NMAX];
    if (input(data, &n) == 1) {
        printf("n/a");
        return 0;
    };
    output(data, n);
    output_result(max(data, n),
                  min(data, n),
                  mean(data, n),
                  variance(data, n));

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
void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        if (p - a == n - 1) {
            printf("%d\n", *p);
        } else {
            printf("%d ", *p);
        }
    }
}

void output_result(int max_v,
                   int min_v,
                   double mean_v,
                   double variance_v) {
    printf("%d %d %6lf %6lf", max_v, min_v, mean_v, variance_v);
                   }
int max(int *a, int n) {
    int max = *a;
    for (int *p = a + 1; p - a < n; p++) {
        if (*p > max) {
            max = *p;
        }
    }
    return max;
}

int min(int *a, int n) {
    int min = *a;
    for (int *p = a + 1; p - a < n; p++) {
        if (*p < min) {
            min = *p;
        }
    }
    return min;
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
        res += pow((*p-sred), 2);
    }
    return res / n;
}