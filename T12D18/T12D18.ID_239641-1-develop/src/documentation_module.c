#include "documentation_module.h"

int validate(char* data) {
    int validation_result = !strcmp(data, Available_document);
    return validation_result;
}

int* check_available_documentation_module(int (*validate)(char*), int document_count, ...) {
    va_list args;
    va_start(args, document_count);
    int* res = malloc(sizeof(int) * document_count);
    for (int i = 0; i < document_count; i++) {
        char* arg = va_arg(args, char*);
        res[i] = validate(arg);
    }
    va_end(args);
    return res;
}
