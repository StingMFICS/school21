#include <math.h>
#include <stdio.h>

int fib(int a);

int main(void) {
    int a;
    char c;
    if (scanf("%d%c", &a, &c) != 2 || c != '\n') {
        printf("n/a");
        return 1;
    } else {
        printf("%d", fib(a));
    }
    return 0;
}

int fib(int a) {
    if (a == 0) {
        return 0;
    }

    if ((a == 1) || (a == 1)) {
        return 1;
    }

    return fib(a - 1) + fib(a - 2);
}