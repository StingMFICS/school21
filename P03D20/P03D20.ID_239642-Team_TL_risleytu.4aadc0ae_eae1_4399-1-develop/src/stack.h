#ifndef STACK_H
#define STACK_H

#include "validate.h"

typedef struct tokenStack TokenStack;

struct tokenStack {
    Token queue;
    TokenStack* next;
};

typedef struct doubleStack DoubleStack;

struct doubleStack {
    double value;
    DoubleStack* next;
};

TokenStack* init_token(Token x);
TokenStack* push_token(TokenStack* root, Token x);
TokenStack* pop_token(TokenStack* root);
void destroy_token(TokenStack* root);
Token peek_token(TokenStack* root);

DoubleStack* init_double(double value);
DoubleStack* push_double(DoubleStack* root, double x);
double pop_double(DoubleStack** root);
void destroy_double(DoubleStack* root);
double peek_double(DoubleStack* stack);
int isEmpty(DoubleStack* stack);

#endif
