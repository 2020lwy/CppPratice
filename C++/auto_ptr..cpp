#include <iostream>
#include <string>
#include <memory>


int main(void){

    std::auto_ptr<std::string> pd  (new std::string("hello"));
    std::cout << "*pd "  << *pd  << std::endl;

    return 0;
}