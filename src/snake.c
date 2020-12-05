#include "snake.h"

Snake snake(Point initial[INITIAL_SIZE]) {
    Snake snek = {
        .tail = NULL,
        .len = 0,
    };
    for (int i=0; i<INITIAL_SIZE; i++) {
        add_node(&snek, initial[i]);
    }
    return snek;
}

SnakeNode* make_node(Point data) {
    SnakeNode *node = (SnakeNode*) malloc(sizeof(SnakeNode));
    node->prev = NULL;
    node->next = NULL;
    node->data = data;
    return node;
}

void add_node(Snake *snek, Point p) {
    if (snek->len == 0) {
        snek->tail = make_node(p);
        snek->tail->prev = snek->tail;
        snek->tail->next = snek->tail;
    }
    else {
        SnakeNode *head = snek->tail->next;
        snek->tail->next = make_node(p);
        snek->tail->next->prev = snek->tail;
        snek->tail->next->next = head;
        snek->tail = snek->tail->next;

    }
    snek->len += 1;
}

int move(Snake *snek, int x, int y) {
    SnakeNode *head = snek->tail->next;
    head->data = (Point) { head->data. y+ y, head->data.x + x };
    SnakeNode *node = snek->tail;
    for (; node != snek->tail->next; node = node->prev) {
        if (node->data.x == head->data.x && node->data.y == head->data.y)
            return DIE;
        node->data = node->prev->data;
    }
    return NOTHING;
}

void _delete_node(Snake *snek, SnakeNode *node) {
    if (node->next != snek->tail)
        _delete_node(snek, node->next);
    node->next = NULL;
    free(node);
}

void delete_snake(Snake *snek) {
    _delete_node(snek, snek->tail);
    snek->len = 0;
}

void debug_printf(Snake *snek) {
    if (snek->len > 0) {
        SnakeNode *node = snek->tail->next;
        printf("{ ");
        do {
            printf("(%d, %d) <-> ", node->data.y, node->data.x);
            node = node->next;
        } while (node != snek->tail->next);
        printf("[%d, %d]  }\n", snek->tail->next->data.y,
                snek->tail->next->data.x);
    } else {
        printf("{}\n");
    }

}
