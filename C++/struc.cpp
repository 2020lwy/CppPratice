#include <iostream>
#include <string>

struct Test{

    char *ttt = (char *)"hello guangzhou";
    int a = 100;
    void print(){
        std::cout << "a = " << a << std::endl;
        std::cout << *ttt << std::endl;
    }
};

int main(void){
    std::string ptr;
    ptr = "hello";
    std::cout << ptr << std::endl;
    Test tt;
    tt.print();
    return 0;
}
