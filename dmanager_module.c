#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void initialize_doors(struct door* doors);
void SortDoors(struct door* doors);
void CloseDoors(struct door* doors);
void OutputDoors(struct door* doors);

int main() {
    struct door doors[DOORS_COUNT];

    initialize_doors(doors);
    SortDoors(doors);
    CloseDoors(doors);
    OutputDoors(doors);

    return 0;
}

void SortDoors(struct door* doors) {
    for (int i = 0; i < DOORS_COUNT - 1; i++) {
        for (int j = 0; j < DOORS_COUNT - 1; j++) {
            if (doors[j].id > doors[j + 1].id) {
                struct door temp = doors[j + 1];
                doors[j + 1] = doors[j];
                doors[j] = temp;
            }
        }
    }
}

void CloseDoors(struct door* doors) {
    for (size_t i = 0; i < DOORS_COUNT; i++) doors[i].status = 0;
}

void OutputDoors(struct door* doors) {
    for (size_t i = 0; i < DOORS_COUNT; i++) {
        if (i == DOORS_COUNT - 1)
            printf("%d, %d", doors[i].id, doors[i].status);
        else
            printf("%d, %d\n", doors[i].id, doors[i].status);
    }
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(struct door* doors) {
    srand(time(0));

    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}
