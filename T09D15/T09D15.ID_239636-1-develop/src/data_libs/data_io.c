#include "data_io.h"

#include <stdio.h>
#include <stdlib.h>

int input(double **data, int *n) {
    if (scanf("%d", n) != 1 || *n <= 0) {
        *n = 0;
        return 0;
    };

    *data = malloc(*n * sizeof(double));
    if (*data == NULL) {
        *n = 0;
        return 0;
    }
    for (int i = 0; i < *n; i++) {
        if (scanf("%lf", (*data + i)) != 1) {
            free(*data);
            *data = NULL;
            return 0;
        }
    }

    return 1;
}

void output(double *data, int n) {
    if (data) {
        for (int i = 0; i < n; i++) {
            printf("%.2lf", data[i]);
            if (i < n - 1) {
                printf(" ");
            }
        }
    }
}
