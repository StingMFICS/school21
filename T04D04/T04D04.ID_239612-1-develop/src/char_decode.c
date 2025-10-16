#include <math.h>
#include <stdio.h>

void code() {
    char ch = 0;
    char current = 0;
    int valid = 1;

    while ((ch = getchar()) != '\n' && valid) {
        if (ch == ' ') {
            if (current != 0) {
                printf("%X ", current);
                current = 0;
            } else {
                valid = 0;
            }
        } else {
            if (current == 0) {
                current = ch;
            } else {
                valid = 0;
            }
        }
    }

    if (!valid) {
        printf("n/a");
    } else if (current != 0) {
        printf("%X", current);
    }
}

void decode() {
    int code = 0;
    char separator = 0;
    int valid = 1;

    while (valid && separator != '\n') {
        if (scanf("%2X%c", &code, &separator) != 2) {
            valid = 0;
            break;
        }

        if (separator == ' ') {
            printf("%c ", code);
        } else if (separator == '\n') {
            printf("%c", code);
        } else {
            valid = 0;
        }
    }

    if (!valid) {
        printf("n/a");
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("n/a");
        return 1;
    }

    int c = argv[1][0];

    if (argv[1][1] != '\0') {
        printf("n/a");
        return 1;
    }

    if (c == '0') {
        code();
    } else if (c == '1') {
        decode();
    } else {
        printf("n/a");
    }

    return 0;
}