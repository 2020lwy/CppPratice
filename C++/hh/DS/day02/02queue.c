/*
 * 循环队列演示
 * */
#include "02queue.h"
//队列的初始化函数
void queue_init(queue *p_queue) {
    p_queue->head = 0;
    p_queue->tail = 0;
    p_queue->qty = 0;
}
//队列的清理函数
void queue_deinit(queue *p_queue) {
    p_queue->head = 0;
    p_queue->tail = 0;
    p_queue->qty = 0;
}
//获得有效数字个数的函数
int queue_size(const queue *p_queue) {
    return p_queue->qty;
}
//判断队列是否空的函数
int queue_empty(const queue *p_queue) {
    return !(p_queue->qty);
}
//判断队列是否满的函数
int queue_full(const queue *p_queue) {
    return p_queue->qty >= SIZE;
}
//向循环队列里加入数字的函数
int queue_push(queue *p_queue, int val) {
    if (p_queue->qty >= SIZE) {
        return 0;
    }
    p_queue->buf[p_queue->tail] = val;
    p_queue->tail++;
    p_queue->tail %= SIZE;
    p_queue->qty++;
    return 1;
}
//从队列里获得数字的函数(会从队列里删除
//数字)
int queue_pop(queue *p_queue, int *p_val) {
    if (!(p_queue->qty)) {
        return 0;
    }
    *p_val = p_queue->buf[p_queue->head];
    p_queue->head++;
    p_queue->head %= SIZE;
    p_queue->qty--;
    return 1;
}
//从队列里获得数字的函数(不会删除数字)
int queue_front(const queue *p_queue, int *p_val) {
    if (!(p_queue->qty)) {
        return 0;
    }
    *p_val = p_queue->buf[p_queue->head];
    return 1;
}







