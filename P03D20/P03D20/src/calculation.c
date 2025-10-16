#include "calculation.h"

#include <stdio.h>

#include "stack.h"
#include "validate.h"

void calculate(char **matrix, Token *tokens, int len, int *error) {
    double step = GRAPH_WIDTH_MAX / MAP_WIDTH;

    for (double x = GRAPH_WIDTH_MIN; x < GRAPH_WIDTH_MAX; x += step) {
        double y = calculate_y(tokens, error, len, x);

        if (!(*error)) {
            int matrix_x = map_graph_x_to_matrix(x);
            int matrix_y = map_graph_y_to_matrix(y);
            if (matrix_y >= 0 && matrix_y < MAP_HEIGHT && matrix_x >= 0 && matrix_x < MAP_WIDTH) {
                matrix[matrix_y][matrix_x] = '*';
            }
        }
    }
}

double calculate_y(const Token *tokens, int *error, int len, double x) {
    DoubleStack *operands = NULL;
    for (int count = 0; count < len && (!(*error)); count++) {
        Token token = tokens[count];
        if (token.type == NUMBER) {
            operands = push_double(operands, token.value);
        } else if (token.type == OPERATOR) {
            int operator= token.opertor;
            double result;
            if (operator<= MUL) {
                if (operands == NULL || operands->next == NULL) {
                    *error = 15;
                } else {
                    double second_operand = pop_double(&operands), first_operand = pop_double(&operands);
                    result = calculate_two_numbers(error, operator, first_operand, second_operand);
                }
            } else {
                if (operands == NULL) {
                    *error = 16;
                } else {
                    double operand = pop_double(&operands);
                    result = calculate_one_number(error, operator, operand);
                }
            }
            if (!(*error)) operands = push_double(operands, result);
        } else {
            operands = push_double(operands, x);
        }
    }
    double result_value = 0;
    if (operands == NULL) {
        *error = 17;
    } else {
        result_value = pop_double(&operands);
        if (!(*error) && operands != NULL) {
            *error = 18;
            destroy_double(operands);
        }
    }
    return result_value;
}

double calculate_one_number(int *error, int operator, double operand) {
    double result = 0;

    if (operator== SIN) {
        result = sin(operand);
    } else if (operator== COS) {
        result = cos(operand);
    } else if (operator== TAN) {
        if (cos(operand)) {
            result = tan(operand);
        } else {
            *error = 11;
        }
    } else if (operator== CTAN) {
        if (sin(operand)) {
            result = cos(operand) / sin(operand);
        } else {
            *error = 12;
        }
    } else if (operator== SQRT) {
        result = sqrt(operand);
    } else if (operator== LN) {
        if (operand > 0) {
            result = log(operand);
        } else {
            *error = 13;
        }
    }

    return result;
}

double calculate_two_numbers(int *error, int operator, double first_operand, double second_operand) {
    double result = 0;

    if (operator== PLUS) {
        result = first_operand + second_operand;
    } else if (operator== MINUS) {
        result = first_operand - second_operand;
    } else if (operator== DIV) {
        if (second_operand == 0) {
            *error = 14;
        } else {
            result = first_operand / second_operand;
        }
    } else if (operator== MUL) {
        result = first_operand * second_operand;
    }

    return result;
}

int map_graph_x_to_matrix(double x) { return (int)round(x * 80 / 4 / M_PI); }

int map_graph_y_to_matrix(double y) { return (int)round((1 - y) / 2 * 25); }
