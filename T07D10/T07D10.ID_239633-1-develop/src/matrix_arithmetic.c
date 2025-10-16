#include <stdio.h>
#include <stdlib.h>

int **dynamic1(int h, int w);
int input_num(int *num);
int input_size(int *h, int *w);
void free_me(int **matrix);
int input(int **matrix, int n, int m);
void output(int **matrix, int n, int m);
int sum(int **matrix_first, int n_first, int m_first, int **matrix_second, int n_second, int m_second,
        int ***matrix_result, int *n_result, int *m_result);
int transpose(int **matrix, int n, int m, int ***matrix_result, int *n_result, int *m_result);
int mul(int **matrix_first, int n_first, int m_first, int **matrix_second, int n_second, int m_second,
        int ***matrix_result, int *n_result, int *m_result);

int main() {
    int **matrix_result = NULL, n_result, m_result, num;
    if (input_num(&num)) {
        printf("n/a");
        return 1;
    }

    if (num == 1) {
        int **matrix_first, **matrix_second;
        int n_first, m_first, n_second, m_second;
        if (input_size(&n_first, &m_first)) {
            printf("n/a");
            return 1;
        }
        matrix_first = dynamic1(n_first, m_first);
        if (input(matrix_first, n_first, m_first)) {
            printf("n/a");
            free_me(matrix_first);
            return 1;
        }
        if (input_size(&n_second, &m_second)) {
            printf("n/a");
            free_me(matrix_first);
            return 1;
        }
        matrix_second = dynamic1(n_second, m_second);
        if (input(matrix_second, n_second, m_second)) {
            printf("n/a");
            free_me(matrix_first);
            free_me(matrix_second);
            return 1;
        }
        if (sum(matrix_first, n_first, m_first, matrix_second, n_second, m_second, &matrix_result, &n_result,
                &m_result)) {
            printf("n/a");
            free_me(matrix_first);
            free_me(matrix_second);
            return 1;
        }
        output(matrix_result, n_result, m_result);
        free_me(matrix_first);
        free_me(matrix_second);
        free_me(matrix_result);
    } else if (num == 2) {
        int **matrix_first, **matrix_second;
        int n_first, m_first, n_second, m_second;
        if (input_size(&n_first, &m_first)) {
            printf("n/a");
            return 1;
        }
        matrix_first = dynamic1(n_first, m_first);
        if (input(matrix_first, n_first, m_first)) {
            printf("n/a");
            free_me(matrix_first);
            return 1;
        }
        if (input_size(&n_second, &m_second)) {
            printf("n/a");
            free_me(matrix_first);
            return 1;
        }
        matrix_second = dynamic1(n_second, m_second);
        if (input(matrix_second, n_second, m_second)) {
            printf("n/a");
            free_me(matrix_first);
            free_me(matrix_second);
            return 1;
        }
        if (mul(matrix_first, n_first, m_first, matrix_second, n_second, m_second, &matrix_result, &n_result,
                &m_result)) {
            printf("n/a");
            free_me(matrix_first);
            free_me(matrix_second);
            return 1;
        }
        output(matrix_result, n_result, m_result);
        free_me(matrix_first);
        free_me(matrix_second);
        free_me(matrix_result);
    } else if (num == 3) {
        int **matrix_first;
        int n_first, m_first;
        if (input_size(&n_first, &m_first)) {
            printf("n/a");
            return 1;
        }
        matrix_first = dynamic1(n_first, m_first);
        if (input(matrix_first, n_first, m_first)) {
            printf("n/a");
            free_me(matrix_first);
            return 1;
        }
        if (transpose(matrix_first, n_first, m_first, &matrix_result, &n_result, &m_result)) {
            printf("n/a");
            free_me(matrix_first);
            return 1;
        }
        output(matrix_result, n_result, m_result);
        free_me(matrix_first);
        free_me(matrix_result);
    }
    return 0;
}

int input_num(int *num) {
    char c;
    if ((scanf("%d%c", num, &c) != 2) || c != '\n' || (*num > 3) || (*num < 1)) {
        return 1;
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
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (scanf("%d%c", &(matrix[i][j]), &c) != 2) {
                return 1;
            }
            if (j == w - 1) {
                if (c != '\n') return 1;
            } else {
                if (c != ' ') return 1;
            }
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
    if (matrix == NULL) return NULL;

    int *val = (int *)(matrix + h);
    for (int i = 0; i < h; i++) {
        matrix[i] = val + i * w;
    }
    return matrix;
}

void free_me(int **matrix) { free(matrix); }

int sum(int **matrix_first, int n_first, int m_first, int **matrix_second, int n_second, int m_second,
        int ***matrix_result, int *n_result, int *m_result) {
    if ((n_first != n_second) || (m_first != m_second)) {
        return 1;
    }

    *n_result = n_first;
    *m_result = m_first;
    *matrix_result = dynamic1(*n_result, *m_result);
    if (*matrix_result == NULL) return 1;

    for (int i = 0; i < *n_result; i++) {
        for (int j = 0; j < *m_result; j++) {
            (*matrix_result)[i][j] = matrix_first[i][j] + matrix_second[i][j];
        }
    }
    return 0;
}

int mul(int **matrix_first, int n_first, int m_first, int **matrix_second, int n_second, int m_second,
        int ***matrix_result, int *n_result, int *m_result) {
    if (m_first != n_second) {
        return 1;
    }

    *n_result = n_first;
    *m_result = m_second;
    *matrix_result = dynamic1(*n_result, *m_result);
    if (*matrix_result == NULL) return 1;

    for (int i = 0; i < *n_result; i++) {
        for (int j = 0; j < *m_result; j++) {
            (*matrix_result)[i][j] = 0;
            for (int k = 0; k < m_first; k++) {
                (*matrix_result)[i][j] += matrix_first[i][k] * matrix_second[k][j];
            }
        }
    }
    return 0;
}

int transpose(int **matrix, int n, int m, int ***matrix_result, int *n_result, int *m_result) {
    *n_result = m;
    *m_result = n;
    *matrix_result = dynamic1(*n_result, *m_result);
    if (*matrix_result == NULL) return 1;

    for (int i = 0; i < *n_result; i++) {
        for (int j = 0; j < *m_result; j++) {
            (*matrix_result)[i][j] = matrix[j][i];
        }
    }
    return 0;
}