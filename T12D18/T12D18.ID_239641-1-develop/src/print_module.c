#include "print_module.h"

#include <stdio.h>
#include <time.h>

char print_char(char ch) { return putchar(ch); }

void print_log(char (*print)(char), char *message) {
    char *log = Log_prefix;
    while (*log != '\0') {
        print(*log);
        log++;
    }

    time_t full_time;
    time(&full_time);
    struct tm *ttime = localtime(&full_time);

    char str_time[10];

    strftime(str_time, sizeof(str_time), "%H:%M:%S", ttime);

    char *tmp = str_time;
    while (*tmp != '\0') {
        print(*tmp);
        tmp++;
    }
    print(' ');

    if (message) {
        while (*message != '\0') {
            print(*message);
            message++;
        }
    }
}
