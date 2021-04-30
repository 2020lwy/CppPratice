/*
 * 二叉树演示
 * */
#ifndef         __02TREE_H__
#define         __02TREE_H__
struct node;
typedef struct {
    struct node *p_node;
} tree;
typedef struct node {
    int val;
    tree left;
    tree right;
} node;
//树的初始化函数
void tree_init(tree *);
//树的清理函数
void tree_deinit(tree *);
//在有序二叉树里插入数字的函数
int tree_insert(tree *, int );
//以中序遍历的方式依次处理有序二叉树
//里所有的节点
void tree_miter(const tree *, void (*)(int));
int tree_remove(tree *, int);
int tree_height(const tree *);
int tree_size(const tree *);
#endif         //__02TREE_H__










