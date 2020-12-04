#include "snake.h"

Snake snake(Point initial[INITIAL_SIZE]) {
    Snake snek = {
        .tail = NULL,
        .len = 0,
    };
    for (int i=0; i<INITIAL_SIZE; i++)
        add_node(&snek, initial[i]);
    return snek;
}

SnakeNode* make_node(Point data) {
    SnakeNode *node = (SnakeNode*) malloc(sizeof(SnakeNode));
    node->data = data;
    node->next = NULL;
    return node;
}

void add_node(Snake *snek, Point p) {
    if (snek->len == 0) {
        snek->tail = make_node(p);
        snek->tail->next = snek->tail;
    }
    else {
        SnakeNode *head = snek->tail->next;
        snek->tail->next = make_node(p);
        snek->tail->next->next = head;
        snek->tail = snek->tail->next;
    }
    snek->len += 1;

}
