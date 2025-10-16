#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "calculation.h"
#include "get.h"
#include "map_matrix.h"
#include "polish.h"
#include "validate.h"

int main() {
    print_start_message();
    int error = 0, len = 0, token_size = 0;
    char *expression = input(&error, &len);

    if (!error) {
        Token *infix_tokens = tokenization(expression, &token_size, &error, len);

        if (!error) {
            int result_size;
            Token *polish_tokens = convert_to_polish_notation(infix_tokens, token_size, &result_size);
            char **matrix = allocate_matrix(&error);
            if (!error) {
                calculate(matrix, polish_tokens, result_size, &error);
                if (!error) {
                    plot_graph(matrix);
                }
            }
            free_matrix(&matrix);
            free(polish_tokens);
        }
        free(infix_tokens);
    }

    if (error) {
        printf("n/a");
    }

    free(expression);
    return error;
}
