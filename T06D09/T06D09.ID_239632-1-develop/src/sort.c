#include <stdio.h>

int input(int *a);
void output(int *a);
void buble(int *a);

#define NMAX 10

int main() {
    int data[NMAX];
    if (input(data) == 1) {
        printf("n/a");
        return 0;
    }
    buble(data);
    output(data);

    return 0;
}

int input(int *a) {
    char c;
    for (int *p = a; p - a < NMAX; p++) {
        if (scanf("%d%c", p, &c) != 2) {
            return 1;
        }
        if (p - a != NMAX - 1) {
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
void output(int *a) {
    for (int *p = a; p - a < NMAX; p++) {
        if (p - a == NMAX - 1) {
            printf("%d", *p);
        } else {
            printf("%d ", *p);
        }
    }
}

void buble(int *a) {
    for (int i = 0; i < NMAX; i++) {
        for (int *p = a; p - a < NMAX - 1; p++) {
            if (*p > *(p + 1)) {
                int tmp = *p;
                *p = *(p + 1);
                *(p + 1) = tmp;
            }
        }
    }
}