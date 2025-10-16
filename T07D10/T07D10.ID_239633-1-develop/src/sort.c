#include <stdio.h>
#include <stdlib.h>

int input(int **a, int *);
void output(int *a, int n);
void buble(int *a, int n);

int main() {
    int *data = NULL, n;
    if (input(&data, &n) == 1) {
        printf("n/a");
        free(data);
        return 0;
    }
    buble(data, n);
    output(data, n);
    free(data);
    return 0;
}

int input(int **a, int *n) {
    char c;
    if (scanf("%d%c", n, &c) != 2 || c != '\n' || *n <= 0) {
        return 1;
    };
    *a = (int *)malloc(sizeof(int) * *n);
    if (*a == NULL) {
        return 1;
    }
    for (int *p = *a; p - *a < *n; p++) {
        if (scanf("%d%c", p, &c) != 2) {
            return 1;
        }
        if (p - *a != *n - 1) {
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
            printf("%d", *p);
        } else {
            printf("%d ", *p);
        }
    }
}

void buble(int *a, int n) {
    for (int i = 0; i < n; i++) {
        for (int *p = a; p - a < n - 1; p++) {
            if (*p > *(p + 1)) {
                int tmp = *p;
                *p = *(p + 1);
                *(p + 1) = tmp;
            }
        }
    }
}