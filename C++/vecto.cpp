#include <iostream>
#include <algorithm>
#include <vector>
#include <memory>
#include <algorithm>
#include "./spdlog/spdlog.h"


void print(int v ){
    std::cout << v << std::endl;
}



class Person{
 public:
    Person(int age,int id):mid(id),mage(age){

    }
    ~Person(){

    }
    void show(){
        std::cout << this->mage << std::endl;
        std::cout << this->mid  << std::endl;
    }
 private:
    int mage;
    int mid;
};

void print_person(std::shared_ptr<Person> pp){
    pp->show();
}

int main(void){

    std::vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(40);
    v.push_back(40);
    for_each(v.begin(),v.end(),print);

    int count_ = std::count(v.begin(),v.end(),40);
    std::cout << "count_ = "  << count_ << std::endl;

    std::vector<std::shared_ptr<Person>> h;
    std::shared_ptr<Person> ps1 = std::make_shared<Person>(100,200);
    std::shared_ptr<Person> ps2 = std::make_shared<Person>(300,400);

    Person p1(100,200);
    Person p2(300,400);
    //std::cout << p1.mage << std::endl;//eror 这个位置自己要注意一下，这里是的mage是一个私有的成员变量，不能使用类对象直接访问，智能使用类的成员函数去访问这些私有的成员变量

    h.push_back(ps1);
    h.push_back(ps2);

    for_each(h.begin(),h.end(),print_person);

    std::vector<int>::iterator it;
    SPDLOG_INFO("xnet is ready");
    SPDLOG_WARN("Failed to set status for xnet start ");


    return 0;
}