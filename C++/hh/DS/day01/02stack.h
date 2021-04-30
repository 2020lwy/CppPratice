/*
 * 栈演示
 * */
#ifndef    __02STACK_H__
#define    __02STACK_H__
#define    SIZE 10;
typedef struct {
    int buf[SIZE];
    int qty;      //栈里实际的数字个数
} stack;
//栈的初始化函数
void stack_init(stack *);
//清理栈内容的函数
void stack_deinit(stack *);
//判断栈是否满的函数
int stack_full(const stack *);
//判断栈是否空的函数
int stack_empty(const stack *);
//获得数字个数的函数
int stack_size(const stack *);
//向栈里加入数字的函数
int stack_push(stack *, int );
//从栈里获得数字的函数(同时从栈里删除数字)
int stack_pop(stack *, int *);
//获得最后一个数字的函数(不会删除数字)
int stack_top(const stack *, int *);
#endif         //__02STACK_H__






