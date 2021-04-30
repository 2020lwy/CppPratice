/*
 * 队列演示
 * */

#include "02queue.h"
typedef struct {
    int buf[SIZE];
    int head;  //如果队列里没有数字则head应该等于tail
    int tail;  //记录下一个数字应该放置的位置
} queue;
//队列初始化函数
void queue_init(queue *p_queue) {
    p_queue->head = 0;
    p_queue->tail = 0;
}
//队列清理函数
void queue_deinit(queue *p_queue) {
    p_queue->head = 0;
    p_queue->tail = 0;
}
//获得有效数字个数的函数
int queue_size(const queue *p_queue) {
    return p_queue->tail - p_queue->head;
}
//判断队列是否空的函数
int queue_empty(const queue *p_queue) {
    return p_queue->head == p_queue->tail;
}
//判断队列是否满的函数
int queue_full(const queue *p_queue) {
    return p_queue->tail >= SIZE;
}
//向队列里加入数字的函数
int queue_push(queue *p_queue, int val) {
    if (p_queue->tail >= SIZE) {
        return 0;
    }
    p_queue->buf[p_queue->tail] = val;
    p_queue->tail++;
    return 1;
}
//从队列里获得数字的函数(会把数字从队列
//里删除)
int queue_pop(queue *p_queue, int *p_val) {
    if (p_queue->head == p_queue->tail) {
        return 0;
    }
    *p_val = p_queue->buf[p_queue->head];
    p_queue->head++;
    return 1;
}
//从队列里获得数字的函数(不会删除数字)
int queue_front(const queue *p_queue, int *p_val) {
    if (p_queue->head == p_queue->tail) {
        return 0;
    }
    *p_val = p_queue->buf[p_queue->head];
    return 1;
}







