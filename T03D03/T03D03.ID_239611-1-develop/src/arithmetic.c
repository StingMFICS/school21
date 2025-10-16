#include <stdio.h>

int sum(int a, int b);
int min(int a, int b);
int mul(int a, int b);
int div(int a, int b);

int main() {
    int a, b;
    char c = ' ';
    if (scanf("%d %d%c", &a, &b, &c) != 3 || c != '\n') {
        printf("n/a");
        return 1;
    }

    printf("%d ", sum(a, b));
    printf("%d ", min(a, b));
    printf("%d ", mul(a, b));
    if (b == 0) {
        printf("n/a");
    } else {
        printf("%d\n", div(a, b));
    }
    return 0;
}
int sum(int a, int b) { return (a + b); }
int min(int a, int b) { return (a - b); }
int mul(int a, int b) { return (a * b); }
int div(int a, int b) { return (a / b); }