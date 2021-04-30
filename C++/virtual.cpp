#include <iostream>
#include <memory>

class Base{
 public:
    virtual void A(){
        std::cout << "Base" << std::endl;
    }
    virtual void B(){
        std::cout << "B "  << std::endl;
    }
};

class Device : public Base{
 public:
    virtual void A(){
        std::cout << "device" << std::endl;
    }
    virtual void B(){

    }
    virtual void C(){

    }
};

int main(void){

    Base base;
    Device dev;
    std::cout << "base的地址是: " << (int *)(&base) << std::endl;
    std::cout << "虚函数表的地址是：" << (int *)*((int *)&base) << std::endl;

    std::cout << "dev 的地址是： " << (int *)(&dev) << std::endl;
    std::cout << "dev的虚函数表的地址是: " << (int *)*((int *)&dev) << std::endl;

    //std::shared_ptr<Base> ptr = std::make_shared<Device> ();
    Base bb;
    Device dd;
    std::cout << "dd 虚函数表是:  " << (int *)*((int *)&dd) << std::endl;



    

    return 0;
}