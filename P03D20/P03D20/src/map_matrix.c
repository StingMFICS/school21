#include "map_matrix.h"

#include <stdio.h>
#include <stdlib.h>

#include "calculation.h"

char **allocate_matrix(int *error) {
    char **matrix = (char **)calloc(MAP_HEIGHT, sizeof(char *));

    if (matrix != NULL) {
        for (int y = 0; y < MAP_HEIGHT; y++) {
            char *new_line = (char *)calloc(MAP_WIDTH, sizeof(char));

            if (!(*error) && new_line != NULL)
                matrix[y] = new_line;
            else
                *error = 1;

            for (int x = 0; x < MAP_WIDTH; x++) {
                matrix[y][x] = '.';
            }
        }
    } else {
        *error = 1;
    }

    if (*error) matrix = NULL;

    return matrix;
}

void plot_graph(char **matrix) {
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            printf("%c", matrix[y][x]);
        }
        printf("\n");
    }
}

void free_matrix(char ***matrix) {
    for (int y = 0; y < MAP_HEIGHT; y++) {
        free((*matrix)[y]);
    }

    free(*matrix);
}
