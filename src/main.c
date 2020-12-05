#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "snake.h"

typedef Point Dir;
#define UP(D) D->y == -1 && D->x == 0
#define DOWN(D) D->y == 1 && D->x == 0
#define LEFT(D) D->y == 0 && D->x == -1
#define RIGHT(D) D->y == 0 && d->x == 1

void left(Dir *d) {
    if (UP(d)) {
        d->x = -1;
        d->y = 0;
    } else if (DOWN(d)) {
        d->x = 1;
        d->y = 0;
    } else if (LEFT(d)) {
        d->x = 0;
        d->y = 1;
    } else if (RIGHT(d)) {
        d->x = 0;
        d->y = -1;
    }
}

void right(Dir *d) {
    if (UP(d)) {
        d->y = 0;
        d->x = 1;
    } else if (DOWN(d)) {
        d->y = 0;
        d->x = -1;
    } else if (LEFT(d)) {
        d->y = -1;
        d->x = 0;
    } else if (RIGHT(d)) {
        d->y = 1;
        d->x = 0;
    }
}

int main() {
    Point initial[] = {{10, 10}, {10, 11}, {10, 12}};
    Snake snek = snake(initial);
    Dir d = {0, -1};

    initscr();

    while (1) {
        clear();
        if (snek_move(&snek, d.y, d.x) == DIE) goto end;
        ncurses_display(&snek);
        refresh();
        right(&d);
        napms(300);
    }

    end:
    endwin();
    delete_snake(&snek);
    return 0;
}
