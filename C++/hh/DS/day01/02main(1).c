/*
 * 栈测试
 * */
#include <stdio.h>
#include "02stack.h"
int main() {
    int val = 0;
    stack stk = {0};
    stack_init(&stk);
    printf("判断空的结果是%d\n", stack_empty(&stk));
    printf("判断满的结果是%d\n", stack_full(&stk));
    printf("数字个数是%d\n", stack_size(&stk));
    stack_push(&stk, 10);
    stack_push(&stk, 20);
    stack_push(&stk, 30);
    printf("判断空的结果是%d\n", stack_empty(&stk));
    printf("判断满的结果是%d\n", stack_full(&stk));
    printf("数字个数是%d\n", stack_size(&stk));
    stack_top(&stk, &val);
    printf("最后一个数字是%d\n", val);
    stack_pop(&stk, &val);
    printf("%d ", val);
    stack_pop(&stk, &val);
    printf("%d ", val);
    stack_pop(&stk, &val);
    printf("%d\n", val);
    printf("判断空的结果是%d\n", stack_empty(&stk));
    printf("判断满的结果是%d\n", stack_full(&stk));
    printf("数字个数是%d\n", stack_size(&stk));
    stack_deinit(&stk);
    return 0;
}









