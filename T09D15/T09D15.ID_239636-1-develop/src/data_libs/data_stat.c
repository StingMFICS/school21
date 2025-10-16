#include "data_stat.h"

#include <math.h>
#include <stdio.h>

double max(double *data, int n) {
    double max = *data;
    for (double *p = data + 1; p - data < n; p++) {
        if (*p > max) {
            max = *p;
        }
    }
    return max;
}

double min(double *data, int n) {
    double min = *data;
    for (double *p = data + 1; p - data < n; p++) {
        if (*p < min) {
            min = *p;
        }
    }
    return min;
}

double mean(double *data, int n) {
    double sum = *data;
    for (double *p = data + 1; p - data < n; p++) {
        sum += *p;
    }
    return sum / n;
}

double variance(double *data, int n) {
    double res = 0;
    double sred = mean(data, n);
    for (double *p = data; p - data < n; p++) {
        res += pow((*p - sred), 2);
    }
    return res / n;
}

void sort(double *data, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (data[j] > data[j + 1]) {
                double tmp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = tmp;
            }
        }
    }
}
