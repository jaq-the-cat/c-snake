#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "snake.h"

typedef Point Dir;
#define UP(D) D->y == -1 && D->x == 0
#define LEFT(D) D->y == 0 && D->x == -1
#define DOWN(D) D->y == 1 && D->x == 0
#define RIGHT(D) D->y == 0 && d->x == 1

void up(Dir *d) {
    if (RIGHT(d) || LEFT(d)) {
        d->y = 1;
        d->x = 0;
    } else if (RIGHT(d)) {
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

int main() {
    Point initial[] = {{10, 10}, {10, 11}, {10, 12}};
    Snake snek = snake(initial);
    Dir d = {0, -1};

    initscr();
    curs_set(0);
    nodelay(stdscr, 1);
    noecho();

    while (1) {
        clear();
        if (snek_move(&snek, d.y, d.x) == DIE) goto end;
        ncurses_display(&snek);
        refresh();
        switch (getch()) {
            case 'w':
                up(&d);
                break;
            case 'a':
                left(&d);
                break;
            case 's':
                down(&d);
                break;
            case 'd':
                right(&d);
                break;
            case 'q':
                goto end;
        }
        napms(100);
    }

    end:
    echo();
    nodelay(stdscr, 0);
    curs_set(1);
    endwin();
    delete_snake(&snek);
    return 0;
}
