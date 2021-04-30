#include <thread>
#include <iostream>

void hello(void){
    std::cout << "I am C++ 多线程" << std::endl;
    std::cout << "hello world" << std::endl;
}

int print(int a,int b){
    std::cout << a+b << std::endl;
    std::thread::id id  = std::this_thread::get_id();
    std::cout << "id " << id << std::endl;
}

class Test{
 public:
    Test(){

    }
    ~Test(){

    }
    int func_test(int a,int b){
        std::cout << "hello func_test" << std::endl;
        std::cout << a+b << std::endl;
        return a+b;
    }
 private:
  int m_data;
};


int main(void){
    //线程的资源回收一定要注意做，不管是等待子线程结束再往下走，还是直接分离子线程，都可以
    std::thread hh(hello);
    hh.join();

    std::thread ee([](){std::cout <<"hello guangzhou" << std::endl;});//创建线程的内部可以使用一个函数指针，
                                                                    //也可以使用一个lambda函数
    ee.detach();

    std::thread ll(print,20,800);
    ll.detach();

    Test test;
    std::thread oo(&Test::func_test,&test,900,1000);
    oo.join();
    unsigned long bb = std::thread::hardware_concurrency(); //说是返回的是一个程序中可以并发的线程的数量，但是在一个多核的CPU中，也有可能是返回的是CPU的核数
    std:: cout << "bb = " << bb  << std::endl;

    std::thread::id thread_id = std::this_thread::get_id();
    std::cout << "thread_id = " << thread_id << std::endl;
    return 0;
}