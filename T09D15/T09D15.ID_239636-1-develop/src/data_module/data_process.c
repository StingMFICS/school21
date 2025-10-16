#include "data_process.h"

#include <math.h>
#include <stdio.h>

#include "../data_libs/data_stat.h"

int normalization(double *data, int n) {
    if (n <= 0 || data == NULL) {
        return 0;
    }
    int result = 1;
    double max_value = max(data, n);
    double min_value = min(data, n);
    double size = max_value - min_value;

    if (fabs(size) <= EPS) {
        result = 0;
    }
    if (result) {
        for (int i = 0; i < n; i++) {
            data[i] = data[i] / size - min_value / size;
        }
    }

    return result;
}
