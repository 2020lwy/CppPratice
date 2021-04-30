/*
 * 链式物理结构演示
 * */
#include <stdio.h>
typedef struct node {
    int num;
    struct node *p_next;
} node;
int main() {
    node val1 = {10}, val2 = {20}, val3 = {30}, head = {0}, tail = {0};
    node *p_node = NULL;
    head.p_next = &val1;
    val1.p_next = &val2;
    val2.p_next = &val3;
    val3.p_next = &tail;
    /*
     * 依次处理线性链式物理结构中
     * 每个节点的循环
     * 指针循环变量p_node从头节点开始
     * 从前向后依次指向线性链式物理结构
     * 中的每个节点，最后一个指向的
     * 节点是最后有效节点
     * */
    for (p_node = &head;p_node != &tail;p_node = p_node->p_next) {
        node *p_first = p_node;
        node *p_mid = p_first->p_next;  //从第一个有效节点一直变到尾节点
        node *p_last = p_mid->p_next;
        if (p_mid != &tail) {
            printf("%d ", p_mid->num);
        }
    }
    printf("\n");
    return 0;
}







