#include "list.h"

#include <stdio.h>
#include <stdlib.h>

struct node* init(struct door* door) {
    struct node* new = malloc(sizeof(struct node));
    if (new) {
        (*new).door = door;
        (*new).next = NULL;
    }
    return new;
}

struct node* add_door(struct node* elem, struct door* door) {
    struct node* new = door != NULL ? init(door) : NULL;
    if (elem && new) {
        struct node* tmp = (*elem).next;
        (*elem).next = new;
        (*new).next = tmp;
    }
    return new;
}

struct node* find_door(int door_id, struct node* root) {
    struct node* cur = root;
    while (cur != NULL && (*(*cur).door).id != door_id) {
        cur = (*cur).next;
    }
    return cur;
}

void destroy(struct node* root) {
    while (root != NULL) {
        struct node* tmp = root;
        root = (*root).next;
        free(tmp);
    }
}