/*
 * 二叉树演示
 * */
#include <stdlib.h>
#include "01tree.h"
//树的初始化函数
void tree_init(tree *p_tree) {
    p_tree->p_node = NULL;
}
//树的清理函数
void tree_deinit(tree *p_tree) {
    if (!(p_tree->p_node)) {
        return ;
    }
    tree_deinit(&(p_tree->p_node->left));
    tree_deinit(&(p_tree->p_node->right));
    free(p_tree->p_node);
    p_tree->p_node = NULL;
}
//在有序二叉树里查找某个数字的位置
tree *tree_search(const tree *p_tree, int val) {
    if (!(p_tree->p_node)) {
        return (tree *)p_tree;
    }
    if (p_tree->p_node->val == val) {
        return (tree *)p_tree;
    }
    else if (p_tree->p_node->val > val) {
        return tree_search(&(p_tree->p_node->left), val);
    }
    else {
        return tree_search(&(p_tree->p_node->right), val);
    }
}
//在有序二叉树里插入数字的函数
int tree_insert(tree *p_tree, int val) {
    node *p_node = NULL;
    tree *p_tmp = tree_search(p_tree, val);
    if (p_tmp->p_node) {
        return 0;
    }
    p_node = (node *)malloc(sizeof(node));
    if (!p_node) {
        return 0;
    }
    p_node->val = val;
    p_node->left.p_node = NULL;
    p_node->right.p_node = NULL;
    p_tmp->p_node = p_node;
    return 1;
}
//以中序遍历的方式依次处理有序二叉树
//里所有的节点
void tree_miter(const tree *p_tree, void (*p_func)(int)) {
    if (!(p_tree->p_node)) {
        return ;
    }
    tree_miter(&(p_tree->p_node->left), p_func);
    p_func(p_tree->p_node->val);
    tree_miter(&(p_tree->p_node->right), p_func);
}
//从有序二叉树里删除数字的函数
int tree_remove(tree *p_tree, int val) {
    node *p_node = NULL;
    tree *p_tmp = tree_search(p_tree, val);
    if (!(p_tmp->p_node)) {
        return 0;
    }
    p_node = p_tmp->p_node;
    //把要删除的节点从有序二叉树里
    //摘出来
    if (!(p_node->left.p_node) && !(p_node->right.p_node)) {
        //要删除的节点没有子节点
        p_tmp->p_node = NULL;
    }
    else if (!(p_node->right.p_node)) {
        //要删除的节点只有左子节点
        p_tmp->p_node = p_node->left.p_node;
    }
    else if (!(p_node->left.p_node)) {
        //要删除的节点只有右子节点
        p_tmp->p_node = p_node->right.p_node;
    }
    else {
        //两个子节点都在
        tree *p_tmp1 = tree_search(&(p_node->left), p_node->right.p_node->val);
        p_tmp1->p_node = p_node->right.p_node;
        p_tmp->p_node = p_node->left.p_node;
    }
    free(p_node);
    p_node = NULL;
    return 1;
}
//计算树高度的函数
int tree_height(const tree *p_tree) {
    int left_height = 0, right_height = 0;
    if (!(p_tree->p_node)) {
        return 0;
    }
    left_height = tree_height(&(p_tree->p_node->left));
    right_height = tree_height(&(p_tree->p_node->right));
    return (left_height > right_height ? left_height : right_height) + 1;
}
//统计节点个数的函数
int tree_size(const tree *p_tree) {
    int size = 0;
    if (!(p_tree->p_node)) {
        return 0;
    }
    size += tree_size(&(p_tree->p_node->left));
    size += tree_size(&(p_tree->p_node->right));
    return size + 1;
}
    








