#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void initialize_doors(struct door *doors);
void sort(struct door *doors);
void close_doors(struct door *doors);
void output(struct door *doors);

int main() {
    struct door doors[DOORS_COUNT];

    initialize_doors(doors);
    sort(doors);
    close_doors(doors);
    output(doors);

    return 0;
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(struct door *doors) {
    srand(time(0));

    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}

void sort(struct door *doors) {
    for (int i = 0; i < DOORS_COUNT; i++) {
        for (int j = 0; j < DOORS_COUNT - 1; j++) {
            if (doors[j].id > doors[j + 1].id) {
                struct door tmp = doors[j];
                doors[j] = doors[j + 1];
                doors[j + 1] = tmp;
            }
        }
    }
}

void close_doors(struct door *doors) {
    for (int j = 0; j < DOORS_COUNT; j++) {
        if (doors[j].status == 1) {
            doors[j].status = 0;
        }
    }
}

void output(struct door *doors) {
    for (int j = 0; j < DOORS_COUNT; j++) {
        printf("%d, %d", doors[j].id, doors[j].status);
        if (j != DOORS_COUNT - 1) {
            printf("\n");
        }
    }
}
