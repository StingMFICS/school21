#include "validate.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "get.h"

Token *tokenization(char *expr, int *size_token, int *error, int len) {
    Token *res = (Token *)malloc(len * sizeof(Token));
    *error = (res == NULL) ? 1 : 0;
    int next_operator = 1, balance = 0;
    char prev_char = '\0';
    while (*expr != '\0' && !(*error)) {
        if (*expr == ' ') {
        } else if (*expr == '(') {
            Token new = {.type = OPERATOR, .opertor = OPEN, .priority = 0};
            res[(*size_token)++] = new;
            balance++;
        } else if (*expr == ')') {
            Token new = {.type = OPERATOR, .opertor = CLOSE, .priority = 0};
            res[(*size_token)++] = new;
            balance--;
        } else if (*expr == 'x') {
            Token new = {.type = X};
            res[(*size_token)++] = new;
            next_operator--;
        } else if (*expr >= '0' && *expr <= '9') {
            res[(*size_token)++] = num(&expr, error);
            next_operator--;
        } else if (*expr == '-' && (prev_char == '(' || prev_char == '\0')) {
            Token new = {.type = OPERATOR, .opertor = MINUS, .priority = 1};
            res[(*size_token)++] = new;
        } else if (next_operator == 1 && *expr != '-') {
            res[(*size_token)++] = unary(&expr, error);
        } else if (next_operator == 0 && (*expr == '+' || *expr == '-' || *expr == '*' || *expr == '/')) {
            res[(*size_token)++] = binary(&expr, error);
            next_operator++;
        }
        if (balance < 0) {
            *error = 2;
        }
        prev_char = *expr;
        expr++;
    }
    *error = (balance != 0 || next_operator != 0) ? 3 : 0;
    return res;
}

Token num(char **expr, int *error) {
    int dot = 0;
    char *num_start = *expr;
    char *res_num = NULL;
    Token new = {.type = NUMBER, .value = 0};
    while ((*num_start >= '0' && *num_start <= '9') || *num_start == '.') {
        if (*num_start == '.') {
            dot++;
        }
        num_start++;
    }
    if (dot > 1 || *(num_start - 1) == '.') {
        *error = 4;
    }
    if (!(*error)) {
        int len = num_start - *expr;
        res_num = malloc((len + 1) * sizeof(char));
        strncpy(res_num, *expr, len);
        res_num[len] = '\0';
        new.value = atof(res_num);
        free(res_num);
        *expr = num_start - 1;
    }
    return new;
}

Token unary(char **expr, int *error) {
    Token new = {.type = OPERATOR, .priority = 3};

    if (**expr == 's') {
        if (strncmp(*expr, "sin(", 4) == 0) {
            new.opertor = SIN;
            *expr += 2;
        } else if (strncmp(*expr, "sqrt(", 5) == 0) {
            new.opertor = SQRT;
            *expr += 3;
        } else {
            *error = 5;
        }
    } else if (**expr == 'c') {
        if (strncmp(*expr, "cos(", 4) == 0) {
            new.opertor = COS;
            *expr += 2;
        } else if (strncmp(*expr, "ctg(", 4) == 0) {
            new.opertor = CTAN;
            *expr += 2;
        } else {
            *error = 6;
        }
    } else if (strncmp(*expr, "ln(", 3) == 0) {
        new.opertor = LN;
        *expr += 1;
    } else if (strncmp(*expr, "tan(", 4) == 0) {
        new.opertor = TAN;
        *expr += 2;
    } else {
        *error = 7;
    }
    return new;
}

Token binary(char **expr, int *error) {
    Token new = {.type = OPERATOR};
    if (**expr == '-') {
        new.opertor = MINUS;
        new.priority = 1;
    } else if (**expr == '+') {
        new.opertor = PLUS;
        new.priority = 1;
    } else if (**expr == '*') {
        new.opertor = MUL;
        new.priority = 2;
    } else if (**expr == '/') {
        new.opertor = DIV;
        new.priority = 2;
    } else {
        *error = 8;
    }
    return new;
}
