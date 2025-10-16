#include <stdio.h>
#include <stdlib.h>

#define NMAX 100

int input(int **matrix, int h, int w);
void output(int **matrix, int h, int w);
void output_res(int *res, int len);
int **dynamic1(int h, int w);
int **dynamic2(int h, int w);
int **dynamic3(int h, int w);
int input_num(int *num);
int input_size(int *h, int *w);
void free_me(int **matrix, int num, int h);
void min(int **matrix, int h, int w, int **res, int *len);
void max(int **matrix, int h, int w, int **res, int *len);

int main() {
    int h, w, **data = NULL, num;
    int statiq[NMAX][NMAX];
    int *a, len;
    if (input_num(&num) == -1 || input_size(&h, &w) == 1) {
        printf("n/a");
        return 1;
    }
    switch (num) {
        case 1:
            if (h > NMAX || w > NMAX) {
                printf("n/a");
                return 1;
            }
            int *rows[NMAX];
            for (int i = 0; i < h; i++) {
                rows[i] = statiq[i];
            }
            if (input(rows, h, w) == 1) {
                printf("n/a");
                return 1;
            }
            output(rows, h, w);
            printf("\n");
            max(rows, h, w, &a, &len);
            output_res(a, len);
            free(a);
            printf("\n");
            min(rows, h, w, &a, &len);
            output_res(a, len);
            free(a);
            return 0;
        case 2:
            data = dynamic1(h, w);
            break;
        case 3:
            data = dynamic2(h, w);
            break;
        case 4:
            data = dynamic3(h, w);
            break;
    }
    if (data == NULL) {
        printf("n/a");
        return 1;
    }
    if (input(data, h, w) == 1) {
        printf("n/a");
        free_me(data, num, h);
        return 1;
    }
    output(data, h, w);
    printf("\n");
    max(data, h, w, &a, &len);
    output_res(a, len);
    free(a);
    printf("\n");
    min(data, h, w, &a, &len);
    output_res(a, len);
    free(a);
    free_me(data, num, h);
    return 0;
}

int input_num(int *num) {
    char c;
    if ((scanf("%d%c", num, &c) != 2) || c != '\n' || (*num > 4) || (*num < 1)) {
        return -1;
    }
    return 0;
}

int input_size(int *h, int *w) {
    char c1, c2;
    if ((scanf("%d%c%d%c", h, &c1, w, &c2) != 4) || c1 != ' ' || c2 != '\n' || (*h <= 0) || (*w <= 0)) {
        return 1;
    }
    return 0;
}

int input(int **matrix, int h, int w) {
    char c;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) {
            if (scanf("%d%c", &(matrix[i][j]), &c) != 2) {
                return 1;
            }
            if (c != ' ' && c != '\n') {
                return 1;
            }
            if (j == w - 1 && c != '\n') {
                return 1;
            }
            if (j < w - 1 && c != ' ') {
                return 1;
            }
        }
    return 0;
}

void output(int **matrix, int h, int w) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            printf("%d", matrix[i][j]);
            if (j != w - 1) {
                printf(" ");
            }
        }
        if (i != h - 1) {
            printf("\n");
        }
    }
}

void output_res(int *a, int len) {
    for (int *p = a; p - a < len; p++) {
        if (p - a == len - 1) {
            printf("%d", *p);
        } else {
            printf("%d ", *p);
        }
    }
}

int **dynamic1(int h, int w) {
    int **matrix = malloc(sizeof(int *) * h + sizeof(int) * h * w);
    int *val = (int *)(matrix + h);
    for (int i = 0; i < h; i++) {
        matrix[i] = val + i * w;
    }
    return matrix;
}

int **dynamic2(int h, int w) {
    int **matrix = malloc(sizeof(int *) * h);
    for (int i = 0; i < h; i++) {
        matrix[i] = malloc(sizeof(int) * w);
    }
    return matrix;
}

int **dynamic3(int h, int w) {
    int **matrix = malloc(sizeof(int *) * h);
    int *val = malloc(w * h * sizeof(int));

    for (int i = 0; i < h; i++) {
        matrix[i] = val + w * i;
    }
    return matrix;
}

void free_me(int **matrix, int num, int h) {
    if (num == 1) {
        return;
    } else if (num == 2) {
        free(matrix);
    } else if (num == 3) {
        for (int i = 0; i < h; i++) {
            free(matrix[i]);
        }
        free(matrix);
    } else if (num == 4) {
        free(matrix[0]);
        free(matrix);
    }
}

void max(int **matrix, int h, int w, int **res, int *len) {
    *len = h;
    *res = malloc(sizeof(int) * *len);
    for (int i = 0; i < h; i++) {
        int maximum = matrix[i][0];
        for (int j = 0; j < w; j++) {
            if (matrix[i][j] > maximum) {
                maximum = matrix[i][j];
            }
        }
        (*res)[i] = maximum;
    }
}

void min(int **matrix, int h, int w, int **res, int *len) {
    *len = w;
    *res = malloc(sizeof(int) * *len);
    for (int i = 0; i < w; i++) {
        int minimum = matrix[0][i];
        for (int j = 0; j < h; j++) {
            if (matrix[j][i] < minimum) {
                minimum = matrix[j][i];
            }
        }
        (*res)[i] = minimum;
    }
}