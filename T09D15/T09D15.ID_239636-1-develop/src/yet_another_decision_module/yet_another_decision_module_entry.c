#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "decision.h"

int main() {
    double *data;
    int n;
    int flag;

    flag = input(&data, &n);

    if (flag == 1 && make_decision(data, n)) {
        printf("YES");
    } else {
        printf("NO");
    }
    free(data);
    return 0;
}
