#include <stdio.h>
#include <stdlib.h>

double det(double **matrix, int h);
int input(double **matrix, int h, int w);
void output(double **matrix, int h, int w);
int input_size(int *h, int *w);
double **dynamic1(int h, int w);
double **invert(double **matrix, int h);
void small_matrix(double **matrix, double **small, int i, int j, int h);
double det_small(double **matrix, int i, int j, int h);
double **transpose(double **matrix, int h);

int main() {
    int flag = 0;
    double **matrix = NULL;
    double **res = NULL;
    double **new_res = NULL;
    int h, w;
    flag = input_size(&h, &w);
    if (flag != 0) {
        printf("n/a");
        return 1;
    }
    if (flag == 0) {
        matrix = dynamic1(h, w);
        flag = input(matrix, h, w);
        if (flag != 0) {
            free(matrix);
        }
    }
    if (flag == 1 && matrix != NULL) {
        free(matrix);
    }
    if (det(matrix, h) == 0 && flag == 0) {
        free(matrix);
        flag = 1;
    }
    if (flag == 0) {
        res = invert(matrix, h);
        new_res = transpose(res, h);
        output(new_res, h, w);
    }
    if (matrix != NULL) {
        free(matrix);
    }
    if (new_res != NULL) {
        free(new_res);
    }
    if (res != NULL) {
        free(res);
    }
    return 0;
}

int input_size(int *h, int *w) {
    int flag = 0;
    char c1, c2;
    if ((scanf("%d%c%d%c", h, &c1, w, &c2) != 4) || c1 != ' ' || c2 != '\n' || (*h <= 0) || (*w <= 0) ||
        *h != *w) {
        flag = 1;
    }
    return flag;
}

int input(double **matrix, int h, int w) {
    char c;
    int flag = 0;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) {
            if (scanf("%lf%c", &(matrix[i][j]), &c) != 2) {
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

void output(double **matrix, int h, int w) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            printf("%lf", matrix[i][j]);
            if (j != w - 1) {
                printf(" ");
            }
        }
        if (i != h - 1) {
            printf("\n");
        }
    }
}

double **dynamic1(int h, int w) {
    double **matrix = malloc(sizeof(double *) * h + h * w * sizeof(double));
    double *val = (double *)(matrix + h);
    for (int i = 0; i < h; i++) {
        matrix[i] = val + i * w;
    }
    return matrix;
}

double det(double **matrix, int h) {
    double res = 0.0;

    if (h == 1) {
        res = matrix[0][0];
    } else if (h == 2) {
        res = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    } else {
        int a = 1;
        double **small = (double **)(malloc(sizeof(double *) * (h - 1)));
        for (int i = 0; i < h - 1; i++) {
            small[i] = (double *)(malloc(sizeof(double) * (h - 1)));
        }
        for (int i = 0; i < h; i++) {
            small_matrix(matrix, small, i, 0, h);
            res += a * matrix[i][0] * det(small, h - 1);
            a *= -1;
        }
        for (int i = 0; i < h - 1; i++) {
            free(small[i]);
        }
        free(small);
    }
    return res;
}

double **invert(double **matrix, int h) {
    double determinant = det(matrix, h);
    double **res;
    res = dynamic1(h, h);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < h; j++) {
            res[i][j] = det_small(matrix, i, j, h) / determinant;
        }
    }
    return res;
}

double det_small(double **matrix, int i, int j, int h) {
    double res;
    double **small;
    small = dynamic1(h - 1, h - 1);
    small_matrix(matrix, small, i, j, h);
    res = det(small, h - 1);
    if ((i + j) % 2 != 0) {
        res *= -1;
    }
    free(small);
    return res;
}

void small_matrix(double **matrix, double **small, int i, int j, int h) {
    int ri = 0;
    for (int k = 0; k < h; k++) {
        if (k == i) continue;
        int rj = 0;
        for (int l = 0; l < h; l++) {
            if (l == j) continue;
            small[ri][rj] = matrix[k][l];
            rj++;
        }
        ri++;
    }
}

double **transpose(double **matrix, int h) {
    double **matrix_result = dynamic1(h, h);

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < h; j++) {
            matrix_result[i][j] = matrix[j][i];
        }
    }
    return matrix_result;
}
