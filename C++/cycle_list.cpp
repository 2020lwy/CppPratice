#include <iostream>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node *next;
    
}Node;
typedef struct Node* LinkList;

//初始化一个循环链表
LinkList init(){
    LinkList head = (LinkList)malloc(sizeof(Node));
    head->next = NULL;
    return head;

}

//打印循环链表中的数据
void print(LinkList L){
    LinkList head = L->next;
    while(head!=NULL){
        std::cout << head->val << "  ";
        head = head->next;
    }
    std::cout << " " << std::endl;
}

//往循环链表的头部插入数据
int insert(LinkList head ,int val){
    LinkList p_node = (LinkList)malloc(sizeof(Node));
    p_node->val = val;
    if(head->next == NULL){
        head->next = p_node;
        p_node->next = NULL;
    }
    else
    {
        p_node->next = head->next;
        head->next = p_node;
    }
    return 1;
}

LinkList fan(LinkList L){
    LinkList newlist = init();
    LinkList head    = L->next;
    LinkList newhead = newlist->next;
    if(head == nullptr){
        std::cout << "这是一个空链表" << std::endl;
        return nullptr;
    }
    else
    {
        while(head != nullptr){
            LinkList temp = head;
            head = head->next;
            if(newlist->next == nullptr){  
                newlist->next = temp;
                temp->next = nullptr;
            }
            else
            {
                temp->next = newlist->next;
                newlist->next = temp;
            }
            //head = head->next;   
        }
    }
    return newlist;
}


void local_reserve(LinkList L){
    LinkList head = L->next;
    LinkList start = nullptr;
    LinkList end   = nullptr;

    start = head;
    end   = head->next;

    if(head == nullptr){
        std::cout << "这是一个空链表" << std::endl;
        return ;
    }
    while(end!=nullptr){
        start->next = end->next;

        end->next = L->next;
        L->next   = end;

        end = start->next;
    }
}

int main(void){
    
    LinkList head = init();
    insert(head,50);
    insert(head,100);
    insert(head,200);
    insert(head,300);
    insert(head,400);
    insert(head,500);
    print(head);

    // LinkList newhead = fan(head);
    // print(newhead);

    local_reserve(head);
    print(head);
  
    return 0;
}