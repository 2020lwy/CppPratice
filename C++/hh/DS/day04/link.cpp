#include <iostream>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node *p_next;
}node;

typedef struct Link{
    node head;
    node tail;
}Link;


//初始化一个链表
void link_init(Link *link){
    link->head.p_next = &(link->tail);
    link->tail.p_next = NULL;
}

//打印链表内的所有的节点的数据
void link_print(Link *link){
    std::cout << "xixi" << std::endl;
    node *p_first = NULL;
    node *p_mid   = NULL;
    node *p_last  = NULL;
    node *p_tmp   = NULL;
    for(p_tmp=&(link->head);p_tmp!=&(link->tail);p_tmp=p_tmp->p_next){
        p_first = p_tmp;
        p_mid   = p_first->p_next;
        p_last  = p_mid->p_next;
        if(p_mid!=&(link->tail)){
            std::cout << p_mid->val << " " ;
        }
    }
    std::cout << std::endl;
}

//在链表的头部插入一个数据

void add_head(Link *link,int val){
    node *p_first = NULL;
    node *p_mid   = NULL;
    node *p_last  = NULL;

    node *p_node = (node *)malloc(sizeof(node));
    if(p_node == NULL){
        std::cout << "malloc error" << std::endl;
        return ;
    }
    p_node->val = val;
    p_node->p_next = NULL;
    p_first = &(link->head);
    p_mid   = p_first->p_next;
    p_last  = p_mid->p_next;
    p_first->p_next = p_node;
    p_node->p_next  = p_mid;
}

//在链表的尾部插入一个数据

void add_tail(Link *link,int val){
    node *p_first = NULL;
    node *p_mid   = NULL;
    node *p_last  = NULL;
    node *p_tmp   = NULL;

    node *p_node = (node *)malloc(sizeof(node));
    if(p_node == NULL){
        std::cout << "malloc error" << std::endl;
        return ;
    }
    p_node->val = val;
    p_node->p_next = NULL;
    for(p_tmp=&(link->head);p_tmp!=&(link->tail);p_tmp=p_tmp->p_next){
        p_first = p_tmp;
        p_mid   = p_first->p_next;
        p_last  = p_mid->p_next;
        if(p_mid==&(link->tail)){
            // p_node = p_first->p_next ;
            // p_mid  = p_node->p_next;
            p_first->p_next = p_node;
            p_node->p_next  = p_mid;
        }
    }
}

//删除链表的头部的第一个数据

void del_head(Link *link){
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

//删除链表尾部的最后的一个数据

void del_tail(Link *link){
    node *p_first = NULL;
    node *p_mid   = NULL;
    node *p_last  = NULL;
    node *p_tmp   = NULL;

    for(p_tmp=&(link->head);p_tmp!=&(link->tail);p_tmp=p_tmp->p_next){
        p_first = p_tmp;
        p_mid   = p_first->p_next;
        p_last  = p_mid->p_next;
        if(p_last==&(link->tail)){
            free(p_mid);
            p_mid = NULL;
            p_first->p_next = p_last;
        }
    }
}


//将整个链表的数据做一个逆序排列
void change(Link *link){
    node *head = &(link->head);
    node *p = NULL;
    p = head->p_next;
    head->p_next = NULL;
    while(p!=NULL){
        node *r = p->p_next;
        p->p_next = head->p_next;
        head->p_next = p;
        p = r;
    }
}

void change2(Link *link){
    node *head = &(link->head);
    node *p = NULL;
    p = head->p_next;
    head->p_next = NULL;

    node *p_first = NULL;
    node *p_mid   = NULL;
    node *p_last  = NULL;
    node *p_tmp   = NULL;

    for(p_tmp=&(link->head);p_tmp!=&(link->tail);p_tmp=p_tmp->p_next){
        p_first = p_tmp;
        p_mid   = p_first->p_next;
        p_last  = p_mid->p_next;
        if(p_last==&(link->tail)){
            free(p_mid);
            p_mid = NULL;
            p_first->p_next = p_last;
        }
    }
}


// Status ListReverse(LinkList L){
//     LinkList current,pnext,prev;
//     if(L == NULL || L->next == NULL)
//         return L;
//     current = L->next;  /* p1指向链表头节点的下一个节点 */
//     pnext = current->next;
//     current->next = NULL;
//     while(pnext){
//         prev = pnext->next;
//         pnext->next = current;
//         current = pnext;
//         pnext = prev;
//     }
//     //printf("current = %d,next = %d \n",current->data,current->next->data);
//     L->next = current;  /* 将链表头节点指向p1 */
//     return L;
// }


// int  ListReverse2(Link* L){
//     Link * current, p;
//     if (L == NULL){
//         return NULL;
//     }
//     current = L->next;
//     while (current->next != NULL){
//         p = current->next;
//         current->next = p->next;
//         p->next = L->next;
//         L->next = p;
//     }
//     return L;
// }



int main(void){

    Link link;
    link_init(&link);
    add_head(&link,20);
    add_head(&link,70);
    // add_head(&link,90);
    // add_head(&link,200);
    // add_head(&link,120);
    // add_tail(&link,99);
    // del_head(&link);
    // del_tail(&link);
    // remove_head(&link);
    link_print(&link);

    change(&link);
    link_print(&link);

    return 0;
}