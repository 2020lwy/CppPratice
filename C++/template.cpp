#include <iostream>
#include <memory>

template<class T>
T test(T t1,T t2){
    if(t1>t2){
        return t1;
    }else{
        return t2;
    }
}



template<class T1>
class B{
 public:
    B(T1 a):a_(a){

    }
    template<class T2>
    T2 test(T2 t2){
        return t2;
    }
    template<class T2>
    T1 get(T2 t2){
        return a_+(T1)t2;
    }

 private:
    T1 a_;
};

int main(void){

    std::shared_ptr<B<int>> ppb = std::make_shared<B<int>>(10);
    // std::string pp = ppb.test<std::string>(std::string s("hello"));
    // std::string ss="hello world";
    // int ss =100;
    // int pp = ppb->test<int>(ss);

    std::string ss = "hello world";
    std::string pp = ppb->test<std::string>(ss);
    std::cout << pp << std::endl;

    // int a=test<int>(20,40);
    // std::cout << "a=" << a <<  std::endl;

    // float b = test<float>(12.8,30.9);
    // std::cout << "b=" << b << std::endl;

    B<int> s(10);
    int a =s.get<int>(30);
    std::cout << "a " << a << std::endl;
    return 0;
}