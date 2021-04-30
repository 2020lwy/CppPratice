#include <iostream>

typedef struct node{
    int val;
    struct node *p_next;
}node;

typedef struct List{
    node head;
    node tail;
}List;

//初始化一个链表
void init_link(List *list){
    list->head.p_next = &(list->tail);
    list->tail.p_next = NULL;
}

//在链表的头部加入一个节点
void add_head(List *list,int val){
    node *p_first = NULL;
    node *p_mid   = NULL;
    node *p_last  = NULL;
    node *p_node = (node *)malloc(sizeof(node));
    if(p_node == NULL){
        std::cout << "malloc error" << std::endl;
    }
    p_node->val = val;
    p_node->p_next = NULL;
    p_first  = &(list->head);
    p_mid    = p_first->p_next;
    p_last   = p_mid->p_next;
    p_first->p_next = p_node;
    p_node->p_next  = p_mid;
}

//在链表的尾部加入一个节点
void add_tail(List *list,int val){
    node *p_first = NULL;
    node *p_mid = NULL;
    node *p_last = NULL;
    node *p_tmp = NULL;
    node *p_node = (node *)malloc(sizeof(node));
    if(p_node==NULL)
        std::cout << "malloc error" << std::endl;
    p_node->p_next = NULL;
    p_node->val = val;
    for(p_tmp=&(list->head);p_tmp!=&(list->tail);p_tmp=p_tmp->p_next){
        p_first = p_tmp;
        p_mid   = p_first->p_next;
        p_last  = p_mid->p_next;
        if(p_mid==&(list->tail)){
            p_first->p_next = p_node;
            p_node->p_next = p_mid;
        }
    }
}

//删除链表的头部的节点
void remov_head(List *list){
    node *p_first = NULL;
    node *p_mid   = NULL;
    node *p_last  = NULL;
    p_first = &(list->head);
    p_mid   = p_first->p_next;
    p_last  = p_mid->p_next;
    if(p_mid!=&(list->tail)){
        free(p_mid);
        p_mid = NULL;
        p_last = p_first->p_next;
        p_first->p_next = p_last;
    }
}

//删除尾部节点
void remov_tail(List *list){
    node *p_first = NULL;
    node *p_mid   = NULL;
    node *p_last  = NULL;
    node *p_tmp   = NULL;
    for(p_tmp=&(list->head);p_tmp!=&(list->tail);p_tmp=p_tmp->p_next){
        p_first = p_tmp;
        p_mid   = p_first->p_next;
        p_last  = p_mid->p_next;
        if(p_last==&(list->tail)){
            free(p_mid);
            p_mid = NULL;
            p_first->p_next = p_last;
            p_last = p_first->p_next;
        }
    }
}

//打印链表的各个节点数据
void print(List *list){
    node *p_first = NULL;
    node *p_mid   = NULL;
    node *p_last  = NULL;
    node *p_tmp   = NULL;
    for(p_tmp=&(list->head);p_tmp!=&(list->tail);p_tmp=p_tmp->p_next){
        p_first = p_tmp;
        p_mid   = p_first->p_next;
        p_last  = p_mid->p_next;
        if(p_mid!=&(list->tail)){
            std::cout << p_mid->val << "  " ;
        }
    }
    std::cout << " "  <<  std::endl;
}

int main(void){

    List list;
    init_link(&list);
    add_head(&list,10);
    add_head(&list,20);
    add_head(&list,50);
    add_tail(&list,90);
    print(&list);
    return 0;
}