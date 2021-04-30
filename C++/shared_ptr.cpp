#include <iostream>
#include <memory>
#include <vector>

class Base{
 public:
    Base() = default;
    Base(const std::string & _name):name(_name){
        std::cout << name << std::endl;
    }
 private:
    std::string name;
};

class BodStr{

 public:
    BodStr() = default;
    BodStr(const std::string &str):data(std::make_shared<std::vector<std::string>>()),m_name(str){
        std::cout << "I am BodStr 构造函数" << std::endl;
    }
    void push_back(const std::string & str){
        data->push_back(str);
    }

    void print(){
        for(auto x = data->begin();x != data->end();x++){
            std::cout << " x = " << *x << std::endl;
        }
    }

 private:
    std::shared_ptr<std::vector<std::string>> data;
    std::string m_name;
};

void test(int *p){
    std::cout << "*p " << *p << std::endl;
}

int main(void){

    std::shared_ptr<Base> ptr = std::make_shared<Base>("hello world!");
    std::shared_ptr<Base> pts = std::make_shared<Base>();
    std::shared_ptr<Base> ppt = nullptr;
    ppt = ptr;

    std::cout << "count = " << ptr.use_count() << std::endl;

    // std::vector<int> vet1;
    // {
    //     std::vector<int> vet2 = {1,2,3,4};
    //     vet1 = vet2;
    // }
    // for(auto tt : vet1){
    //     std::cout << "vet1 = " << tt << std::endl;
    // }
    std::shared_ptr<BodStr> bodptr2 = std::make_shared<BodStr>("bod");
    //bodptr2->print();
    //std::cout << "start" << std::endl;
    {
        std::shared_ptr<BodStr> bodptr = std::make_shared<BodStr>("bod");
        bodptr->push_back("hello1");
        bodptr->push_back("hello2");
        bodptr->push_back("hello3");
        bodptr->push_back("hello4");
        bodptr->print();
        bodptr2 = bodptr;
    }
    //std::cout << "end" << std::endl;
    //bodptr2->print();

    std::shared_ptr<int> ppp = std::make_shared<int>(200);
    test(ppp.get());



    
    auto sp = std::make_shared<int>();
    auto p = sp.get();
    //delete p;

    return 0;
}