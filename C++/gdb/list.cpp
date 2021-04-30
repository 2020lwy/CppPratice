#include <iostream>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node *next;
}Node,*LinkList;

//初始化一个链表  单链表

LinkList init(){
    LinkList head = (LinkList)malloc(sizeof(Node));
    if(head == nullptr)
        std::cout << "malloc error" << std::endl;
    
    head->next = nullptr;
}

//打印链表

void print(LinkList L){
    LinkList head = L->next;
    while(head != nullptr){
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << " " << std::endl;
}

void insert_head(LinkList L,int val){
    LinkList p_node = (LinkList)malloc(sizeof(Node));
    p_node->next = nullptr;
    p_node->val  = val;

    LinkList head = L->next;

    if(head == nullptr){
        L->next = p_node;
        p_node->next = nullptr;
    }
    else
    {
        p_node->next = L->next;
        L->next = p_node;
    }
    
}

//反转一个链表

void nixu(LinkList L){
    LinkList start = L->next;
    LinkList end = start->next;
    while(end!=nullptr)
    {
        start->next = end->next;

        end->next = L->next;
        L->next = end;

        end = start->next;
    }
    
}


int main(void){
    LinkList head = init();
    insert_head(head,100);
    insert_head(head,101);
    insert_head(head,102);
    insert_head(head,103);
    print(head);

    nixu(head);
    print(head);
    return 0;
}