#include <stdio.h>
#include <stdlib.h>
#include "snake.h"

int main() {
    Point initial[] = {{10, 10}, {10, 11}, {10, 12}};
    Snake snek = snake(initial);
    return 0;
}
