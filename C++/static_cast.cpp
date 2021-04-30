#include <iostream>

int main(void){

    char c='a';
    int b = static_cast<int>(c);
    std::cout << b << std::endl;
    unsigned int d = 100;
    int f = -10;
    std::cout << "d " << d  << std::endl;
    std::cout << "f " << f  << std::endl;


    return 0;
}
