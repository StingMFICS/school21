#ifndef POLISH_H
#define POLISH_H

#include "stack.h"
#include "validate.h"

Token *convert_to_polish_notation(Token *data, int n, int *result_size);
Token peek(TokenStack *root);

#endif
