/*
 * 循环队列演示
 * */
#ifndef     __02QUEUE_H__
#define     __02QUEUE_H__
#define     SIZE 100
typedef struct {
    int buf[SIZE];
    int head;   //如果队列是空的或者满的head都应该等于tail
    int tail;   //记录下一个数字应该放置的位置
    int qty;    //记录有效数字个数
} queue;
//队列的初始化函数
void queue_init(queue *);
//队列的清理函数
void queue_deinit(queue *);
//获得有效数字个数的函数
int queue_size(const queue *);
//判断队列是否空的函数
int queue_empty(const queue *);
//判断队列是否满的函数
int queue_full(const queue *);
//向循环队列里加入数字的函数
int queue_push(queue *, int );
//从队列里获得数字的函数(会从队列里删除
//数字)
int queue_pop(queue *, int *);
//从队列里获得数字的函数(不会删除数字)
int queue_front(const queue *, int *);
#endif           //__02QUEUE_H__






