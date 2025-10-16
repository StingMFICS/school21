#include "get.h"

#include <stdio.h>
#include <stdlib.h>

char *input(int *error, int *len) {
    char *expression = NULL;

    do {
        expression = great(expression, *len, error);
        expression[*len] = getchar();
    } while (expression[(*len)++] != '\n' && !(*error));

    expression[*len - 1] = '\0';
    return expression;
}

char *great(char *expression, int len, int *error) {
    char *tmp = realloc(expression, (len + 1) * sizeof(char));
    if (tmp == NULL) {
        free(expression);
        *error = 9;
    }
    return tmp;
}

void print_start_message() {
    printf(
        "Ввведи выражения используя следующие операторы и функции: "
        "+, -, *, /, (), sin, cos, tan, ctg, sqrt, ln:\n");
}
