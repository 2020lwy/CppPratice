#include <iostream>
#include <cstring>
#include <algorithm>
#include <memory>


class Transfer{
 public:
    Transfer(){

    }
    virtual ~Transfer(){

    }
    virtual int read()=0;
    virtual int write()=0;   
 
 public:
    using ptr = std::shared_ptr<Transfer>;//在抽象类中提供一个这样的智能指针类吧，姑且先这样理解

 private:
    
};

class TransferCan : public Transfer{//子类继承父类，并且在子类中实现各种虚函数
 public:
    TransferCan(){
    }
    virtual int read(){
        std::cout << "I am transfercan read" << std::endl;
    }
    virtual int write(){
        std::cout << "I am transfercan write" << std::endl;
    }
    ~TransferCan(){

    }
 public:

};

class TransferSpi : public Transfer{//子类继承父类，并且在子类中实现各种虚函数
 public:
    TransferSpi(){
    }
    virtual int read(){
        std::cout << "I am transferspi read" << std::endl;
    }
    virtual int write(){
        std::cout << "I am transferspi write" << std::endl;
    }
    ~TransferSpi(){

    }
 public:

};

class Use{//如果需要使用到上面的类的方法的时候，因为不同的继承类实现的方法不同
 public:
    Use(){
        transfer_ptr_ = std::make_shared<TransferSpi>();
    }
    ~Use(){

    }
 public:
    Transfer::ptr transfer_ptr_;
 private:

};

int main(void){
    Use use;
    use.transfer_ptr_->read();
    // std::shared_ptr<Transfer> ptr = std::make_shared<TransferCan>();
    // ptr->read();
    return 0;
}