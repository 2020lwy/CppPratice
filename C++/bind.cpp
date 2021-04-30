#include <iostream>
#include <algorithm>
#include <functional>

int test(int a ,int b){
    return a+b;
}

int main(void){
    std::function<int(int ,int)> func = std::bind(&test,std::placeholders::_1,std::placeholders::_2);
    std::cout << "func(a,b) = " << func(10,20) << std::endl;
    //std::function<int(int,int)> func2 = std::bind(test,100,200);
    auto func2 = std::bind(test,100,200);
    std::cout << "func2 = "  << func2()  << std::endl;

    return 0;
}