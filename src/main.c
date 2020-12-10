#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "snake.h"
#include "dir.h"

int main() {
    Point initial[] = {{10, 10}, {10, 11}, {10, 12}};
    Snake snek = snake(initial);
    Dir d = {0, -1};

    initscr();
    curs_set(0);
    nodelay(stdscr, 1);
    noecho();

    while (1) {
        if (snek_move(&snek, d.y, d.x) == DIE) goto end;

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

        clear();
        ncurses_display(&snek);
        refresh();

        napms(70);
    }

    end:
    echo();
    nodelay(stdscr, 0);
    curs_set(1);
    endwin();
    delete_snake(&snek);
    return 0;
}
