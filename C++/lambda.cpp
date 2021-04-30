#include <iostream>
#include <functional>
#include <memory>
#include <string>

int func_test(int a ,int b){
    return a+b;
}

template<class T>
using Callbafunc = std::function<void (T a ,T b)>;

template<class MT>
class Base{
 public:
    Base(std::string _name,Callbafunc<MT>  func_){
        m_name_ = _name;
        cbfunc_ = func_;
        func__ = std::bind(&Base::func_test,this,std::placeholders::_1,std::placeholders::_2);
    }
    ~Base(){

    }
    int func_test(int a ,int b){
        return a+b;
    }
    void call(){
        this->cbfunc_(10,20);
        std::cout << this->func__(10,400)  << std::endl;
    }
    
    
 private:
    std::string m_name_;
    Callbafunc<MT> cbfunc_;
    std::function<int (int a,int b)> func__;
    // auto fff = [] {return 42;};
    // std::cout << "func() "  << fff() << std::endl;

};



int main(void){

    Base<int> base("hello",[](int a,int b){  std::cout << "hello I am lambda" << std::endl;});
    base.call();
    std::function<int(int a,int b)> aa = std::bind(&Base<int>::func_test,&base,std::placeholders::_1,std::placeholders::_2);
    std::cout << aa(100,200) << std::endl;

    int cc = 100;
    auto ff = [cc](int a ,int b) mutable ->int {cc=2000;return cc + a + b;};
    std::cout << "cc = "  << ff(90,100) << std::endl;
    return 0;
}