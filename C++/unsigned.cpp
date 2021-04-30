#include <iostream>

int main(void){

    unsigned a = 10;
    int b = -20;
    std::cout << "a+b = "  << a+b  << std::endl;

    int c = 10;
    int d = 010;
    std::cout << "c "  << c  << std::endl;
    std::cout << "d"    <<  d << std::endl;

    std::string book = "hello world!";
    std::cout << book << std::endl;


    int ss = 100;
    int &dd = ss;
    std::cout << "ss before "  << ss << std::endl;
    std::cout << "dd befoer "  << dd << std::endl;
    dd = 900;

    std::cout << "ss after "  << ss << std::endl;
    std::cout << "dd after "  << dd << std::endl;

    int hh = dd;
    std::cout << "hh "  << hh << std::endl;


    int ip = 20;
    int *p1 = &ip;
    *p1 = *p1 * *p1;
    std::cout << "*p1 "  << *p1 << std::endl;

    int *pp = ip;

    return 0;
}