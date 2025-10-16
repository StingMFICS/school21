#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

#include "validate.h"

// TokenStack
TokenStack* push_token(TokenStack* root, Token x) {
    TokenStack* p = (TokenStack*)malloc(sizeof(TokenStack));
    p->queue = x;
    p->next = root;
    return p;
}

TokenStack* pop_token(TokenStack* root) {
    TokenStack* temp;
    if (root == NULL) {
        temp = NULL;
    } else {
        temp = root->next;
        free(root);
    }

    return temp;
}

void destroy_token(TokenStack* root) {
    while (root != NULL) {
        TokenStack* temp = root->next;
        free(root);
        root = temp;
    }
}

Token peek_token(TokenStack* root) {
    Token empty = {0};

    return (root == NULL) ? empty : root->queue;
}

// DoubleStack
DoubleStack* push_double(DoubleStack* root, double x) {
    DoubleStack* p = (DoubleStack*)malloc(sizeof(DoubleStack));
    p->value = x;
    p->next = root;
    return p;
}

double pop_double(DoubleStack** root) {
    double popped = (*root)->value;
    DoubleStack* temp = *root;
    *root = (*root)->next;
    free(temp);

    return popped;
}

void destroy_double(DoubleStack* root) {
    while (root != NULL) {
        DoubleStack* temp = root->next;
        free(root);
        root = temp;
    }
}
