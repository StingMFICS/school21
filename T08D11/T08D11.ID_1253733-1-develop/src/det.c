#include <stdio.h>
#include <stdlib.h>

double det(double **matrix, int h);
int input(double **matrix, int h, int w);
void output(double res);
int input_size(int *h, int *w);
double **dynamic1(int h, int w);

int main() {
    int flag = 0;
    double **matrix;
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
        double res = det(matrix, h);
        output(res);
        free(matrix);
    } else {
        printf("n/a");
        return 1;
    }
    return 0;
}

int input_size(int *h, int *w) {
    int flag = 0;
    char c1, c2;
    if ((scanf("%d%c%d%c", h, &c1, w, &c2) != 4) || c1 != ' ' || c2 != '\n' || (*h <= 0) || (*w <= 0) ||
        *h != *w) {
        flag = -1;
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

void output(double res) { printf("%lf", res); }

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
            int i1 = 0, j1 = 0;
            for (int k = 0; k < h - 1; k++) {
                if (k == i) {
                    i1 = 1;
                }
                j1 = 0;
                for (int l = 0; l < h - 1; l++) {
                    if (l == 0) {
                        j1 = 1;
                    }

                    small[k][l] = matrix[k + i1][l + j1];
                }
            }
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