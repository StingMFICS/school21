#include <stdio.h>

#define NMAX 100

void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
int sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
int input(int *buff_0, int *len);
void output(int *result, int result_length);
int first_larger(int *buff1, int len1, int *buff2, int len2);
/*
    Беззнаковая целочисленная длинная арифметика
    с использованием массивов.
    Ввод:
     * 2 длинных числа в виде массивов до 100 элементов
     * В один элемент массива нельзя вводить число > 9
    Вывод:
     * Результат сложения и разности чисел-массивов
    Пример:
     * 1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 6 1
       2 9

       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 9 0
       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 3 2
*/
int main() {
    int buff1[NMAX], len1, buff2[NMAX], len2, result[NMAX + 1], result_length;
    if (input(buff1, &len1) == 1 || input(buff2, &len2) == 1) {
        printf("n/a");
        return 0;
    }
    sum(buff1, len1, buff2, len2, result, &result_length);
    output(result, result_length);
    printf("\n");
    if (sub(buff1, len1, buff2, len2, result, &result_length) == 1) {
        printf("n/a");
    } else {
        output(result, result_length);
    }
    return 0;
}

int input(int *buff_0, int *len) {
    char c;
    *len = 0;
    int *buff = buff_0;
    while (*len < NMAX) {
        if (scanf("%d%c", buff, &c) != 2 || (c != ' ' && c != '\n') || *buff > 9 || *buff < 0) {
            return 1;
        }
        (*len)++;
        buff++;
        if (c == '\n') {
            break;
        }
    }
    if (*len == 0) {
        return 1;
    }
    return 0;
}
void output(int *result, int result_length) {
    for (int *p = result; p - result < result_length; p++) {
        if (p - result == result_length - 1) {
            printf("%d", *p);
        } else {
            printf("%d ", *p);
        }
    }
}

int first_larger(int *buff1, int len1, int *buff2, int len2) {
    if (len1 < len2) {
        return 1;
    } else if (len1 == len2) {
        for (int i = 0; i < len1; i++) {
            if (buff1[i] > buff2[i]) {
                return 0;
            }
            if (buff1[i] < buff2[i]) {
                return 1;
            }
        }
    }
    return 0;
}

void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length) {
    int ost = 0, dig_1, dig_2;
    int i = len1 - 1, j = len2 - 1;
    int k = (len1 > len2) ? len1 : len2;
    *result_length = k + 1;
    for (; k >= 0; k--) {
        if (i >= 0) {
            dig_1 = *(buff1 + i);
            i--;
        } else {
            dig_1 = 0;
        }
        if (j >= 0) {
            dig_2 = *(buff2 + j);
            j--;
        } else {
            dig_2 = 0;
        }
        int sum = dig_1 + dig_2 + ost;
        *(result + k) = sum % 10;
        ost = sum / 10;
    }
    while (*result == 0) {
        for (int *p = result; p - result < *result_length; p++) {
            *p = *(p + 1);
        }
        *result_length -= 1;
    }
}

int sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length) {
    if (first_larger(buff1, len1, buff2, len2) == 1) {
        return 1;
    }
    int ost = 0, dig_1, dig_2;
    int i = len1 - 1, j = len2 - 1, k = len1 - 1;
    *result_length = k + 1;
    for (; k >= 0; k--) {
        if (i >= 0) {
            dig_1 = *(buff1 + i);
            i--;
        } else {
            dig_1 = 0;
        }
        if (j >= 0) {
            dig_2 = *(buff2 + j);
            j--;
        } else {
            dig_2 = 0;
        }
        int diff = dig_1 - dig_2 - ost;
        if (diff < 0) {
            diff += 10;
            ost = 1;
        } else {
            ost = 0;
        }
        *(result + k) = diff;
    }
    while (*result == 0) {
        for (int *p = result; p - result < *result_length; p++) {
            *p = *(p + 1);
        }
        *result_length -= 1;
    }
    return 0;
}