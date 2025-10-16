#include "list.h"

#include <stdio.h>

int main() {
    struct door door1 = {1, 0};
    struct door door2 = {2, 1};
    struct node *first = init(&door1);

    struct node *second = add_door(first, &door2);
    printf(
        "door1 = {1, 0}\ndoor2 = {2, 1}\nstruct node *first = init(&door1) ---> struct node *second = "
        "add_door(first, &door2)\n*(first).next = second и second.id = 2");
    if ((*first).next == second && (*(*second).door).id == 2) {
        printf("\nSUCCEES");
    } else {
        printf("\nFAIL");
    }
}
