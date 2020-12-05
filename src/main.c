#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "snake.h"

typedef Point Dir;

void left(Dir *d) {
    if (d->x != 0)
        d->x = 0;
    else
        d->x = -1;
    if (d->y != 0)
        d->y = 0;
    else
        d->y = -1;
}

void right(Dir *d) {
    if (d->x != 0)
        d->x = 0;
    else
        d->x = 1;
    if (d->y != 0)
        d->y = 0;
    else
        d->y = 1;
}

int main() {
    Point initial[] = {{10, 10}, {10, 11}, {10, 12}};
    Snake snek = snake(initial);
    Dir d = {0, -1};

    /*initscr();*/

    while (1) {
        if (snek_move(&snek, d.y, d.x) == DIE) goto end;
    }

    end:
    /*endwin();*/
    delete_snake(&snek);
    return 0;
}
