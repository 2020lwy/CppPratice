/*
 * 队列测试
 * */
#include <stdio.h>
#include "02queue.h"
int main() {
    queue que = {0};
    queue_init(&que);
    queue_deinit(&que);
    return 0;
}
