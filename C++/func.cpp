#include <iostream>
#include <functional>

int func(int a,int b){
    return a+b;
}

void func2(int a,int b){
    std::cout << "a+b " << a+b << std::endl;
}

int (*p)(int,int);

typedef int (*P)(int ,int);

typedef void (*H)(int,int);

class Test{
 public:
    Test(){
        test_func_ = std::bind(&Test::sig_handle,this,std::placeholders::_1);
        test_func_(10);

    }

    ~Test(){
        
    }

    void sig_handle(int a){
        std::cout << "I am sig_handle" << std::endl;
    }
 private:
    std::function<void(int)> test_func_;

};


int main(void){

    p = func;
    int c = (*p)(10,20);
    P p1;
    p1=func;
    int h = (*p1)(100,900);
    std::cout << "h " <<  h << std::endl;
    std::cout << "c " << c << std::endl;
    Test tt;
    H g;
    g=func2;
    (*g)(20,9);
    return 0;
}
