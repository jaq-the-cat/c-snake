#ifndef SNAKE_H
#define SNAKE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int y;
    int x;
} Point;

typedef struct {
    Point *tail;
    int len;
} Snake;

Snake snake() {
    Snake snek = {
        .tail = NULL,
        .len = 0,
    };
    return snek;
}

#endif
