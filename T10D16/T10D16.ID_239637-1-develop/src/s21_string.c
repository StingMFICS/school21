#include "s21_string.h"

#include <stdio.h>
#include <stdlib.h>

size_t s21_strlen(const char *str) {
    size_t cnt = 0;
    while (*str) {
        cnt++;
        str++;
    }
    return cnt;
}

int s21_strcmp(const char *str1, const char *str2) {
    for (; *str1 && *str1 == *str2; str1++, str2++);
    return *str1 - *str2;
}

char *s21_strcpy(char *new, const char *old) {
    char *result = new;
    while (*old != '\0') {
        *result = *old;
        result++;
        old++;
    }
    *result = '\0';
    return new;
}

char *s21_strcat(char *new, const char *old) {
    char *result = new;
    while (*result) {
        result++;
    }
    while (*old != '\0') {
        *result = *old;
        result++;
        old++;
    }
    *result = '\0';
    return new;
}

char *s21_strchr(const char *str, int n) {
    char *res = NULL;
    while (*str != '\0' && *str != n) {
        str++;
    }
    if (*str == n) {
        res = (char *)str;
    }
    return res;
}

char *s21_strstr(const char *str1, const char *str2) {
    char *res = NULL;
    int flag = 0;
    if (*str2 == '\0') {
        res = (char *)str1;
        flag = 1;
    }
    for (; !flag && *str1 != '\0'; str1++) {
        const char *a = str1;
        const char *b = str2;
        while (*a != '\0' && *b != '\0' && *a == *b) {
            a++;
            b++;
        }
        if (*b == '\0') {
            res = (char *)str1;
            flag = 1;
        }
    }
    return res;
}
