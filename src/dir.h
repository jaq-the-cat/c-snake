#ifndef DIR_H
#define DIR_H

#include "snake.h"

typedef Point Dir;
#define UP(D) D->y == -1 && D->x == 0
#define LEFT(D) D->y == 0 && D->x == -1
#define DOWN(D) D->y == 1 && D->x == 0
#define RIGHT(D) D->y == 0 && d->x == 1

void up(Dir*);
void left(Dir*);
void down(Dir*);
void right(Dir*);

#endif
