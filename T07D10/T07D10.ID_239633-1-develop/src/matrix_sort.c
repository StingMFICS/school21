#include <stdio.h>
#include <stdlib.h>

int input(int **matrix, int h, int w);
void output(int **matrix, int h, int w);
int **dynamic1(int h, int w);
int **dynamic2(int h, int w);
int **dynamic3(int h, int w);
int input_num(int *num);
int input_size(int *h, int *w);
void free_me(int **matrix, int num, int h);
int sum(int *a, int len);
void buble(int **matrix, int h, int w);

int main() {
    int h, w, **data = NULL, num;
    if (input_num(&num) == -1 || input_size(&h, &w) == 1) {
        printf("n/a");
        return 1;
    }
    switch (num) {
        case 1:
            data = dynamic1(h, w);
            break;
        case 2:
            data = dynamic2(h, w);
            break;
        case 3:
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
    buble(data, h, w);
    output(data, h, w);
    free_me(data, num, h);
    return 0;
}

int input_num(int *num) {
    char c;
    if ((scanf("%d%c", num, &c) != 2) || c != '\n' || (*num > 3) || (*num < 1)) {
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
        free(matrix);
    } else if (num == 2) {
        for (int i = 0; i < h; i++) {
            free(matrix[i]);
        }
        free(matrix);
    } else if (num == 3) {
        free(matrix[0]);
        free(matrix);
    }
}

int sum(int *a, int len) {
    int sum;
    for (int i = 0; i < len; i++) {
        sum += a[i];
    }
    return sum;
}

void buble(int **matrix, int h, int w) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < h - 1; j++) {
            if (sum(matrix[j], w) > sum(matrix[j + 1], w)) {
                int *tmp = matrix[j];
                matrix[j] = matrix[j + 1];
                matrix[j + 1] = tmp;
            }
        }
    }
}