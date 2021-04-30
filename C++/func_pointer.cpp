#include <iostream>

int (* func)(int a ,int b);

int test(int a ,int b){
    std::cout << "test  a "  << a <<std::endl;
    std::cout << " test b "  << b <<std::endl;
}

void ppp(int a ,int b,int test(int c,int d)){
    std::cout << " ppp a"  << a << std::endl;
    std::cout << " ppp  b "  << b << std::endl;
    test(a,b);
}

class Test{

 public:
    Test() = default;
    Test(int n_):n(n_){

    }

    // void print(){
    //     std::cout << "n "  << n  << std::endl;
    // }
    friend void print_(const Test &tt);
    friend class Myfriend;
    void print() const{
        std::cout << "n " << 2*n << std::endl;
    }

    void out() const{
        
        std::cout << "n " << 3*n  << std::endl;
    }

 private:
    int n ;
};

class Myfriend{

 public:
    void print(const Test &tt){
        std::cout << "I am class Myfriend " << std::endl;
        std::cout << " n = "  << tt.n << std::endl;
    }
 private:

};

void print_(const Test &tt ){
    std::cout << "hello world !"  << std::endl;
    std::cout << tt.n << std::endl;
}


class Static{
 public:
    Static() = default;
    Static(int a_):a(a_){

    }
    static int b;
    const static int c = 100;
    static void test(){
        std::cout << " b = "  << b << std::endl;
        std::cout << " c = "  << c << std::endl;
        //std::cout << " b = "  << a << std::endl;  //静态成员函数只能调用静态成员变量
        std::cout << "static test"  << std::endl;
    }
 private:
    int a ;
    

};

int Static::b = 0;

int main(void){

    // func = test;
    // // func(10,20);
    // ppp(100,2000,func);

    // const Test tt(20);
    // tt.print();

    // Test tt2(40);
    // tt2.print();

    // Test yy;
    // yy.out();

    // Test &tt3 = tt2;
    // print_(tt3);

    // Myfriend myfriend;
    // myfriend.print(tt3);

    Static test(100);
    Static::b = 300;
    std::getwchar();
    Static::test();
    return 0;
}