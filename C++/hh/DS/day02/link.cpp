#include <iostream>

typedef struct node{
    int val;
    struct node* p_next;
}node;

typedef struct Link{
    node head;
    node tail;
}Link;

//链表的初始化

void init_link(Link *link){

    link->head.p_next = &(link->tail);
    link->tail.p_next = NULL;
}

//打印链表上的节点

void print_link(Link * link){
    node *p_tmp = NULL;
    node *p_first = NULL;
    node *p_mid   = NULL;
    node *p_last  = NULL;
    for(p_tmp=&(link->head);p_tmp!=&(link->tail);p_tmp=p_tmp->p_next){
        p_first = p_tmp;
        p_mid   = p_first->p_next;
        p_last  = p_mid->p_next;
        if(p_mid!=&(link->tail)){
            std::cout << p_mid->val << " ";
        }
    }
    std::cout << " " << std::endl;
}

//在链表的头部加入节点
int  add_head(Link *link,int val){
    node *p_first = NULL;
    node *p_mid   = NULL;
    node *p_last  = NULL;
    node *p_node = (node *)malloc(sizeof(node));
    if(p_node == NULL){
        return 0;
    }
    p_node->val = val;
    p_node->p_next = NULL;
    p_first = &(link->head);
    p_mid   = p_first->p_next;
    p_last  = p_mid->p_next;
    p_first->p_next = p_node;
    p_node->p_next = p_mid;
}

//删除链表的第一个节点
int remove_head(Link *link){
    node *p_first = NULL;
    node *p_mid   = NULL;
    node *p_last  = NULL;
    p_first = &(link->head);
    p_mid   = p_first->p_next;
    p_last  = p_mid->p_next;
    if(p_mid!=&(link->tail)){
        free(p_mid);
        p_mid = NULL;
        p_first->p_next = p_last;
    }
}

//添加一个节点到链表的尾部

int add_tail(Link *link,int val){
    node *p_tmp = NULL;
    node *p_first = NULL;
    node *p_mid   = NULL;
    node *p_last  = NULL;
    node *p_node = (node *)malloc(sizeof(node));
    if(p_node == NULL)
        return 0;
    p_node->p_next = NULL;
    p_node->val    = val;

    for(p_tmp=&(link->head);p_tmp!=&(link->tail);p_tmp=p_tmp->p_next){
        p_first = p_tmp;
        p_mid   = p_first->p_next;
        p_last  = p_mid->p_next;
        if(p_mid==&(link->tail)){
            p_first->p_next = p_node;
            p_node->p_next = p_mid;
        }
    }
}

//删除链表的最后一个节点
int remove_tail(Link *link){
    node *p_tmp = NULL;
    node *p_first = NULL;
    node *p_mid   = NULL;
    node *p_last  = NULL;
    for(p_tmp=&(link->head);p_tmp!=&(link->tail);p_tmp=p_tmp->p_next){
        p_first = p_tmp;
        p_mid   = p_first->p_next;
        p_last  = p_mid->p_next;
        if(p_last==&(link->tail)){
            free(p_mid);
            p_mid= NULL;
            p_first->p_next = p_last;
        }
    }
}


int main(void){

    Link link;
    init_link(&link);
    add_head(&link,200);
    add_head(&link,400);
    add_tail(&link,700);
    add_tail(&link,701);
    print_link(&link);

    remove_head(&link);
    print_link(&link);

    remove_tail(&link);
    print_link(&link);
    return 0;
}