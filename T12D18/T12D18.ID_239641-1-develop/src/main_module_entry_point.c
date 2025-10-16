#include <stdio.h>

#include "documentation_module.h"
#include "print_module.h"

int main() {
#ifdef Q1
    print_log(print_char, Module_load_success_message);
#elif Q2
    int *availability_mask = check_available_documentation_module(validate, Documents_count, Documents);

    // Output availability for each document....
    char *names[] = {Documents};
    for (int i = 0; i < Documents_count; i++) {
        printf("%-15s: ", names[i]);
        printf(availability_mask[i] ? "available\n" : "unavailable\n");
    }
    free(availability_mask);
#endif
    return 0;
}
