#include <iostream>

enum Level{
    level1 = 0,
    level2,level3,level4
};

int main(void){

    unsigned char ll = 9;

    switch (ll){

        case level1:
            std::cout << "level1" << std::endl;
            break;
        case level2:
            std::cout << "level2" << std::endl;
            break;
        case level3:
            std::cout << "level3" << std::endl;
            break;
        case level4:
            std::cout << "level4" << std::endl;
            break;
        default:
            std::cout << "error"  << std::endl;
            break;
    }

    return 0;
}