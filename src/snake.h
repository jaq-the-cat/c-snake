#ifndef SNAKE_H
#define SNAKE_H

#include <stdio.h>
#include <stdlib.h>

#define INITIAL_SIZE 3

#define DIE 0
#define NOTHING 1

typedef struct {
    int y;
    int x;
} Point;

typedef struct s_SnakeNode {
    Point data;
    struct s_SnakeNode *prev;
    struct s_SnakeNode *next;
} SnakeNode;

typedef struct {
    SnakeNode *tail;
    int len;
} Snake;

Snake snake(Point[INITIAL_SIZE]);
SnakeNode* make_node(Point);
void add_node(Snake*, Point);
int snek_move(Snake*, int, int);
void delete_snake(Snake*);
void ncurses_display(Snake*);
void debug_printf(Snake*);

#endif
