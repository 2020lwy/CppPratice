#include <iostream>

class Base{
 public:
    ~Base(){
        std::cout << "Base 的析构函数" << std::endl;
    }
};

class Son : public Base{
 public:
    ~Son(){
        std::cout << "Son 的析构函数" << std::endl;
    }
};

int main(void){
    Base *base = new Son();
    delete base;
    return 0;
}