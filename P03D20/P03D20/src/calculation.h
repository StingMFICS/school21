#ifndef COUNT_POLISH_NOTATION_H
#define COUNT_POLISH_NOTATION_H

#include <math.h>

#include "validate.h"

#define MAP_HEIGHT 25
#define MAP_WIDTH 80

#define GRAPH_HEIGHT_MIN -1
#define GRAPH_HEIGHT_MAX 1
#define GRAPH_WIDTH_MIN 0
#define GRAPH_WIDTH_MAX 4 * M_PI

void calculate(char **matrix, Token *tokens, int len, int *error);
double calculate_y(const Token *tokens, int *error, int len, double x);

double calculate_one_number(int *error, int operator, double operand);
double calculate_two_numbers(int *error, int operator, double first_operand, double second_operand);

int map_graph_x_to_matrix(double x);
int map_graph_y_to_matrix(double y);

#endif
