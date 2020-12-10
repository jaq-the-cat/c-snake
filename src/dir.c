#include "dir.h"

void up(Dir *d) {
    if (RIGHT(d) || LEFT(d)) {
        d->y = -1;
        d->x = 0;
    }
}

void left(Dir *d) {
    if (UP(d) || DOWN(d)) {
        d->y = 0;
        d->x = -1;
    }
}

void down(Dir *d) {
    if (RIGHT(d) || LEFT(d)) {
        d->y = 1;
        d->x = 0;
    }
}

void right(Dir *d) {
    if (UP(d) || DOWN(d)) {
        d->y = 0;
        d->x = 1;
    }
}

