#include <stdio.h>
#include <stdlib.h>

void sort_vertical(int **matrix, int h, int w, int **result_matrix);
void sort_horizontal(int **matrix, int h, int w, int **result_matrix);
int input(int **matrix, int h, int w);
void output(int **matrix, int h, int w);
int input_size(int *h, int *w);
int **dynamic1(int h, int w);
void buble(int *buf, int n);

int main() {
    int flag = 0;
    int **matrix, **result;
    int h, w;
    flag = input_size(&h, &w);
    if (flag == 0) {
        matrix = dynamic1(h, w);
        flag = input(matrix, h, w);
    }
    if (flag == 1) {
        free(matrix);
    }
    if (flag == 0) {
        result = dynamic1(h, w);
        sort_vertical(matrix, h, w, result);
        output(result, h, w);
        printf("\n\n");
        sort_horizontal(matrix, h, w, result);
        output(result, h, w);
        printf("\n\n");
    } else {
        printf("n/a");
        return 1;
    }
    free(matrix);
    free(result);
    return 0;
}

int input_size(int *h, int *w) {
    int flag = 0;
    char c1, c2;
    if ((scanf("%d%c%d%c", h, &c1, w, &c2) != 4) || c1 != ' ' || c2 != '\n' || (*h <= 0) || (*w <= 0)) {
        flag = -1;
    }
    return flag;
}

int input(int **matrix, int h, int w) {
    char c;
    int flag = 0;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) {
            if (scanf("%d%c", &(matrix[i][j]), &c) != 2) {
                flag = 1;
            }
            if (c != ' ' && c != '\n') {
                flag = 1;
            }
            if (j == w - 1 && c != '\n') {
                flag = 1;
            }
            if (j < w - 1 && c != ' ') {
                flag = 1;
            }
        }
    return flag;
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

int **dynamic1(int h, int w) {
    int **matrix = malloc(sizeof(int *) * h + h * w * sizeof(int));
    int *val = (int *)(matrix + h);
    for (int i = 0; i < h; i++) {
        matrix[i] = val + i * w;
    }
    return matrix;
}

void buble(int *buf, int n) {
    for (int i = 0; i < n; i++) {
        for (int *p = buf; p - buf < n - 1; p++) {
            if (*p > *(p + 1)) {
                int tmp = *p;
                *p = *(p + 1);
                *(p + 1) = tmp;
            }
        }
    }
}

void sort_vertical(int **matrix, int h, int w, int **result_matrix) {
    int *buf = malloc(sizeof(int) * h * w);
    int k = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            buf[k] = matrix[i][j];
            k++;
        }
    }
    buble(buf, k);
    k = 0;
    for (int j = 0; j < w; j++) {
        if (j % 2 == 0) {
            for (int i = 0; i < h; i++) {
                result_matrix[i][j] = buf[k];
                k++;
            }
        } else {
            for (int i = h - 1; i >= 0; i--) {
                result_matrix[i][j] = buf[k];
                k++;
            }
        }
    }
    free(buf);
}

void sort_horizontal(int **matrix, int h, int w, int **result_matrix) {
    int *buf = malloc(sizeof(int) * h * w);
    int k = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            buf[k] = matrix[i][j];
            k++;
        }
    }
    buble(buf, k);
    k = 0;
    for (int i = 0; i < h; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < w; j++) {
                result_matrix[i][j] = buf[k];
                k++;
            }
        } else {
            for (int j = w - 1; j >= 0; j--) {
                result_matrix[i][j] = buf[k];
                k++;
            }
        }
    }
    free(buf);
}