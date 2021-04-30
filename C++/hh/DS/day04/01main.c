/*
 * 树测试
 * */
#include <stdio.h>
#include "01tree.h"
void print_cb(int val) {
    printf("%d ", val);
}
int main() {
    tree tr = {0};
    tree_init(&tr);
    tree_insert(&tr, 50);
    tree_insert(&tr, 25);
    tree_insert(&tr, 75);
    tree_insert(&tr, 13);
    tree_insert(&tr, 37);
    tree_insert(&tr, 67);
    tree_insert(&tr, 89);
    tree_insert(&tr, 7);
    tree_miter(&tr, print_cb);
    printf("\n");
    printf("树的高度是%d\n", tree_height(&tr));
    printf("节点个数是%d\n", tree_size(&tr));
    tree_remove(&tr, 25);
    printf("树的高度是%d\n", tree_height(&tr));
    printf("节点个数是%d\n", tree_size(&tr));
    tree_miter(&tr, print_cb);
    printf("\n");
    tree_deinit(&tr);
    return 0;
}





