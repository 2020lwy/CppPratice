#include <iostream>

void print(int &a,int &b){
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    a = 1000;
    b = 120;
}
int main(void){
    
    int a = 100;
    int b = 200;
    print(a,b);
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    return 0;
}
