#ifndef VALIDATE_H
#define VALIDATE_H

// тип токена
#define NUMBER 1
#define OPERATOR 2
#define X 3

// тип оператора
#define PLUS 1
#define MINUS 2
#define DIV 3
#define MUL 4
#define CLOSE 5
#define OPEN 6
#define SIN 7
#define COS 8
#define TAN 9
#define CTAN 10
#define SQRT 11
#define LN 12

typedef struct token Token;

struct token {
    int type;
    int priority;
    union {
        int opertor;
        double value;
    };
};

Token *tokenization(char *expr, int *size, int *error, int len);
Token unary(char **expr, int *error);
Token binary(char **expr, int *error);
Token num(char **expr, int *error);

#endif
