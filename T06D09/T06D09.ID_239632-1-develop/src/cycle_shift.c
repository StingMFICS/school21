
#include <stdio.h>

int input(int *buffer, int *length, int *sh);
void output(int *buffer, int length);
void shift(int *buffer, int length, int sh);

#define NMAX 10
int main() {
    int length, data[NMAX], sh;
    if (input(data, &length, &sh) == 1) {
        printf("n/a");
        return 0;
    }
    shift(data, length, sh);
    output(data, length);

    return 0;
}

int input(int *buffer, int *length, int *sh) {
    char c;
    if (scanf("%d%c", length, &c) != 2 || c != '\n' || *length <= 0 || *length > NMAX) {
        return 1;
    };
    for (int *p = buffer; p - buffer < *length; p++) {
        if (scanf("%d%c", p, &c) != 2) {
            return 1;
        }
        if (p - buffer != *length - 1) {
            if (c != ' ') {
                return 1;
            }
        } else {
            if (c != '\n') {
                return 1;
            }
        }
    }
    if (scanf("%d%c", sh, &c) != 2 || c != '\n') {
        return 1;
    }
    return 0;
}
void output(int *buffer, int length) {
    for (int *p = buffer; p - buffer < length; p++) {
        if (p - buffer == length - 1) {
            printf("%d", *p);
        } else {
            printf("%d ", *p);
        }
    }
}

void shift(int *buffer, int length, int sh) {
    sh = sh % length;
    if (sh < 0) {
        sh = sh + length;
    }
    for (int i = 0; i < sh; i++) {
        int tmp = *buffer;
        for (int *p = buffer; p - buffer < length; p++) {
            ;
            if (p - buffer == length - 1) {
                *p = tmp;
            } else {
                *p = *(p + 1);
            }
        }
    }
}