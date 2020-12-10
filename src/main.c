#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "snake.h"
#include "dir.h"

Point make_food(int maxx, int maxy) {
    return (Point) {rand() % maxy, rand() % (maxx/2)*2};
}

int main() {
    Point initial[] = {{10, 10}, {10, 11}, {10, 12}};
    Snake snek = snake(initial);
    Dir d = {0, -1};

    initscr();
    curs_set(0);
    nodelay(stdscr, 1);
    noecho();

    Point f = make_food(getmaxx(stdscr), getmaxy(stdscr));

    while (1) {
        int eat = is_eat(&snek.tail->next->data, f);
        switch (snek_move(&snek, d.y, d.x, eat)) {
            case DIE:
                goto end;
            default:
                break;
        };
        if (eat) f = make_food(getmaxx(stdscr), getmaxy(stdscr));

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
        char buf[128];
        sprintf(buf, "%d", f.y);
        mvaddstr(0, 0, buf);
        sprintf(buf, "%d", f.x);
        mvaddstr(1, 0, buf);
        sprintf(buf, "%d", snek.tail->next->data.x);
        mvaddstr(2, 0, buf);
        mvaddstr(f.y, f.x, "##");
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
