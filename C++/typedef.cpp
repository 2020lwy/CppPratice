#include <iostream>

typedef struct A{
    int a;
    int b;
}A;
typedef A* B;

int main(void){
    A a;
    a.a=100;
    a.b=200;
    std::cout << a.a+a.b << std::endl;
    B b;
    b->a = 100;
    b->b = 500;
    std::cout << b->a+b->b << std::endl;
    return 0;
}