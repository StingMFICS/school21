#include "polish.h"

#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

Token *convert_to_polish_notation(Token *data, int n, int *result_size) {
    Token *result = (Token *)malloc(n * sizeof(Token));
    TokenStack *operators = NULL;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (data[i].type == 1 || data[i].type == 3) {
            result[count] = data[i];
            count++;
        } else if (data[i].opertor == OPEN) {
            operators = push_token(operators, data[i]);
        } else if (data[i].opertor == CLOSE) {
            while (operators != NULL && peek_token(operators).opertor != OPEN) {
                result[count] = peek_token(operators);
                count++;
                operators = pop_token(operators);
            }
            if (operators != NULL) {
                operators = pop_token(operators);
            }
        } else {
            if (operators == NULL || peek_token(operators).priority < data[i].priority) {
                operators = push_token(operators, data[i]);
            } else {
                while (peek_token(operators).priority >= data[i].priority) {
                    result[count] = peek_token(operators);
                    operators = pop_token(operators);
                    count++;
                }
                operators = push_token(operators, data[i]);
            }
        }
    }
    while (operators != NULL) {
        result[count] = peek_token(operators);
        count++;
        operators = pop_token(operators);
    }
    *result_size = count;
    destroy_token(operators);
    return result;
}
