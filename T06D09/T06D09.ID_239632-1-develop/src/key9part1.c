/*------------------------------------
        Здравствуй, человек!
        Чтобы получить ключ
        поработай с комментариями.
-------------------------------------*/

#include <stdio.h>

int input(int *buffer, int *length);
void output(int *buffer, int length, int sum);
int sum_numbers(int *buffer, int length);
void find_numbers(int *buffer, int length, int sum, int *numbers, int *new_len);

#define NMAX 10
/*------------------------------------
        Функция получает массив данных
        через stdin.
        Выдает в stdout особую сумму
        и сформированный массив
        специальных элементов
        (выбранных с помощью найденной суммы):
        это и будет частью ключа
-------------------------------------*/
int main() {
    int length, data[NMAX], numbers[NMAX], sum, new_len;
    if (input(data, &length) == 1) {
        printf("n/a");
        return 0;
    }
    sum = sum_numbers(data, length);
    find_numbers(data, length, sum, numbers, &new_len);
    output(numbers, new_len, sum);

    return 0;
}

/*------------------------------------
        Функция должна находить
        сумму четных элементов
        с 0-й позиции.
-------------------------------------*/
int sum_numbers(int *buffer, int length) {
    int sum = 0;

    for (int i = 0; i < length; i++) {
        if (buffer[i] % 2 == 0) {
            sum = sum + buffer[i];
        }
    }
    return sum;
}

/*------------------------------------
        Функция должна находить
        все элементы, на которые нацело
        делится переданное число и
        записывает их в выходной массив.
-------------------------------------*/
void find_numbers(int *buffer, int length, int sum, int *numbers, int *new_len) {
    for (int *p = buffer; p - buffer < length; p++) {
        if (*p != 0 && sum % *p == 0) {
            *(numbers + *new_len) = *p;
            (*new_len)++;
        }
    }
}

int input(int *buffer, int *length) {
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
    return 0;
}
void output(int *buffer, int length, int sum) {
    printf("%d\n", sum);
    for (int *p = buffer; p - buffer < length; p++) {
        if (p - buffer == length - 1) {
            printf("%d", *p);
        } else {
            printf("%d ", *p);
        }
    }
}
