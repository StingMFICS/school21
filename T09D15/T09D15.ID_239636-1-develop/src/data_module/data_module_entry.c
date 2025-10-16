#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "data_process.h"

int main() {
    double *data = NULL;
    int n;
    int flag;

    // Don`t forget to allocate memory !

    flag = input(&data, &n);

    if (flag == 1 && normalization(data, n)) {
        output(data, n);
    } else {
        printf("ERROR");
    }
    free(data);
    return 0;
}
